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


    QDateTime Time;
    QString FileName;
    QString FileVersion;

    FileVersion = Time.currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    FileVersion.replace(":","_");
    FileVersion.replace("-","_");
    FileVersion.replace(" ","-");


    FileName = QString("log_%1.txt").arg(FileVersion);

    static QFile outFile(FileName);
    //outFile.rename(FileName);
    //outFile.open(QIODevice::WriteOnly | QIODevice::Append);
    outFile.open(QIODevice::WriteOnly);
    //outFile.open(QIODevice::WriteOnly);
    static QTextStream out(&outFile);

    Logger::ts = &out;


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

        QDateTime time;

        //Logger::value.append(time.currentDateTime().toString().remove("Mo").remove("Sep"));
        //Logger::value.append(time.currentDateTime().toString());
        //Logger::value.append("  ");

      send_state = 1;
      }

    Logger::value.append(str);
    int endcounter = Logger::value.count("\n");
    if(endcounter > 0)
    {
        Logger::value.remove("\n");
        qDebug().noquote()  << Logger::value;
        *Logger::ts         << Logger::value << "\n";
        Logger::ts->flush();
        Logger::value.clear();
        send_state = 1;
    }


}

