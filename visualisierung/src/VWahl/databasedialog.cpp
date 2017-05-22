#include "databasedialog.h"
#include "ui_databasedialog.h"

DatabaseDialog::DatabaseDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DatabaseDialog)
{
//    ui->typeEdit->insert(SettingsWindow::db->driverName());
//    ui->hostnameEdit->insert(SettingsWindow::db->hostName());
//    ui->userEdit->insert(SettingsWindow::db->userName());
//    ui->passwordEdit->insert(SettingsWindow::db->password());
//    ui->nameEdit->insert(SettingsWindow::db->databaseName());

    ui->setupUi(this);

}

DatabaseDialog::~DatabaseDialog()
{
    delete ui;
}
