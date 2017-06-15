#include "querydialog.h"
#include "ui_querydialog.h"

QueryDialog::QueryDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QueryDialog)
{
    ui->setupUi(this);
    connect(ui->cancelButton, &QPushButton::clicked,
            this, &QueryDialog::close);
    init();
}

QueryDialog::~QueryDialog()
{
    delete ui;
}

void QueryDialog::addItem()
{

}

void QueryDialog::writeBasicItemsToSettings()
{
    VWahl::settings->beginGroup("querys");
    VWahl::settings->setValue("partyIdAndName", "SELECT P_ID, P_Bezeichnung FROM partei;");
}

void QueryDialog::init()
{
    VWahl::settings->beginGroup("querys");
    QStringList keys = VWahl::settings->allKeys();

    for (int i = 0; i < keys.size(); ++i){
        QVector < QTableWidgetItem * > tmp;
        tmp.append(new QTableWidgetItem(keys.at(i)));
        tmp.append(new QTableWidgetItem(VWahl::settings->value(keys.at(i)).toString()));
        items.append(tmp);
        ui->tableWidget->setItem(i, 0, items.at(i).at(0));
        ui->tableWidget->setItem(i, 1, items.at(i).at(1));
    }
    VWahl::settings->endGroup();
}
