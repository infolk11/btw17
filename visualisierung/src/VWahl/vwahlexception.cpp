#include "vwahlexception.h"

#include <QByteArray>

const char* VWahlException::what()
{
    QByteArray ba = errorMsg.toLatin1();
    const char* ca = ba.data();
    return ca;
}


const char *CandidateNotFoundException::what()
{
    QByteArray ba = errorMsg.toLatin1();
    const char* ca = ba.data();
    return ca;
}
