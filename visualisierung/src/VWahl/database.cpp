#include "database.h"

Database::Database(QString name)
{
    dbcon_name = name;
    db = QSqlDatabase::addDatabase(type, name);
}

Database::~Database()
{
    close();
}

auto Database::connect() -> int
{
    db.setHostName(db_host);
    db.setDatabaseName(db_name);
    db.setUserName(db_user);
    db.setPassword(db_password);
    if (db.open()) {
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

auto Database::exec(QString queryString) -> QSqlQuery
{
    QSqlQuery query;
    query = db.exec(queryString);
    if (query.exec(queryString)) {
        //
    }
    return query;
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
