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
    QString SaveFileName;
    QString FileVersion;

    FileVersion = Time.currentDateTime().toString("yyyy-MM-dd");
    FileVersion.replace(":","_");
    FileVersion.replace("-","_");
    FileVersion.replace(" ","-");

    FileName = QString("log.txt");
    SaveFileName = QString("log_%1.txt").arg(FileVersion);

    outFile = new QFile(FileName);
    outSaveFile = new QFile(SaveFileName);

    outFile->open(QIODevice::WriteOnly);
    outSaveFile->open(QIODevice::WriteOnly);
    ts = new QTextStream(outFile);
    sts = new QTextStream(outSaveFile);

    debug   = true;
    info    = true;
    warning = true;
    error   = true;


}

void Logger::init(int LoggerLevel) {

    Logger::init();

    debug   = false;
    info    = false;
    warning = false;
    error   = false;

    if(LoggerLevel & LoggerOutput::Debug)
    {
        debug   = true;
    }

    if(LoggerLevel & LoggerOutput::Info)
    {
        info   = true;
    }

    if(LoggerLevel & LoggerOutput::Warn)
    {
        warning   = true;
    }

    if(LoggerLevel & LoggerOutput::Error)
    {
        error   = true;
    }

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
    QString LogTime;

    if((str == L_INFO and info == true) or (str == L_ERROR and error == true) or (str == L_WARN and warning == true) or (str == L_DEBUG and debug == true))
    {
        Logger::sending_permission = true;
    }

    Logger::value.append(str);
    int endcounter = Logger::value.count("\n");
    if(endcounter > 0)
    {

        Logger::value.remove("\n");


        QDateTime time;
        LogTime.append( time.currentDateTime().toString("hh:mm:ss:zzz"));
        LogTime.append("  ");

        LogTime.append(value);

        if (sending_permission == true)
        {
            qDebug().noquote()  << LogTime;


            *Logger::ts         << LogTime<< "\n";
            Logger::ts->flush();
            *Logger::sts         << LogTime<< "\n";
            Logger::sts->flush();
            Logger::sending_permission = 0;
        }
        Logger::value.clear();
    }

}


Logger::~Logger()
{
    delete ts;
    delete sts;
    delete outFile;
    delete outSaveFile;
}

