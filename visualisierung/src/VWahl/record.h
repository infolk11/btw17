#ifndef RECORD_H
#define RECORD_H

#include <QColor>

/**
 * Stores one record either for parties or candidates. Can be visualized with the help of plots.
 *
 */
class RecordObject
{
   public:
    explicit RecordObject(QString desc, int v, QColor col) : description(desc), votes(v), color(col) {}

    QString getDescription() const;
    int getVotes() const;
    QColor getColor() const;

private:
    QString description;
    int votes;
    QColor color;
};



class Record
{
public:
    Record(QString s, unsigned short y, QList<RecordObject> o) : election(s),year(y), objects(o) {}
    Record() = default;
    unsigned short getYear() const;
    void setYear(unsigned short value);

    QString getElection() const;
    void setElection(const QString &value);

    QList<RecordObject> getObjects() const;
    void setObjects(const QList<RecordObject> &value);

private:
    QList<RecordObject> objects;
    QString election;
    unsigned short year;
};

#endif // RECORD_H
