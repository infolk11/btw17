#include "settingswindow.h"

SettingsWindow::~SettingsWindow()
{
    delete welcomeWidget;
}

/**
 * Initializes the gui components
 *
 * @brief SettingsWindow::init
 */
void SettingsWindow::init()
{
    welcomeWidget = new WelcomeWidget();
    mainWidget = new QTabWidget();

    setCentralWidget(mainWidget);
    mainWidget->addTab(welcomeWidget,"Willkommen");

}
