#include "database.h"

Database::Database(QString name)
{
    dbcon_name = name;
    db = QSqlDatabase::addDatabase(type, name);
}

auto Database::connect() -> int
{
    db.setHostName(db_host);
    db.setDatabaseName(db_name);
    db.setUserName(db_user);
    db.setPassword(db_password);
    if (db.open()) {
        //Logger::log << L_INFO << "successfull connected to database!";
        qInfo() << "successfull connected to database!";
        connected = true;
        return EXIT_SUCCESS;
    }
    else {
        qInfo() << db.lastError();
        //Logger::log << L_INFO << db.lastError();
        qInfo() << db.lastError();
        connected = false;
        return EXIT_FAILURE;
    }
}

auto Database::exec(QString &queryString) -> QSqlQuery
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
    qInfo() << "connection closed!";
}
