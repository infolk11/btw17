#include "pollingstation.h"

PollingStation::PollingStation()
{

}

int PollingStation::getId() const
{
    return id;
}

void PollingStation::setId(int value)
{
    id = value;
}

QString PollingStation::getDescription() const
{
    return description;
}

void PollingStation::setDescription(const QString &value)
{
    description = value;
}

QString PollingStation::getPostCode() const
{
    return postCode;
}

void PollingStation::setPostCode(const QString &value)
{
    postCode = value;
}

QString PollingStation::getStreet() const
{
    return street;
}

void PollingStation::setStreet(const QString &value)
{
    street = value;
}

int PollingStation::getVoters() const
{
    return voters;
}

void PollingStation::setVoters(int value)
{
    voters = value;
}

int PollingStation::getVoterTurnout() const
{
    return voterTurnout;
}

void PollingStation::setVoterTurnout(int value)
{
    voterTurnout = value;
}
