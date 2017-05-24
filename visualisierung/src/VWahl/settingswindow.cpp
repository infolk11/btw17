#include "settingswindow.h"
#include "ui_settingswindow.h"

SettingsWindow::SettingsWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SettingsWindow)
{
    ui->setupUi(this);

    db = new Database();
    db->initDatabaseSettings();
    if(db->connect() != EXIT_SUCCESS)
        error.showMessage(db->lastError().text());

    dbDialog = new DatabaseDialog(this);


    //Logger::log << L_INFO << db->lastError().text().toStdString();
    if(db->isOpen()){
        Logger::log << L_INFO << "opened Database!";

        QSqlQuery q =db->exec("SELECT P_Bezeichnung FROM partei ORDER BY P_Bezeichnung;");
        q.first();
        while(q.next()){
            ui->zuVerwendendeParteienAuswHlenComboBox->addItem(q.value(0).toString());
        }
    }
    else{
        error.showMessage(db->lastError().text());
    }
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

void SettingsWindow::on_actionBeenden_triggered()
{

}
