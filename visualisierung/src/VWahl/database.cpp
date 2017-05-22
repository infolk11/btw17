#include "database.h"

Database::Database(QString name)
{
    dbcon_name = name;
    db = QSqlDatabase::addDatabase(type, name);
    db.setDatabaseName(name);
}

Database::~Database()
{
    close();
}

//connects class-object to database
auto Database::connect() -> int
{
    Database::writeDBSettings();
    db.setHostName(db_host);
    db.setDatabaseName(db_name);
    db.setUserName(db_user);
    db.setPassword(db_password);
    if (db.open(db_user, db_password)) {
        Logger::log << L_INFO<< "successfull connected to database!";
        connected = true;
        return EXIT_SUCCESS;
    }
    else {
        //Konvertiert QSqlError zu QString und dann zu Std::String.
        Logger::log << L_ERROR << db.lastError().text().toStdString();
        connected = false;
        return EXIT_FAILURE;
    }
}

auto Database::writeDBSettings() -> void
{
    db.setHostName(VWahl::settings->value("hostname").toString());
    db.setDatabaseName(VWahl::settings->value("name").toString());
    db.setUserName(VWahl::settings->value("user").toString());
    db.setPassword(VWahl::settings->value("password").toString());

}

auto Database::exec(QString queryString, int column) -> QVariant
{
    QSqlQuery query;
    query = db.exec(queryString);
    if (query.exec(queryString)) {
        return query.value(column);
    }

    else{
        Logger::log << L_INFO << db.lastError().text().toStdString();
        //return may be done better
        return 0;
    }
}

//returns a recordobject related to given sql commands
RecordObject Database::getRecordObject(QString getDescription, int descriptionColumn, QString getVotes, int votesColumn, QString getColor, int colorColumn)
{
    //columns are related to index in the current query record
    return RecordObject(exec(getDescription, descriptionColumn).toString(), exec(getVotes, votesColumn).toInt(), exec(getColor, colorColumn).value<QColor>());
}

auto Database::close() -> void
{
    db.close();
    connected = false;
    Logger::log << L_INFO << "connection closed!";
}

auto Database::getData(QString wahl) -> Record
{
    //Content will be delivered by other group.
    return Record();
}

int Database::initDatabaseSettings()
{
    if(!doBasicSettingsExist())
        return writeBasicDatabaseSettings("localhost","wahl17","vwahl","pass");
    return EXIT_SUCCESS;
}

//get methods
auto Database::getDbType() -> QString
{
    return type;
}

auto Database::getDbHost() -> QString
{
    return db_host;
}

auto Database::getDbName() -> QString
{
    return db_name;
}

auto Database::getDbUser() -> QString
{
    return db_user;
}

auto Database::isConnected() -> bool
{
    return connected;
}

//set methods
auto Database::setDbType(QString x) -> void
{
    type = x;
}

auto Database::setDbHost(QString x) -> void
{
    db_host = x;
}

auto Database::setDbName(QString x) -> void
{
    db_name = x;
}

auto Database::setDbUser(QString x) -> void
{
    db_user = x;
}

auto Database::setDbPassword(QString x) -> void
{
    db_password = x;
}


int Database::writeBasicDatabaseSettings(QString h, QString n, QString u, QString p)
{

    //set basic values for the database connection in database-group
    VWahl::settings->beginGroup("database");
    VWahl::settings->setValue("hostname", h);
    VWahl::settings->setValue("name", n);
    VWahl::settings->setValue("user", u);
    VWahl::settings->setValue("password", p);
    VWahl::settings->endGroup();

    //settings for sql commands
    VWahl::settings->beginGroup("sql");
    VWahl::settings->setValue("partei", "SELECT ... FROM ...");
    VWahl::settings->setValue("kandidat", "SELECT ... FROM ...");
    VWahl::settings->endGroup();

    VWahl::settings->sync();
    if (VWahl::settings->status() != 0){
        Logger::log << L_ERROR << "failed to write settings to" << VWahl::settings->fileName().toStdString();
        return EXIT_FAILURE;
    }
    else
        Logger::log << L_INFO << "wrote the basic settings to" << VWahl::settings->fileName().toStdString();
    return EXIT_SUCCESS;
}

bool Database::doBasicSettingsExist()
{
    VWahl::settings->beginGroup("database");

    return (VWahl::settings->contains("hostname") &
            VWahl::settings->contains("name") &
            VWahl::settings->contains("user") &
            VWahl::settings->contains("databasepassword"));

}

auto Database::status() -> QString
{
    db.lastError().text();
}
