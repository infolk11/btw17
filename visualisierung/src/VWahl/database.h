#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>
#include <QtSql/QtSql>
#include <QtSql/QSqlDatabase>
//#include <QtSql/QSqlQueryModel>
#include <QtSql/QSqlError>
#include <QString>
#include <QColor>
#include <QList>
#include <iostream>

#include "logger.h"
#include "record.h"
#include "main.h"

class Database
{
public:
    Database(QString name);
    ~Database();
    Database() = default;
    auto connect() -> int;
    auto close() -> void;
    auto exec(QString queryString, int column) -> QVariant;
    auto writeDBSettings() -> void;
    auto status() -> QString;

    //get a single recordObject
    RecordObject getRecordObject(QString getDescription, int descriptionColumn, QString getVotes, int votesColumn, QString getColor, int colorColumn);

    /**
     * Reads the dates for a record out of the database.
     * Criterias for the dates are: Type and year of election, the radius and the participants like candidates or parties.
     *
     * @brief getData
     * @param wahl
     * @return
     */
    static auto getData(QString wahl ) -> Record;

    static auto initDatabaseSettings() -> int;

    //get functions
    auto getDbType() -> QString;
    auto getDbHost() -> QString;
    auto getDbName() -> QString;
    auto getDbUser() -> QString;
    auto isConnected() -> bool;

    //set functions
    auto setDbType(QString x) -> void;
    auto setDbHost(QString x) -> void;
    auto setDbName(QString x) -> void;
    auto setDbUser(QString x) -> void;
    auto setDbPassword(QString x) -> void;

private:
    //auto getSize(QSqlQuery &quey) -> int;

    /**
     * will be deleted laterwards. Just here to ease programming
     *
     * @brief writeBasicDatabaseSettings
     * @param h
     * @param n
     * @param u
     * @param p
     * @return
     */
    static auto writeBasicDatabaseSettings(QString h, QString n, QString u, QString p) -> int;
    static auto doBasicSettingsExist() -> bool;

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
