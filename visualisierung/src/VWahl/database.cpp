#include "database.h"
#include "kandidat.h"
#include "partei.h"

Database::Database(const QString& ty, const QString& st, const int y) : type(ty), state(st), year(y)
{

    db = QSqlDatabase::addDatabase(VWahl::settings->value("database/type").toString(),getNamingScheme(type,state,year));

    Logger::log << L_INFO << "Adding database " << getNamingScheme(type,state,year).toStdString() << " from type " << VWahl::settings->value("database/type").toString().toStdString();
}

Database::~Database()
{
    db.close();
    Logger::log << L_INFO << "closed Database" << databaseName().toStdString();
}

//connects class-object to database
auto Database::connect() -> int
{
    initByDatabaseSettings();
    if (db.open()) {
        Logger::log << L_INFO<< "successfull connected to database!";
        return EXIT_SUCCESS;
    }
    else {
        Logger::log << L_DEBUG << db.lastError().text().toStdString();
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

int Database::getVotesCandidate(Kandidat k, QList<PollingStation> pollingStations)
{
    int votes = 0;
    for(PollingStation p : pollingStations)
    {
        QSqlQuery voteQuery = QSqlQuery(VWahl::settings->value("BestimmteStimmenDirektkandidatWahllokal").toString(),db);
        voteQuery.bindValue("@d",QVariant(k.getId()));
        voteQuery.bindValue("@w",QVariant(p.getId()));
        voteQuery.exec();
        if(! voteQuery.exec())
        {
            Logger::log << L_ERROR << "Failed to execute the query " << voteQuery.executedQuery() << "\n";
            return 0;
        }
        int v = voteQuery.value("1Anzahl").toInt();
        votes += v;
    }

    return votes;
}

int Database::getVotesParty(Partei party, QList<PollingStation> pollingStations)
{
    int votes = 0;
    for(PollingStation p : pollingStations)
    {
        QSqlQuery voteQuery = QSqlQuery(VWahl::settings->value("BestimmteStimmenParteiWahllokal").toString(),db);
        voteQuery.bindValue("@d",QVariant(party.getP_id()));
        voteQuery.bindValue("@w",QVariant(p.getId()));
        voteQuery.exec();
        if(! voteQuery.exec())
        {
            Logger::log << L_ERROR << "Failed to execute the query " << voteQuery.executedQuery() << "\n";
            return 0;
        }
        int v = voteQuery.value("1Anzahl").toInt();
        votes += v;
    }

    return votes;
}
int Database::checkDatabaseSettings()
{
    bool returnV = false;
    if(!doBasicSettingsExist())
        returnV = writeBasicDatabaseSettings();
    else
        returnV = EXIT_SUCCESS;

    if(returnV == EXIT_SUCCESS)
        buildUpAvailableDatabases();

    return returnV;
}

void Database::buildUpAvailableDatabases()
{
    QSqlDatabase db = QSqlDatabase::addDatabase(VWahl::settings->value("database/type").toString());
    db.setHostName(VWahl::settings->value("database/hostname").toString());
    db.setUserName(VWahl::settings->value("database/user").toString());
    db.setPassword(VWahl::settings->value("database/password").toString());
    bool ok = db.open();
    if(ok)
    {
        Logger::log << L_INFO << "Successfully build up default database connection";
        QSqlQuery query = QSqlQuery("show databases",db);
        query.exec();
        while(query.next())
        {
            Logger::log << L_INFO << "Available database: " << query.value(0).toString().toStdString();
        }
    }
    else
        Logger::log << L_ERROR << "Failed to build up default database connection: " << db.lastError().databaseText().toStdString();
}

QString Database::getNamingScheme(QString type, QString state, int year)
{
    return VWahl::settings->value("database/databasePrefix").toString() + "_" + type.toUpper() + "_" + state.toUpper() + "_" + year;
}

int Database::reloadSettings()
{
    db.close();
    initByDatabaseSettings();
    if(connect() == EXIT_FAILURE){
        Logger::log << L_ERROR << db.lastError().text().toStdString();
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;

}

int Database::initByDatabaseSettings()
{
    db.close();

    checkDatabaseSettings();

    db.setDatabaseName(getNamingScheme(type,state,year));
    db.setHostName(VWahl::settings->value("database/hostname").toString());
    db.setUserName(VWahl::settings->value("database/user").toString());
    db.setPassword(VWahl::settings->value("database/password").toString());

    return EXIT_SUCCESS;
}



auto Database::writeBasicDatabaseSettings(QString h/* = "localhost"*/, QString n/* = "wahl17"*/, QString u/* = "vwahl"*/, QString p/* = "pass"*/, QString t/* = "QMYSQL"*/) -> int
{

    //set basic values for the database connection in database-group
    VWahl::settings->beginGroup("database");
    VWahl::settings->setValue("hostname", h);
    VWahl::settings->setValue("name", n);
    VWahl::settings->setValue("user", u);
    VWahl::settings->setValue("password", p);
    VWahl::settings->setValue("type", t);
    VWahl::settings->endGroup();

    //    //settings for sql commands
    //    VWahl::settings->beginGroup("sql");
    //    VWahl::settings->setValue("partei", "SELECT ... FROM ...");
    //    VWahl::settings->setValue("kandidat", "SELECT ... FROM ...");
    //    VWahl::settings->endGroup();

    return EXIT_SUCCESS;
}

auto Database::doBasicSettingsExist() -> bool
{
    return (VWahl::settings->contains("database/hostname") &&
            VWahl::settings->contains("database/name") &&
            VWahl::settings->contains("database/user") &&
            VWahl::settings->contains("database/password") &&
            VWahl::settings->contains("database/type"));

}

QList<Partei> Database::getParties() const
{
    return parties;
}

void Database::updateData()
{
    //candidates
    candidates.clear();
    QSqlQuery candidatesQuery = QSqlQuery(VWahl::settings->value("querys/KandidatListe").toString(),db);
    if(! candidatesQuery.exec())
    {
        Logger::log << L_ERROR << "Failed to execute the query " << candidatesQuery.executedQuery().toStdString();
        return;
    }
    while(candidatesQuery.next())
    {
        int id = candidatesQuery.value("D_ID").toInt();
        QString lname = candidatesQuery.value("Name").toString();
        QString name = candidatesQuery.value("Vorname").toString();
        QColor col = candidatesQuery.value("/*ausstehend*/").value<QColor>();
        Kandidat k = Kandidat(id,lname,name,col);
        candidates.push_back(k);
    }

    //parties
    parties.clear();
    QSqlQuery partiesQuery = QSqlQuery(VWahl::settings->value("querys/ParteiListe").toString(),db);
    partiesQuery.exec();
    if(! partiesQuery.exec())
    {
        Logger::log << L_ERROR << "Failed to execute the query " << partiesQuery.executedQuery().toStdString();
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
    pollingStations.clear();
    QSqlQuery pollingStationsQuery = QSqlQuery(VWahl::settings->value("querys/WahllokalListe").toString(),db);
    pollingStationsQuery.exec();
    if(! pollingStationsQuery.exec())
    {
        Logger::log << L_ERROR << "Failed to execute the query " << pollingStationsQuery.executedQuery().toStdString();
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
