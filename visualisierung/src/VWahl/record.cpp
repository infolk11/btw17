#include "record.h"

Record::Record()
{

}

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
