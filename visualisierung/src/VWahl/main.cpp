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
    return app.exec();
}

/**
 * Run method of the program
 *
 * @brief run
 */
void run()
{
    std::cout << "Starting the application." << std::endl;

    std::cout << "Stopping the application." << std::endl;
}

/**
 * Initializes the program
 *
 * @brief init
 * @return
 */
int init()
{
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
    return EXIT_SUCCESS;
}
