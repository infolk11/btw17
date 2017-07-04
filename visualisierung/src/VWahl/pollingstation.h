#ifndef POLLINGSTATION_H
#define POLLINGSTATION_H

#include <QString>

class PollingStation
{
public:
    PollingStation() = default;
    PollingStation(QString desc) : description(desc) {}
    PollingStation(QString desc, QString pc, QString str, int v, int vt) : description(desc), postCode(pc), street(str), voters(v), voterTurnout(vt) {}
    int getId() const;
    void setId(int value);

    QString getDescription() const;
    void setDescription(const QString &value);

    QString getPostCode() const;
    void setPostCode(const QString &value);

    QString getStreet() const;
    void setStreet(const QString &value);

    int getVoters() const;
    void setVoters(int value);

    int getVoterTurnout() const;
    void setVoterTurnout(int value);

private:
    int id;
    QString description;
    QString postCode;
    QString street;
    int voters;
    int voterTurnout;
};

#endif // POLLINGSTATION_H
