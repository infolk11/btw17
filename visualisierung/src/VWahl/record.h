#ifndef RECORD_H
#define RECORD_H

#include <QColor>
#include <QList>

/**
 * Stores one record either for parties or candidates. Can be visualized with the help of plots.
 *
 */
class RecordObject
{
   public:
    RecordObject() = default;
    RecordObject(QString desc, QColor col) : description(desc),color(col) {}
    RecordObject(QString desc, int v, QColor col) : description(desc), votes(v), color(col) {}

    QString getDescription() const;
    int getVotes() const;
    QColor getColor() const;

private:
    QString description;
    int votes;
    QColor color;
};


/**
 * Stores the recordobjects and some general information about the record
 *
 * @brief The Record class
 */
class Record
{
public:
    Record(QString s, unsigned short y, QList<RecordObject> o) : objects(o), election(s), year(y) {}
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
