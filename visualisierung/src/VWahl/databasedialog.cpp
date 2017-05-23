#include "databasedialog.h"
#include "ui_databasedialog.h"

DatabaseDialog::DatabaseDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DatabaseDialog)
{
    ui->setupUi(this);

    ui->typeEdit->insert(VWahl::settings->value("database/type").toString());
    ui->hostnameEdit->insert(VWahl::settings->value("database/hostname").toString());
    ui->userEdit->insert(VWahl::settings->value("database/user").toString());
    ui->passwordEdit->insert(VWahl::settings->value("database/password").toString());
    ui->nameEdit->insert(VWahl::settings->value("database/name").toString());



}

DatabaseDialog::~DatabaseDialog()
{
    delete ui;
}
