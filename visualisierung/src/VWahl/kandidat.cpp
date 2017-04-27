#include "kandidat.h"



int Kandidat::getId() const
{
    return id;
}

void Kandidat::setId(int value)
{
    id = value;
}

QString Kandidat::getName() const
{
    return name;
}

void Kandidat::setName(const QString &value)
{
    name = value;
}

QString Kandidat::getLName() const
{
    return LName;
}

void Kandidat::setLName(const QString &value)
{
    LName = value;
}

QImage Kandidat::getImage() const
{
    return image;
}

void Kandidat::setImage(const QImage &value)
{
    image = value;
}
