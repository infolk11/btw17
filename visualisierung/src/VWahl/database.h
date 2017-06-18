#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>
#include <QtSql/QtSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QString>
#include <QColor>
#include <QList>

#include "logger.h"
#include "record.h"
#include "main.h"

class Database
{
public:
    Database(const QString name);
    Database() = default;
    ~Database();
    auto connect() -> int;
    auto exec(const QString queryString) -> QSqlQuery;

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
    static auto checkDatabaseSettings() -> int;
    auto reloadSettings() -> int;
    auto initByDatabaseSettings() -> int;
    auto isOpen() -> bool;
    auto lastError() -> QSqlError;
    auto hostName() -> QString;
    auto userName() -> QString;
    auto password() -> QString;
    auto databaseName() -> QString;
    auto driverName() -> QString;
private:
    //auto getSize(QSqlQuery &quey) -> int;


    QSqlDatabase db;
    QSqlQuery query;
    QSqlRecord rec;
    QString db_name;

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
    static auto writeBasicDatabaseSettings(QString h = "localhost", QString n = "wahl17", QString u = "vwahl", QString p = "pass", QString t = "QMYSQL") -> int;
    static auto doBasicSettingsExist() -> bool;


};

#endif // DATABASE_H
