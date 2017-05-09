#ifndef LOGGER_H
#define LOGGER_H

#include <log4cpp/Category.hh>
#include <log4cpp/Appender.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/Layout.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/Priority.hh>

#define L_ERROR log4cpp::Priority::ERROR
#define L_WARN  log4cpp::Priority::WARN
#define L_INFO  log4cpp::Priority::INFO
#define L_DEBUG log4cpp::Priority::DEBUG


/**
 * Logger based on log4cpp
 *
 * @brief The Logger class
 */
class Logger
{
public:
    Logger() = delete; //only static methods
    static void init();
    static log4cpp::Category& log;
private:
    static log4cpp::Appender* appender;
    static log4cpp::Appender* consoleAppender;
};

#endif // LOGGER_H
