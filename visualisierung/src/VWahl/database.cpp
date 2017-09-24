#include "database.h"

#include <future>

//static variables
unsigned long Database::connectionCounter =0;
std::mutex Database::connectionCounterMutex;

//functions
Database::Database(const QString& ty, const QString& st, const int y) : type(ty), state(st), year(y)
{

    db = QSqlDatabase::addDatabase(VWahl::settings->value("database/databaseType").toString(),getConnectionName(type,state,year));

    Logger::log << L_INFO << "Adding connection " << db.connectionName() << " from type "
                <<  db.driverName() << "\n";
}

Database::Database(const Database &other)
{
    type = other.type;
    state = other.state;
    year = other.year;
    db = QSqlDatabase::cloneDatabase(other.db,getConnectionName(type,state,year));
    candidates = QList<Kandidat>(other.candidates);
    parties = QList<Partei>(other.parties);
    pollingStations = QList<PollingStation>(other.pollingStations);
}

Database::~Database()
{
    db.close();
    Logger::log << L_INFO << "closed Database" << db.connectionName()<< "\n";
}

//connects class-object to database
auto Database::connect() -> int
{
    if(initByDatabaseSettings() != EXIT_SUCCESS)
        return EXIT_FAILURE;

    if (db.open()) {
        Logger::log << L_INFO<< "successfull connected to database!"<< "\n";
        return EXIT_SUCCESS;
    }
    else {
        Logger::log << L_DEBUG << db.lastError().text().toStdString()<< "\n";
        return EXIT_FAILURE;
    }
}

auto Database::exec(const QString queryString) -> QSqlQuery
{
    QSqlQuery query;
    query = db.exec(queryString);
    query.exec(queryString);
    return query;
}

void Database::close()
{
    db.close();
}

int Database::getVotesSingleCandidate(QSqlDatabase db, Kandidat k, PollingStation station)
{
    db.open();
    QString queryString = VWahl::settings->value("querys/BestimmteStimmenDirektkandidatWahllokal").toString();
    QSqlQuery voteQuery = QSqlQuery(db);
    voteQuery.prepare(queryString);
    voteQuery.bindValue(":d",QVariant(k.getId()));
    voteQuery.bindValue(":w",QVariant(station.getId()));
    voteQuery.exec();
    if(! voteQuery.exec() || ! voteQuery.next())
        throw VWahlException("Failed to execute query " + voteQuery.executedQuery());
    int v = voteQuery.value("1Anzahl").toInt();
    db.close();
    return v;
}

unsigned long Database::getRawConnectionCounter()
{
    std::lock_guard<std::mutex> lock_guard(connectionCounterMutex);
    ++connectionCounter;
    return connectionCounter;
}

QString Database::getConnectionCounter()
{
    return QStringLiteral("%1").arg(getRawConnectionCounter());
}

int Database::getVotesCandidate(Kandidat k, QList<PollingStation> pollingStations)
{
    int votes = 0;

    try
    {
        QVector<std::shared_future<int>> threads;
        for(PollingStation p : pollingStations)
        {
            threads.push_back(std::async(std::launch::async,getVotesSingleCandidate,
                                         QSqlDatabase::cloneDatabase(db,getConnectionName(type,state,year))
                                         ,k,p));

        }
        for(int i = 0; i< threads.size(); ++i)
            votes += threads[i].get();

    }catch(VWahlException e)
    {
        Logger::log << "Error while receiving votes for candidate " << k.getDescription() << " " << e.what() << "\n";
        throw e;
    }

    return votes;
}

int Database::getVotesSingleParty(QSqlDatabase db, Partei party, PollingStation station)
{
    if(! db.open())
        throw VWahlException("Couldn't get votes for party " + party.getDescription() +
                             " in polling station " + station.getDescription());

    QString queryString = VWahl::settings->value("querys/BestimmteStimmenParteiWahllokal").toString();
    QSqlQuery voteQuery = QSqlQuery(db);
    voteQuery.prepare(queryString);
    voteQuery.bindValue(":d",QVariant(party.getP_id()));
    voteQuery.bindValue(":w",QVariant(station.getId()));
    voteQuery.exec();
    if(! voteQuery.exec() || !voteQuery.next())
    {
        Logger::log << L_ERROR << "Failed to execute query " << voteQuery.executedQuery() << " with error " << db.lastError().text() << "\n";
        throw VWahlException("Failed to execute query " + voteQuery.executedQuery() + " with error " + db.lastError().text());
     }
    int v = voteQuery.value("2Anzahl").toInt();
    db.close();
    return v;
}

int Database::getVotesParty(Partei party, QList<PollingStation> pollingStations)
{
    int votes = 0;
    if(party.getP_id() == getIGNORED_PARTY())
    {
        Logger::log << L_DEBUG << "Silently ignoring party " << party.getDescription() << "\n";
        return 0;
    }

    try
    {
        QVector<std::shared_future<int>> threads;
        for(PollingStation p : pollingStations)
        {
            threads.push_back(std::async(std::launch::async,getVotesSingleParty,
                                         QSqlDatabase::cloneDatabase(db,getConnectionName(type,state,year))
                                         ,party,p));

        }
        for(int i = 0; i< threads.size(); ++i)
            votes += threads[i].get();

    }catch(VWahlException e)
    {
        Logger::log << "Error while receiving votes for party " << party.getDescription() << " " << e.what() << "\n";
        throw e;
    }

    return votes;

}

Kandidat Database::getCandidate(int index)
{
    for(Kandidat k : candidates)
        if(k.getId() == index)
            return k;
    throw CandidateNotFoundException(QString("Couldn't find a candidate with id ") + index);
}

Partei Database::getParty(int index)
{
    for(Partei p : parties)
        if(p.getP_id() == index)
            return p;
    throw PartyNotFoundException(QString("Couldn't find a party with id ") + index);
}

PollingStation Database::getPollingStation(int index)
{
    for(PollingStation p : pollingStations)
        if(p.getId() == index)
            return p;
    throw PollingStationNotFoundException(QString("Couldn't find a polling station with id " + index));
}

int Database::getVote2Count(PollingStation& p, QSqlDatabase& db)
{
    db.open();
    QString queryString = VWahl::settings->value("querys/Anzahl2StimmenWahllokal").toString();
    QSqlQuery query(db);
    query.prepare(queryString);
    query.bindValue(":w",p.getId());
    if(!query.exec() || !query.next())
        throw VWahlException("Failed to receive all votes in polling station " + p.getDescription() + " with query " +
                             query.executedQuery() + " and error " + db.lastError().text());
    int count = query.value("count").toInt();
    db.close();
    return count;

}

int Database::getVote1Count(PollingStation p, QSqlDatabase db)
{
    db.open();
    QString queryString = VWahl::settings->value("querys/Anzahl1StimmenWahllokal").toString();
    QSqlQuery query(db);
    query.prepare(queryString);
    query.bindValue(":w",p.getId());
    if(!query.exec() || !query.next())
        throw VWahlException("Failed to receive all votes in polling station " + p.getDescription() + " with query " +
                             query.executedQuery() + " and error " + db.lastError().text());
    int count = query.value("count").toInt();
    db.close();
    return count;

}

int Database::getVotes1Count(QList<PollingStation> ps)
{
    try
    {
        int vc = 0;
        std::vector<std::shared_future<int>> threads;
        for(int i = 0; i < ps.size(); ++i)
        {
            PollingStation p = ps[i];
            threads.push_back(std::async(std::launch::async, getVote1Count,p,
                                         QSqlDatabase::cloneDatabase(db,getConnectionName(type,state,year))));

        }
        for(int i = 0; i < threads.size(); ++i)
            vc += threads[i].get();
        return vc;
    }catch(VWahlException e)
    {
        throw e;
    }
}

int Database::getVotes2Count(QList<PollingStation> ps)
{
    try
    {
        QVector<std::shared_future<int>> threads;
        int votes = 0;
        for(PollingStation p : ps)
        {
            threads.push_back(std::async(std::launch::async,getVote1Count,p,
                                         QSqlDatabase::cloneDatabase(db,getConnectionName(type,state,year))));
        }
        for(int i = 0; i< threads.size(); ++i)
            votes += threads[i].get();
        return votes;
    }catch(VWahlException e)
    {
        throw e;
    }
}

Kandidat Database::getCandidateForParty(Partei p)
{
    if(p.getP_id() == getIGNORED_PARTY())
        throw CandidateNotFoundException("Party " + p.getDescription() + " will be silently ignored.");

    QString queryString = VWahl::settings->value("querys/BestimmterKandidatUndPartei").toString();
    QSqlQuery query(db);
    query.prepare(queryString);
    query.bindValue(":pk",QVariant(p.getP_id()));
    if(!query.exec() || !query.next())
        throw VWahlException("Failed to receive Candidate for party " + p.getDescription() +
                             " with query " + query.executedQuery() + " and error " + lastError().text());
    int d_id = query.value("D_ID").toInt();
    try
    {
        return getCandidate(d_id);
    }catch(CandidateNotFoundException e)
    {
        throw e;
    }
}

Partei Database::getPartyForCandidate(Kandidat k)
{
    QString queryString = VWahl::settings->value("querys/BestimmteParteiUndKandidat").toString();
    QSqlQuery query(db);
    query.prepare(queryString);
    query.bindValue(":k",QVariant(k.getId()));
    if(!query.exec() || !query.next())
        throw VWahlException("Failed to receive Party for candidate " + k.getDescription() +
                             " with query " + query.executedQuery() + " and error " + lastError().text());
    int p_id = query.value("P_ID").toInt();

    if(getIGNORED_PARTY() == p_id)
        throw CandidateNotFoundException(QString("Silently ignoring party with id ") + getIGNORED_PARTY());
    try
    {
        return getParty(p_id);
    }catch(PartyNotFoundException e)
    {
        throw e;
    }
}

QString Database::getNamingScheme(QString type, QString state, int year)
{
    return "_" + VWahl::settings->value("database/databasePrefix").toString() + "_" + type.toUpper() + "_" + state.toUpper() + "_" + QStringLiteral("%1").arg(year);
}

QString Database::getConnectionName(QString type, QString state, int year)
{
    return getNamingScheme(type,state,year) + "_" + getConnectionCounter();
}

int Database::reloadSettings()
{
    db.close();
    initByDatabaseSettings();
    if(connect() == EXIT_FAILURE){
        Logger::log << L_ERROR << db.lastError().text().toStdString()<< "\n";
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;

}

int Database::initByDatabaseSettings()
{
    //Make sure database is closed
    if(db.isOpen())
        db.close();

    IGNORED_PARTY = VWahl::settings->value("database/ignoredParty").toInt();

    QString hostname = VWahl::settings->value("database/hostname").toString();
    QString user = VWahl::settings->value("database/user").toString();
    QString password = VWahl::settings->value("database/password").toString();
    QString databaseName = getNamingScheme(type,state,year);

    Logger::log << L_INFO << "Connecting " << db.connectionName() << " to database " << databaseName << " on host " << hostname << " with user " << user << " and password " << password << "\n";
    Logger::log << L_INFO << "Ignoring parties with id " << IGNORED_PARTY << "\n";

    db.setDatabaseName(databaseName);
    db.setHostName(hostname);
    db.setUserName(user);
    db.setPassword(password);

    return EXIT_SUCCESS;
}


QList<Partei> Database::getParties() const
{
    return parties;
}

int Database::getIGNORED_PARTY() const
{
    return IGNORED_PARTY;
}

void Database::updateData()
{
    //candidates
    Logger::log << L_INFO << "Refreshing cache for candidates...\n";
    candidates.clear();
    QString candidateQueryString = VWahl::settings->value("querys/KandidatListe").toString();
    QSqlQuery candidatesQuery = QSqlQuery(candidateQueryString,db);
    if(! candidatesQuery.exec())
    {
        Logger::log << L_ERROR << "Failed to execute the query " << candidatesQuery.executedQuery().toStdString()<< "\n";
        return;
    }
    while(candidatesQuery.next())
    {
        int id = candidatesQuery.value("D_ID").toInt();
        QString lname = candidatesQuery.value("Name").toString();
        QString name = candidatesQuery.value("Vorname").toString();
        QColor col = candidatesQuery.value("Farbe").value<QColor>();
        Kandidat k = Kandidat(id,lname,name,col);
        candidates.push_back(k);
    }

    //parties
    Logger::log << L_INFO << "Refreshing cache for parties...\n";
    parties.clear();
    QSqlQuery partiesQuery = QSqlQuery(VWahl::settings->value("querys/ParteiListe").toString(),db);
    partiesQuery.exec();
    if(! partiesQuery.exec())
    {
        Logger::log << L_ERROR << "Failed to execute the query " << partiesQuery.executedQuery().toStdString() << "\n";
        Logger::log << L_ERROR << "The parties cache couldn't be refreshed.\n";
        return;
    }
    while(partiesQuery.next())
    {
        QString desc = partiesQuery.value("P_Bezeichnung").toString();
        int id = partiesQuery.value("P_ID").toInt();
        int listPlaces = partiesQuery.value("Listenplaetze").toInt();
        QColor colour = partiesQuery.value("Farbe").value<QColor>();
        parties.push_back(Partei(id,listPlaces,desc,colour));
    }


    //polling stations
    Logger::log << L_INFO << "Refreshing cache for polling stations...\n";
    pollingStations.clear();
    QSqlQuery pollingStationsQuery = QSqlQuery(VWahl::settings->value("querys/WahllokalListe").toString(),db);
    pollingStationsQuery.exec();
    if(! pollingStationsQuery.exec())
    {
        Logger::log << L_ERROR << "Failed to execute the query " << pollingStationsQuery.executedQuery().toStdString() << "\n";
        Logger::log << L_ERROR << "The polling station cache couldn't be refreshed.\n";
        return;
    }
    while(pollingStationsQuery.next())
    {
        QString desc = pollingStationsQuery.value("W_Bezeichnung").toString();
        int id = pollingStationsQuery.value("W_ID").toInt();
        QString pc = pollingStationsQuery.value("PLZ").toString();
        QString street = pollingStationsQuery.value("Straße").toString();

        PollingStation ps = PollingStation(desc,id,pc,street);
        pollingStations.push_back(ps);
    }

    Logger::log << L_INFO << "All caches have been refreshed successfully.\n";
}

QList<PollingStation> Database::getPollingStations() const
{
    return pollingStations;
}

QList<Kandidat> Database::getCandidates() const
{
    return candidates;
}

auto Database::isOpen() -> bool
{
    return db.isOpen();
}

auto Database::lastError() -> QSqlError
{
    return db.lastError();
}

auto Database::hostName() -> QString
{
    return db.hostName();
}

auto Database::userName() -> QString
{
    return db.userName();
}

auto Database::password() -> QString
{
    return db.password();
}

auto Database::databaseName() -> QString
{
    return db.databaseName();
}

auto Database::driverName() -> QString
{
    return db.driverName();
}
