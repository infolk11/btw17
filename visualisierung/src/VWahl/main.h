#ifndef MAIN_H
#define MAIN_H

#include "presentationwindow.h"
#include "settingswindow.h"
#include "database.h"

#include <QSettings>
#include <QCoreApplication>

#include "logger.h"



//forward declare Database in order to use it in main
//I have no idea how to do this in a "better" way, nevertheless it does work
class Database;

//same for SettingsWindow
class SettingsWindow;

namespace VWahl
{
    void run(QApplication &app);
    int init();
    int initSettings();
    int shutdown();
    void showGui();

    //database
    extern Database *databaseForUse;

    //functions for setting-file
    void writeBasicSettings(QString h, QString n, QString u, QString p);
    bool doBasicSettingsExist();

    //Guis
    extern PresentationWindow *presentationWindow;
    extern SettingsWindow *settingsWindow;

    //setting object, to store settings, i.e. login details for the database
    //company: Evangelische Schule Neuruppin, name: btw17
    extern QSettings *settings;

}

#endif // MAIN_H

