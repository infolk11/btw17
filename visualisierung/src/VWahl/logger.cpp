#include "logger.h"

//Static variables
Logger Logger::log = Logger();

/**
 * Initializing the logger
 *
 * @brief QTLogger::init
 */



void Logger::init() {

    QDateTime Time;
    QString FileName;
    QString FileVersion;

    FileVersion = Time.currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    FileVersion.replace(":","_");
    FileVersion.replace("-","_");
    FileVersion.replace(" ","-");


    FileName = QString("log_%1.txt").arg(FileVersion);

    outFile = new QFile(FileName);
    //outFile.rename(FileName);
    //outFile.open(QIODevice::WriteOnly | QIODevice::Append);
    outFile->open(QIODevice::WriteOnly);
    //outFile.open(QIODevice::WriteOnly);
    ts = new QTextStream(outFile);


}

Logger &operator << (Logger &l, const char * a)
{
    QString str;

    str.sprintf("%s",a);
    l.send(str);

    return l;
}
Logger &operator << (Logger &l, QString a)
{
    l.send(a);

    return l;
}
Logger &operator << (Logger &l, string a)
{
    QString str;

    str = QString::fromStdString(a);
    l.send(str);

    return l;
}
Logger &operator << (Logger &l, int a)
{
    QString str;

    str.sprintf("%d",a);

    l.send(str);

    return l;
}

void Logger::send(QString str)
{
    Logger::value.append(str);
    int endcounter = Logger::value.count("\n");
    if(endcounter > 0)
    {
        Logger::value.remove("\n");
        qDebug().noquote()  << Logger::value;
        *Logger::ts         << Logger::value << "\n";
        Logger::ts->flush();
        Logger::value.clear();
    }
}

Logger::~Logger()
{
    delete ts;
    delete outFile;
}

