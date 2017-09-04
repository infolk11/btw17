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

#define L_ERROR "ERROR       "
#define L_WARN  "WARNING     "
#define L_INFO  "INFO        "
#define L_DEBUG "DEBUG       "


/**
 * Logger based on log4cpp
 *
 * @brief The Logger class
 */
class Logger
{
  public:
    static void init();
    static QString      log();
    static void         send(QString str);
    static QString      Logger::value;
    static QTextStream  * Logger::ts;
    static void         TimerFflush();

    friend QString &operator << (QString &c, QString a);
    friend QString &operator << (QString &c, string a);
    friend QString &operator << (QString &c, const char * a);
    friend QString &operator << (QString &c, int a);

    Logger();

    private:
    // ~Logger();
};

#endif // QT_LOGGER_H
