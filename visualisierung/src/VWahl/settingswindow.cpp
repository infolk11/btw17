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

    //drop-down menu to chose
    QComboBox *parteien = new QComboBox();
    QComboBox *kandidaten = new QComboBox();

    parteien->clear();
    kandidaten->clear();

    db.setDbHost("localhost");
    db.setDbName("");
    db.setDbUser("");
    db.setDbPassword("");

    db.connect();
    //if(db.connect() == EXIT_FAILURE)
    //    return EXIT_FAILURE;

    parteien->addItems(db.exec("SELECT bezeichnung FROM Partei")
                       .value("bezeichnung").toStringList());
    kandidaten->addItems(db.exec("SELECT Name FROM Direktkandidat")
                         .value("Name").toStringList());

    //für die Visualisierung der drop-down menüs müssen wir uns noch was überlegen,
    //ich hab an ein wizard schritt für schritt menü innerhalb eines tabs gedacht

    db.close();

    setCentralWidget(mainWidget);
    mainWidget->addTab(welcomeWidget,"Willkommen");

}
