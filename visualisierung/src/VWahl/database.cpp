#include "database.h"
#include "kandidat.h"
#include "partei.h"
#include "logger.h"

Database::Database(const QString name)
{
    rec = query.record();
    db_name = name;
    db = QSqlDatabase::addDatabase(VWahl::settings->value("database/type").toString());
    VWahl::dbs->append(*this);

    Logger::log() << L_DEBUG << "Adding database " << name.toStdString() << " from type " << VWahl::settings->value("database/type").toString().toStdString();
}

Database::~Database()
{
    db.close();
    Logger::log() << L_INFO << "closed Database" << db_name.toStdString();
}

//connects class-object to database
auto Database::connect() -> int
{
    initByDatabaseSettings();
    if (db.open()) {
        Logger::log() << L_INFO<< "successfull connected to database!";
        return EXIT_SUCCESS;
    }
    else {
        Logger::log() << L_DEBUG << db.lastError().text().toStdString();
        return EXIT_FAILURE;
    }
}

auto Database::exec(const QString queryString) -> QSqlQuery
{
    query = db.exec(queryString);
    query.exec(queryString);
    return query;
}

//returns a recordobject related to given sql commands
RecordObject Database::getRecordObject(QString getDescription, int descriptionColumn, QString getVotes, int votesColumn, QString getColor, int colorColumn)
{
    //columns are related to index in the current query record
    return RecordObject(exec(getDescription).value(descriptionColumn).toString(), exec(getVotes).value(votesColumn).toInt(), exec(getColor).value(colorColumn).value<QColor>());
}

/**
 * @warning actually not working!
 *
 * @brief Database::getElectionResults
 * @param desc
 * @param y
 * @param options
 * @param candidates
 * @param parties
 * @param pollingStations
 * @return
 */
QList<Record> Database::getElectionResults(QString desc, int y, Database::Options options, QList<int> candidates, QList<int> parties, QList<int> pollingStations)
{
    QList<Record> records;
    if(options.testFlag(Option::Candidates))
    {

        Record rec;
        QList<RecordObject> objects;
        for(int candidate: candidates)
        {
            Kandidat k;
            QSqlQuery candidateInfos = QSqlQuery(VWahl::settings->value("/*Abfrage ausstehend*/").toString(),db);
            candidateInfos.bindValue("/*ausstehend*/",QVariant(candidate));
            candidateInfos.exec();

            //Initialisieren mit Ergebnissen der Querys - ausstehend

            //Errechnen der Stimmen
            int votes = 0;
            for(int pollingStation : pollingStations)
            {
                QSqlQuery voteQuery = QSqlQuery(VWahl::settings->value("/*Abfrage ausstehend*/").toString(),db);
                voteQuery.bindValue("/*ausstehend*/",QVariant(pollingStation));
                query.exec();

                //Addieren der Votes - ausstehend

            }
            objects.push_back(k);
        }
        rec = Record(desc + " Direktkanidaten",y,objects);
        records.push_back(rec);
    }
    if(options.testFlag(Option::Parties))
    {
        Record rec;
        QList<RecordObject> objects;

        for(int party : parties)
        {
            Partei p;
            QSqlQuery partyInfos(VWahl::settings->value("/*Abfrage ausstehend*/").toString(),db);
            partyInfos.bindValue("/*ausstehend*/",QVariant(party));

            //Mit Daten anreichern - ausstehend
            int votes = 0;
            for(int pollingStation : pollingStations)
            {
                QSqlQuery voteQuery(VWahl::settings->value("/*Abfrage ausstehend*/").toString(),db);
                voteQuery.bindValue("/*ausstehend*/",pollingStation);

                //Errechnen der Votes - ausstehend
            }
            objects.push_back(p);
        }
        rec = Record(desc + " Parteien",y,objects);
        records.push_back(rec);
    }
    return records;
}

Record Database::getVoterTurnout(QString desc, int y, QList<QString> pollingStations)
{
    Record rec;
    //actually not supported
    return rec;
}

int Database::checkDatabaseSettings()
{
    if(!doBasicSettingsExist())
        return writeBasicDatabaseSettings();
    else
        return EXIT_SUCCESS;
}

int Database::reloadSettings()
{
    db.close();
    initByDatabaseSettings();
    if(connect() == EXIT_FAILURE){
        //to do Logger::log << L_ERROR << db.lastError().text().toStdString();
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;

}

int Database::initByDatabaseSettings()
{
    db.close();

    checkDatabaseSettings();

    db.setDatabaseName(db_name);
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
