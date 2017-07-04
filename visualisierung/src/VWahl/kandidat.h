#ifndef KANDIDAT_H
#define KANDIDAT_H

#include <QString>
#include <QImage>
#include <QColor>

#include "record.h"

class Kandidat : public RecordObject
{
public:
    Kandidat() = default;
    Kandidat(int i, QString n, QString ln, int v, QColor col) : RecordObject(n + " " + ln,v,col), id(i), name(n), LName(ln) {}

    int getId() const;
    void setId(int value);

    QString getName() const;
    void setName(const QString &value);

    QString getLName() const;
    void setLName(const QString &value);

    QImage getImage() const;
    void setImage(const QImage &value);

private:
    /**
     *Things we want to know about a candidate:
     * Name,
     * LName,
     * ID,
     * Image,
     * Color
     */
    int id;
    QString name;
    QString LName;
    QImage image;
};

#endif // KANDIDAT_H
