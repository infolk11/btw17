#ifndef POLLINGSTATION_H
#define POLLINGSTATION_H

#include <QString>

#include "record.h"

class PollingStation : public RecordObject
{
public:
    PollingStation() = default;
    PollingStation(QString desc, int i, QString pc, QString str) : RecordObject(desc), id(i),postCode(pc),street(str) {}
    PollingStation(QString desc, QString pc, QString str, int v, int vt) : RecordObject(desc), postCode(pc), street(str), voters(v), voterTurnout(vt) {}
    int getId() const;
    void setId(int value);

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
    QString postCode;
    QString street;
    int voters;
    int voterTurnout;
};

#endif // POLLINGSTATION_H
