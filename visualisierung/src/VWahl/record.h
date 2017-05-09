#ifndef RECORD_H
#define RECORD_H

#include <QColor>

/**
 * Stores one record either for parties or candidates. Can be visualized with the help of plots.
 *
 * @brief The Record class
 */
class Record
{
public:
    Record();
};

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

#endif // RECORD_H
