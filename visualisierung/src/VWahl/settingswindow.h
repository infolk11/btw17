#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H

#include "presentationwindow.h"
#include "logger.h"
#include "welcomewidget.h"

#include <QMainWindow>
#include <QGridLayout>
#include <qtabwidget.h>

/**
 * Window to create the plots for PresentationWindow
 *
 * @brief The SettingsWindow class
 */
class SettingsWindow : public QMainWindow
{
public:
    SettingsWindow(PresentationWindow* pW) : presentationWindow(pW) {init();}
    ~SettingsWindow();
private:

    //Methods
    void init();

    //Objects
    PresentationWindow* presentationWindow;

    //Gui-elements
    QGridLayout *mainLayout;
    QTabWidget *mainWidget;
    WelcomeWidget *welcomeWidget;
};

#endif // SETTINGSWINDOW_H
