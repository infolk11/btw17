#ifndef MAIN_H
#define MAIN_H

#include "logger.h"

#include "presentationwindow.h"
#include "settingswindow.h"
namespace VWahl
{
    void run(QApplication &app);
    int init();
    int shutdown();
    void showGui();

    //Guis
    PresentationWindow *presentationWindow;
    SettingsWindow *settingsWindow;

}

#endif // MAIN_H

