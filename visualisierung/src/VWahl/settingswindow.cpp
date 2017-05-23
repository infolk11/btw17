#include "settingswindow.h"
#include "ui_settingswindow.h"

SettingsWindow::SettingsWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SettingsWindow)
{
    ui->setupUi(this);

    db = new Database();
    db->initDatabaseSettings();

    dbDialog = new DatabaseDialog(this);

    Logger::log << L_INFO << db->lastError().text().toStdString();
    if(db->isOpen())
        ui->zuVerwendendeParteienAuswHlenComboBox->addItems(db->exec("SELECT P_Bezeichnung FROM partei ORDER BY P_Bezeichnung;").value(0).toStringList());
}

SettingsWindow::~SettingsWindow()
{
    delete db;
    delete ui;

    ui = NULL;
    db = NULL;
}
void SettingsWindow::on_actionDatabase_Settings_triggered()
{
    dbDialog->show();
}
