#include "vwahlexception.h"

const char* VWahlException::what()
{
    return errorMsg.toStdString().c_str();
}

