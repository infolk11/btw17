#include "logger.h"

//Static variables

ostringstream  Logger::log;
int output_counter;
int ErrorNumber;

/**
 * Initializing the logger
 *
 * @brief QTLogger::init
 */


void Logger::init() {

    QString str = "Start logger";
    qDebug() << str;
    output_counter = 0;
}

ostringstream &operator<< (ostringstream &ostr, const char* a)
{
    QFile outFile("log.txt");
    outFile.open(QIODevice::WriteOnly | QIODevice::Append);
    QTextStream ts(&outFile);

    if(output_counter == 1)
    {
        qDebug() << ErrorNumber << a;
        ts << ErrorNumber << a << endl;
        output_counter = 0;
    }
    else
    {
        qDebug() << a;
        ts << a << endl;
    }

    return ostr;
}

ostringstream &operator<< (ostringstream &ostr, int a)
{

    if (output_counter == 0)
    {
        ErrorNumber = a;
        output_counter = 1;
    }

    return ostr;
}

ostringstream &operator<< (ostringstream &ostr, string a)
{
    qDebug("hallo");

    return ostr;
}
