#include "logger.h"

//Static variables
log4cpp::Appender *Logger::appender;
log4cpp::Appender *Logger::consoleAppender;
log4cpp::Category& Logger::log = log4cpp::Category::getRoot();

/**
 * Initializing the logger
 *
 * @brief Logger::init
 */
void Logger::init() {
    appender = new log4cpp::FileAppender("default","program.log");
    consoleAppender = new log4cpp::OstreamAppender("console",&std::cout);
    log4cpp::PatternLayout *layout = new log4cpp::PatternLayout();
    layout->setConversionPattern("%d: %p - %m %n");
    appender->setLayout(layout);
    consoleAppender->setLayout(new log4cpp::BasicLayout);
    log.setPriority(log4cpp::Priority::DEBUG);
    log.addAppender(appender);
    log.addAppender(consoleAppender);
}
