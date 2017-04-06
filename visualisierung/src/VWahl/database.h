#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql/QtSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QString>

class Database
{
public:
    Database(QString name);
    Database() = default;
    auto connect() -> bool;
    auto readEntries() -> std::vector<Entry>;
    auto close() -> void;

private:
    auto getSize(QSqlQuery &quey) -> int;
    auto exec(QString &) -> QSqlQuery;

    QString type = "QMYSQL"
    QString db_host;
    QString db_name;
    QString db_user;
    QString db_password;

    QSqlDatabase db;
    QString dbcon_name;
    bool connected = false;
};

#endif // DATABASE_H
