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
    Kandidat(int i, QString ln, QString n, QColor col ) : RecordObject(ln,col), id(i),lname(ln),name(n) {}
    Kandidat(int i, QString n, QString ln, int v, QColor col) : RecordObject(ln,v,col), id(i), name(n), lname(ln) {}

    int getId() const;
    void setId(int value);

    QString getName() const;
    void setName(const QString &value);

    QString getLname() const;
    void setLname(const QString &value);

    QImage getImage() const;
    void setImage(const QImage &value);

    static QList<RecordObject> convertToRecordList(QList<Kandidat> candidates);
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
    QString lname;
    QImage image;
};

#endif // KANDIDAT_H
