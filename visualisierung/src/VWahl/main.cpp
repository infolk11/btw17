#include <QApplication>
#include <QDesktopWidget>
#include <QLabel>
#include <iostream>
#include <QWindow>
#include <QScreen>

#include "main.h"

/**
 * Main
 *
 * @brief main
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char *argv[])
{
    QApplication app(argc,argv);
    run();
    return EXIT_SUCCESS;
    //app.exec();
}

/**
 * Run method of the program
 *
 * @brief run
 */
void run()
{
    init();
    Logger::log << L_INFO << "Starting the application.";

    Logger::log << L_INFO << "Stopping the application.";
    shutdown();
}

/**
 * Initializes the program
 *
 * @brief init
 * @return
 */
int init()
{
    Logger::init();
    Logger::log << L_INFO << "Initialized the program.";
    return EXIT_SUCCESS;
}

/**
 * shuts down the program
 *
 * @brief shutdown
 * @return
 */
int shutdown()
{
    Logger::log << L_INFO << "Shutting down the program.";
    return EXIT_SUCCESS;
}
