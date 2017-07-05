#ifndef PARTEI_H
#define PARTEI_H

#include <QString>
#include <QColor>

#include "record.h"

class Partei : public RecordObject
{
public:
    Partei() = default;
    Partei(int id, int lp, QString desc, QColor col) : RecordObject(desc,col), p_id(id) , listenplaetze(lp) {}
    Partei(QString desc, int v,QColor color, int id, int lp): RecordObject(desc,v,color), p_id(id), listenplaetze(lp) {}

private:
    int p_id;
    int listenplaetze;
};

#endif // PARTEI_H
