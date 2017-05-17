#ifndef MAIN_H
#define MAIN_H

#include <QSettings>
#include <QCoreApplication>

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

}

#endif // MAIN_H

