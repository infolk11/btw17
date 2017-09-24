#include "record.h"

QString RecordObject::getDescription() const
{
    return description;
}

double RecordObject::getVotes() const
{
    return votes;
}

QColor RecordObject::getColor() const
{
    return color;
}

void RecordObject::setVotes(double value)
{
    votes = value;
}

bool RecordObject::operator==(const RecordObject l)
{
    if(this == &l)
        return true;

    if(l.getDescription() != getDescription())
        return false;
    if(l.getVotes() != getVotes())
        return false;
    return true;
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

QList<QList<RecordObject> > Record::getObjects() const
{
    return objects;
}

void Record::setObjects(const QList<QList<RecordObject> > &value)
{
    objects = value;
}

QList<RecordObject> Record::recordsAsOneList()
{
   QList<RecordObject> oneList;
   for(QList<RecordObject> objs : objects)
       oneList += objs;
   return oneList;
}

