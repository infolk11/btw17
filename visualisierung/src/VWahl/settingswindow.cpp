#include "settingswindow.h"
#include "ui_settingswindow.h"

SettingsWindow::SettingsWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SettingsWindow)
{
    ui->setupUi(this);

    Database *db = new Database();
    db->initDatabaseSettings();

    DatabaseDialog *dbDialog = new DatabaseDialog();

    Logger::log << L_INFO << db->lastError().text().toStdString();
    if(db->isOpen())
        ui->zuVerwendendeParteienAuswHlenComboBox->addItems(db->exec("SELECT P_Bezeichnung FROM partei ORDER BY P_Bezeichnung;").value(0).toStringList());
}

SettingsWindow::~SettingsWindow()
{
    //delete db;
    delete ui;
}

void SettingsWindow::on_actionDatabase_Settings_triggered()
{
    dbDialog->show();
}
