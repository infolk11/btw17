#include "logger.h"

//Static variables
QString Logger::value;
int send_state;
int ErrorNumber;
QTextStream * Logger::ts;

/**
 * Initializing the logger
 *
 * @brief QTLogger::init
 */


Logger::Logger(void){
}

void Logger::init() {

    static QFile outFile("log.txt");

    outFile.open(QIODevice::WriteOnly | QIODevice::Append);

    static QTextStream out(&outFile);

    Logger::ts = &out;

    qDebug().noquote().nospace();

    send_state = 0;
}


QString Logger::log()
{
    QString str;

   send_state = 0;

   return str ;
}

QString &operator << (QString &c, const char * a)
{
    QString str;

    str.sprintf("%s",a);

    Logger::send(str);

    return str;
}
QString &operator << (QString &c, QString a)
{
    Logger::send(a);

    return a;
}

QString &operator << (QString &c, string a)
{
    QString str;

    //str.sprintf("%s",a);
    str = QString::fromStdString(a);
    Logger::send(str);

    return str;
}

QString &operator << (QString &c, int a)
{
    QString str;

    str.sprintf("%d",a);

    Logger::send(str);

    return str;
}

void Logger::send(QString str)
{
    if(send_state == 0)
    {
        if(Logger::value.length() > 0)
        {
            qDebug()        << Logger::value;
            *Logger::ts     << Logger::value << "\n";

            Logger::value.clear();
        }

        QDateTime time;
        /*
        QString temp_str;
        temp_str = time.toString();
        QByteArray ba = temp_str.toLatin1();
        const char *c_str2 = ba.data();
        */

        Logger::value.append(time.currentDateTime().toString());
        Logger::value.append("  ");

        send_state = 1;
    }
    else if (send_state == 1)
    {
        QTimer::singleShot(20,TimerFflush);
        send_state = 2;
    }

    Logger::value.append(str);

}


void Logger::TimerFflush()
{
    if(Logger::value.length() > 0)
    {
        qDebug()        << Logger::value;
        *Logger::ts     << Logger::value << "\n";

        Logger::value.clear();
    }
    send_state = 1;
}


