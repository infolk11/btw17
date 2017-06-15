#ifndef MAIN_H
#define MAIN_H

#include "database.h"
#include "presentationwindow.h"
#include "settingswindow.h"
#include "plottest.h"

#include <QSettings>
#include <QCoreApplication>
#include <QVector>

#include "logger.h"



//forward declare SettingsWindow in order to use it in main
//I have no idea how to do this in a "better" way, nevertheless it does work
class SettingsWindow;
class Database;

namespace VWahl
{
    void run(QApplication &app);
    int init();
    int initSettings();
    int shutdown();
    void showGui();

    //Guis
    extern PresentationWindow *presentationWindow;
    extern SettingsWindow *settingsWindow;

    //setting object, to store settings, i.e. login details for the database
    //company: Evangelische Schule Neuruppin, name: btw17
    extern QSettings *settings;

    //QVector to refer the databases used by the program.
    extern QVector<Database> *dbs;

}

#endif // MAIN_H

