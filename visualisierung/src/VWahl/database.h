#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>
#include <QtSql/QtSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QString>
#include <iostream>

#include "logger.h"

class Database
{
public:
    Database(QString name);
    Database() = default;
    auto connect() -> int;
    auto close() -> void;

private:
    auto getSize(QSqlQuery &quey) -> int;
    auto exec(QString &) -> QSqlQuery;

    QString type = "QMYSQL";
    QString db_host;
    QString db_name;
    QString db_user;
    QString db_password;

    QSqlDatabase db;
    QString dbcon_name;
    bool connected = false;
};

#endif // DATABASE_H
