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
    if (VWahl::doBasicSettingsExist() == false)
        VWahl::writeBasicSettings("localhost", "btw17", "user", "12345678");

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

void VWahl::writeBasicSettings(QString h, QString n, QString u, QString p)
{
    //setting object, to store settings, i.e. login details for the database
    //company: Evangelische Schule Neuruppin, name: btw17
    QSettings settings("Evangelische_Schule_Neuruppin", "btw17");

    //set basic values for the database connection in database-group
    settings.beginGroup("database");
    settings.setValue("hostname", h);
    settings.setValue("name", n);
    settings.setValue("user", u);
    settings.setValue("password", p);
    settings.endGroup();
    settings.sync();
    if (settings.status() != 0){
        Logger::log << L_ERROR << "failed to write settings";
    }
    else
        Logger::log << L_INFO << "wrote the basic settings to" << settings.fileName().toStdString();
}

bool VWahl::doBasicSettingsExist()
{
    //setting object, to store settings, i.e. login details for the database
    //company: Evangelische Schule Neuruppin, name: btw17
    QSettings settings("Evangelische_Schule_Neuruppin", "btw17");
    settings.beginGroup("database");

    return !(settings.contains("hostname") and
            settings.contains("name") and
            settings.contains("user") and
            settings.contains("databasepassword"));
}
