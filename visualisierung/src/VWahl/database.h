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


#include "vwahlexception.h"
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
    void close();

    int getVotesCandidate(Kandidat k, QList<PollingStation> pollingStations);
    int getVotesParty(Partei party, QList<PollingStation> pollingStations);
    Kandidat getCandidate(int index);
    Partei getParty(int index);
    PollingStation getPollingStation(int index);
    static int getVote2Count(PollingStation &p, QSqlDatabase &db);
    int getVote2Count(QList<PollingStation> ps);
    int getVote1Count(QList<PollingStation> ps);
    Kandidat getCandidateForParty(Partei p);
    Partei getPartyForCandidate(Kandidat k);
    void updateData();

    //Static functions
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

    int getIGNORED_PARTY() const;

    static int getVotesSingleParty(QSqlDatabase db, Partei party, PollingStation station);
    static int getVote1Count(PollingStation p, QSqlDatabase db);
    unsigned long connectionCounter = 0;
private:

    int IGNORED_PARTY;
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
