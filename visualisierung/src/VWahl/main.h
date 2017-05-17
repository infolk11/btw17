#ifndef MAIN_H
#define MAIN_H

#include <QSettings>

#include "logger.h"

#include "presentationwindow.h"
#include "settingswindow.h"
namespace VWahl
{
    void run(QApplication &app);
    int init();
    int shutdown();
    void showGui();

    //functions for setting-file
    void writeBasicSettings(QString h, QString n, QString u, QString p);
    bool doBasicSettingsExist();

    //Guis
    PresentationWindow *presentationWindow;
    SettingsWindow *settingsWindow;

    //setting object, to store settings, i.e. login details for the database
    //company: Evangelische Schule Neuruppin, name: btw17
    QSettings settings("Evangelische_Schule_Neuruppin", "btw17");

}

#endif // MAIN_H

