#ifndef LOGGER_H
#define LOGGER_H

//#include <Qdialog>
#include <QDebug>
#include <QFile>
//#include <QErrorMessage>
#include <QString>
//#include <iostream>
#include <sstream>
#include <string>
#include <QTime>
#include <QTimer>


using namespace std;


#define L_ERROR "ERROR    "
#define L_WARN  "WARNING  "
#define L_INFO  "INFO     "
#define L_DEBUG "DEBUG    "


/**
 * Logger based on log4cpp
 *
 * @brief The Logger class
 */
class Logger
{
public:
    void init();
    void init(int LoggerLevel);
    static Logger       log;

    enum LoggerOutput{None  = 0,
                      Error  = 8,
                      Warn   = 4,
                      Info   = 2,
                      Debug  = 1,
                      All    = 15,
                      Level1 = LoggerOutput::Error,
                      Level2 = LoggerOutput::Error | LoggerOutput::Warn,
                      Level3 = LoggerOutput::Error | LoggerOutput::Warn | LoggerOutput::Info,
                      Level4 = LoggerOutput::All
                     };

private:
    void         send(QString str);
    QString      value;
    QFile        *outFile;
    QFile        *outSaveFile;
    QTextStream  *ts;
    QTextStream  *sts;
    bool         sending_permission;
    bool         error;
    bool         warning;
    bool         info;
    bool         debug;
    void         TimerFflush();

    friend Logger &operator << (Logger& l, const char * a);
    friend Logger &operator << (Logger& l, string a);
    friend Logger &operator << (Logger& l, QString a);
    friend Logger &operator << (Logger& l, int a);

    //None	= keine Ausgabe
    //Error	= nur Error
    //Warn	= nur Warning
    //Info	= nur Info
    //Debug	= nur Debug
    //All		= alle werden ausgegeben
    //Level1	= nur Error
    //Level2	= Error und Warning,
    //Level3	= Error, Warning und Info,
    //Level4	= alle werden ausgegeben


    Logger() = default;
    ~Logger();
};

#endif // QT_LOGGER_H
