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
    connected = true;
    return db.open()
}
