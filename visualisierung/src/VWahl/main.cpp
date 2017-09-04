#include <QApplication>
#include <QDesktopWidget>
#include <QLabel>
#include <iostream>
#include <QWindow>
#include <QScreen>

#include "main.h"
#include "plottest.h"

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

namespace VWahl {


//Variables
QSettings *settings;
PresentationWindow *presentationWindow;
SettingsWindow *settingsWindow;
QVector<Database> *dbs;

//Methods
/**
 * Run method of the program
 *
 * @brief run
 */
void run(QApplication& app)
{
    try
    {
        if(VWahl::init() != EXIT_SUCCESS)
        {
            Logger::log << L_ERROR << "Failed to initialize the program. This is an fatal error which will cause a shutdown.";
            return;
        }

        Logger::log << L_INFO << "Running the application.";
        //VWahl::showGui();
        Logger::log << L_INFO << "Initalized guis.";
        app.exec();
        Logger::log << L_INFO << "Stopping execution of app.";
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
void showGui()
{
    PresentationWindow* window = new PresentationWindow();
    SettingsWindow *settingswindow = new SettingsWindow(window);
    settingswindow->showMaximized();
}

/**
 * Initializes the program
 *
 * @brief init
 * @return
 */
int init()
{
    //Initializing the logger
    Logger::init();

    //Initializing the settings
    if(initSettings()!= EXIT_SUCCESS)
    {
        Logger::log << L_ERROR << "Failed to initalize settings!";
        return EXIT_FAILURE;
    }

    //Initializing databases
    VWahl::dbs = new QVector<Database>();
    if(Database::checkDatabaseSettings() != EXIT_SUCCESS)
    {
        Logger::log << L_ERROR << "Failed to initialize database settings.";
        return EXIT_FAILURE;
    }

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

    VWahl::settings->sync();
    if (VWahl::settings->status() != 0){
        Logger::log << L_ERROR << "failed to write the settings to" << VWahl::settings->fileName().toStdString();
        return EXIT_FAILURE;
    }
    else
        Logger::log << L_INFO << "wrote the settings to" << VWahl::settings->fileName().toStdString();

    //Cleaning up memory
    delete settingsWindow;
    delete presentationWindow;
    delete settings;

    return EXIT_SUCCESS;
}

int initSettings()
{
    settings = new QSettings("Evangelische_Schule_Neuruppin", "btw17");
    settings->sync();
    return EXIT_SUCCESS;
}

}
