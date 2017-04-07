#include "database.h"

Database::Database(QString name)
{
    dbcon_name = name;
    db = QSqlDatabase::addDatabase(type, name);
}

auto Database::connect() -> bool
{
    db.setHostName(db_host);
    db.setDatabaseName(db_name);
    db.setUserName(db_user);
    db.setPassword(db_password);
    if (db.open())
        return true;
    else
        //std::cout << db.lastError() << std::endl;
        return false;
}

auto Database::exec(QString &queryString) -> QSqlQuery
{
    QSqlQuery query;
    query = db.exec(queryString);
    return query;
}

auto Database::close() -> void
{
    db.close();
    //connected = false;
}
