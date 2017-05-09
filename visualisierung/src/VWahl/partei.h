#ifndef PARTEI_H
#define PARTEI_H

#include <QString>
#include <QColor>

class Partei
{
public:
    Partei() = default;

private:
    QString bezeichnung;
    int p_id;
    int listenplaetze;
    QColor farbe;
};

#endif // PARTEI_H
