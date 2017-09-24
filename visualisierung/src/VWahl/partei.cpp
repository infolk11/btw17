#include "partei.h"


int Partei::getP_id() const
{
    return p_id;
}

void Partei::setP_id(int value)
{
    p_id = value;
}

int Partei::getListenplaetze() const
{
    return listenplaetze;
}

void Partei::setListenplaetze(int value)
{
    listenplaetze = value;
}

QList<RecordObject> Partei::convertToRecordList(QList<Partei> parties)
{
    QList<RecordObject> result;
    for(Partei p : parties)
            result.push_back(p);
    return result;
}
