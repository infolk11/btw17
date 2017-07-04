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

    enum Option
    {
        VoterTurnout = 0x0,
        ElectionResults = 0x1,
        Parties = 0x2,
        Candidates = 0x3
    };
    Q_DECLARE_FLAGS(Options,Option)

    Database(const QString name);
    Database() = default;
    ~Database();
    auto connect() -> int;
    auto exec(const QString queryString) -> QSqlQuery;

    //get a single recordObject
    RecordObject getRecordObject(QString getDescription, int descriptionColumn, QString getVotes, int votesColumn, QString getColor, int colorColumn);

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
    QList<Record>& getElectionResults(QString desc, int y, Options options, QList<int> candidates = QList<QString>{}, QList<int> parties = QList<QString>{}, QList<int> pollingStations = QList<QString>{});
    Record& getVoterTurnout(QString desc, int y, QList<QString> pollingStations);
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

Q_DECLARE_OPERATORS_FOR_FLAGS(Database::Options)

#endif // DATABASE_H
