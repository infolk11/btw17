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

void DatabaseDialog::on_acceptButton_clicked()
{
    VWahl::settings->setValue("database/type", ui->typeEdit->text());
    VWahl::settings->setValue("database/hostname", ui->hostnameEdit->text());
    VWahl::settings->setValue("database/user", ui->userEdit->text());
    VWahl::settings->setValue("database/password", ui->passwordEdit->text());
    VWahl::settings->setValue("database/name", ui->nameEdit->text());

//for testing purpose
//    Logger::log << L_INFO << "type aus object: " << ui->typeEdit->text().toStdString()<< "\n";
//    Logger::log << L_INFO << "type aus file:   " << VWahl::settings->value("database/type").toString().toStdString()<< "\n";

    //I don't know how to do this...
    //VWahl::settingsWindow->db->reloadSettings();
    Logger::log << L_INFO << "in accept: " << "\n";
    //Logger::log << L_INFO << "in accept: " << *(VWahl::settingsWindow->db)<< "\n";

    this->hide();
}
