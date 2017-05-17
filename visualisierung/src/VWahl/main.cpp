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

        if (VWahl::doBasicSettingsExist() == false)
            VWahl::writeBasicSettings("localhost", "btw17", "user", "12345678");

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
    settings = new QSettings("Evangelische_Schule_Neuruppin", "btw17");
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

void VWahl::writeBasicSettings(QString h, QString n, QString u, QString p)
{
    //set basic values for the database connection in database-group
    VWahl::settings->beginGroup("database");
    VWahl::settings->value("hostname", h);
    VWahl::settings->value("name", n);
    VWahl::settings->value("user", u);
    VWahl::settings->value("password", p);
    VWahl::settings->endGroup();
    VWahl::settings->sync();

    if (VWahl::settings->status() != 0){
        Logger::log << L_ERROR << "failed to write settings";
    }
    else
        Logger::log << L_INFO << "successful wrote the basic settings to" << VWahl::settings->fileName().toStdString();
}

bool VWahl::doBasicSettingsExist()
{
    return (VWahl::settings->contains("database/hostname") and
            VWahl::settings->contains("database/name") and
            VWahl::settings->contains("database/user") and
            VWahl::settings->contains("database/databasepassword"));
}
