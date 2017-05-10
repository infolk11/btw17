#ifndef WAHLLOKAL_H
#define WAHLLOKAL_H

#include <QString>

class Wahllokal
{
public:
    Wahllokal() = default;

private:
    int w_id;
    int wahlberechtigte;
    QString strasse;
    int postleitzahl;
    QString bezeichnung;
    double wahlbeteiligung;
};

#endif // WAHLLOKAL_H
