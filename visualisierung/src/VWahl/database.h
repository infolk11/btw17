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
#include "kandidat.h"
#include "partei.h"
#include "pollingstation.h"


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

    Database(const QString& ty, const QString& st, const int y);
    Database() = default;
    ~Database();
    auto connect() -> int;
    auto exec(const QString queryString) -> QSqlQuery;

    /**
     * @warning actually not working!QString
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
    QList<Record> getElectionResults(QString desc, int y, Options options, QList<int> candidates = QList<int>{}, QList<int> parties = QList<int>{}, QList<int> pollingStations = QList<int>{});
    Record getVoterTurnout(QString desc, int y, QList<QString> pollingStations);

    //Static functions
    static auto checkDatabaseSettings() -> int;
    static auto buildUpAvailableDatabases() -> void;
    static auto closeAllDatabases() -> void;
    static auto getNamingScheme(QString type, QString state, int year) -> QString;

    auto reloadSettings() -> int;
    auto initByDatabaseSettings() -> int;
    auto isOpen() -> bool;
    auto lastError() -> QSqlError;
    auto hostName() -> QString;
    auto userName() -> QString;
    auto password() -> QString;
    auto databaseName() -> QString;
    auto driverName() -> QString;

    QList<Kandidat> getCandidates() const;
    QList<PollingStation> getPollingStations() const;
    QList<Partei> getParties() const;
    void updateData();

private:
    //auto getSize(QSqlQuery &quey) -> int;


    QSqlDatabase db;
    QString type;
    QString state;
    int year;

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

    /*
     * One database typically represents one election, so we will use the database as a container for the values
     */
     QList<Kandidat> candidates;
     QList<PollingStation> pollingStations;
     QList<Partei> parties;

};

Q_DECLARE_OPERATORS_FOR_FLAGS(Database::Options)

#endif // DATABASE_H
