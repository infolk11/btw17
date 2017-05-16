#include <QApplication>
#include <QDesktopWidget>
#include <QLabel>
#include <iostream>
#include <QWindow>
#include <QScreen>

#include "main.h"
#include "plottest.h"
#include "presentationwindow.h"

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
    VWahl::run(app);
    return EXIT_SUCCESS;
    //app.exec();
}

/**
 * Run method of the program
 *
 * @brief run
 */
void VWahl::run(QApplication& app)
{
    try
    {
        VWahl::init();
        Logger::log << L_INFO << "Running the application.";
        VWahl::showGui();
        Logger::log << L_INFO << "Initalized guis.";
        app.exec();
        Logger::log << L_INFO << "Stopping the application.";
    }catch(...)
    {
        //TO-DO: Advanced exception handling...
        Logger::log << L_ERROR << "A fatal error has occured!";
    }
    VWahl::shutdown();
}

/**
 * Will initialize the gui
 *
 * @brief showGuis
 */
void VWahl::showGui()
{
    PresentationWindow* window = new PresentationWindow();
    window->showMaximized();
//    PresentationWindow *presentationWindow = new PresentationWindow();
//    SettingsWindow *settingsWindow = new SettingsWindow(presentationWindow);

//    settingsWindow->showMaximized();
}

/**
 * Initializes the program
 *
 * @brief init
 * @return
 */
int VWahl::init()
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
int VWahl::shutdown()
{
    Logger::log << L_INFO << "Shutting down the program.";

    delete settingsWindow;
    delete presentationWindow;

    return EXIT_SUCCESS;
}
