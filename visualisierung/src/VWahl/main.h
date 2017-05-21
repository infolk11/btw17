#ifndef MAIN_H
#define MAIN_H

#include <QSettings>
#include <QCoreApplication>

#include "logger.h"

#include "presentationwindow.h"
#include "settingswindow.h"
#include "database.h"

namespace VWahl
{
    void run(QApplication &app);
    int init();
    int initSettings();
    int shutdown();
    void showGui();

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

