#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>
#include <QtSql/QtSql>
#include <QtSql/QSqlDatabase>
//#include <QtSql/QSqlQueryModel>
#include <QtSql/QSqlError>
#include <QString>
#include <iostream>

#include "logger.h"
#include "record.h"

class Database
{
public:
    Database(QString name);
    Database() = default;
    auto connect() -> int;
    auto close() -> void;
    auto exec(QString queryString) -> QSqlQuery;
    auto getData(QString wahl ) -> Record;

    //get functions
    auto getDbType() -> QString;
    auto getDbHost() -> QString;
    auto getDbName() -> QString;
    auto getDbUser() -> QString;

    //set functions
    auto setDbType(QString x) -> void;
    auto setDbHost(QString x) -> void;
    auto setDbName(QString x) -> void;
    auto setDbUser(QString x) -> void;
    auto setDbPassword(QString x) -> void;

private:
    //auto getSize(QSqlQuery &quey) -> int;


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
