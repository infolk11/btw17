#include "record.h"

QString RecordObject::getDescription() const
{
    return description;
}

int RecordObject::getVotes() const
{
    return votes;
}

QColor RecordObject::getColor() const
{
    return color;
}

void RecordObject::setVotes(int value)
{
    votes = value;
}

unsigned short Record::getYear() const
{
    return year;
}

void Record::setYear(unsigned short value)
{
    year = value;
}

QString Record::getElection() const
{
    return election;
}

void Record::setElection(const QString &value)
{
    election = value;
}

QList<RecordObject> Record::getObjects() const
{
    return objects;
}

void Record::setObjects(const QList<RecordObject> &value)
{
    objects = value;
}
