#ifndef LOGGER_H
#define LOGGER_H

//#include <Qdialog>
#include <QDebug>
#include <QFile>
//#include <QErrorMessage>
//#include <QString>
//#include <iostream>
#include <sstream>
#include <string>

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

#define L_ERROR 300
#define L_WARN  400
#define L_INFO  600
#define L_DEBUG 700


/**
 * Logger based on log4cpp
 *
 * @brief The Logger class
 */
class Logger
{
  public:
    static ostringstream  log;
    static void init();

    friend ostringstream &operator<< (ostringstream &ostr, const char* a);
    friend ostringstream &operator<< (ostringstream &ostr, int a);
    friend ostringstream &operator<< (ostringstream &ostr, string a);

  private:
    Logger();
    ~Logger();
};

#endif // QT_LOGGER_H
