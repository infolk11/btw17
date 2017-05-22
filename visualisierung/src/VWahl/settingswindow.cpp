#include "settingswindow.h"
#include "ui_settingswindow.h"

SettingsWindow::SettingsWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SettingsWindow)
{
    ui->setupUi(this);

//    if(VWahl::databaseForUse->isConnected() == true)
//        ui->zuVerwendendeParteienAuswHlenComboBox->addItems(VWahl::databaseForUse->exec("SELECT P_Bezeichnung FORM partei ORDER BY P_Bezeichnung;", 0).toStringList());

    //Logger::log << L_INFO << VWahl::databaseForUse->status().toStdString();
}

SettingsWindow::~SettingsWindow()
{
    delete ui;
}
