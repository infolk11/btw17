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

/*
typedef enum {EMERG  = 0,
              FATAL  = 0,
              ALERT  = 100,
              CRIT   = 200,
              ERROR  = 300,
              WARN   = 400,
              NOTICE = 500,
              INFO   = 600,
              DEBUG  = 700,
              NOTSET = 800
} PriorityLevel;
*/

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
    static Logger       log;
    void         send(QString str);
    QString      value;
    QFile        *outFile;
    QFile        *outSaveFile;
    QTextStream  *ts;
    QTextStream  *sts;
    bool         priority;
    bool         error;
    bool         warning;
    bool         info;
    bool         debug;
    void         TimerFflush();

    friend Logger &operator << (Logger& l, const char * a);
    friend Logger &operator << (Logger& l, string a);
    friend Logger &operator << (Logger& l, QString a);
    friend Logger &operator << (Logger& l, int a);



    private:
        Logger() = default;
        ~Logger();
};

#endif // QT_LOGGER_H
