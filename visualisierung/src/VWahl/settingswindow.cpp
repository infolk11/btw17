
#include "settingswindow.h"
#include "ui_settingswindow.h"

SettingsWindow::SettingsWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SettingsWindow)
{
    ui->setupUi(this);

    db = new Database("wahl17");
    db->initByDatabaseSettings();
    if(db->connect() != EXIT_SUCCESS)
        error.showMessage(db->lastError().text());

    dbDialog = new DatabaseDialog(this);
    queryDialog = new QueryDialog(this);

    //set shortcuts
    ui->actionBeenden->setShortcut(Qt::CTRL + Qt::Key_Q);

    //it should be possible to select multiple items
    ui->partyList->setSelectionMode(QAbstractItemView::MultiSelection);
    ui->candidatesList->setSelectionMode(QAbstractItemView::MultiSelection);

    //signal and slot in new qt5 syntax
    connect(ui->actionBeenden, &QAction::triggered,
            this, &SettingsWindow::close);

    connect(ui->actionDatabaseSettings, &QAction::triggered,
            this->dbDialog, &DatabaseDialog::show);

    //using lambda functions
    connect(ui->showAssociatedParty, &QCheckBox::stateChanged,
            [=](const int state){
        QSqlQuery q;
        if(state == Qt::Checked){
            ui->partyList->clear();
            q = db->exec(VWahl::settings->value("querys/candidatesAndTheirPartys").toString());
            if (q.lastError().type() == QSqlError::NoError){
                while(q.next())
                    new QListWidgetItem(q.value(0).toString() + ", " + q.value(1).toString() + "\t" + q.value(2).toString(), ui->candidatesList);
            }
            else{
                Logger::log << L_ERROR << q.lastError().text().toStdString();
                error.showMessage(q.lastError().text());
                return;
            }
        }
        else{
            ui->partyList->clear();
            q = db->exec(VWahl::settings->value("querys/candidates").toString());
            if(q.lastError().type() == QSqlError::NoError){
                while(q.next())
                   new QListWidgetItem(q.value(0).toString() + ", " + q.value(1).toString(), ui->candidatesList);
            }
            else{
                Logger::log << L_ERROR << q.lastError().text().toStdString();
                error.showMessage(q.lastError().text());
                return;
            }
        }
    });

    connect(ui->selectAllCandidatesCheckBox, &QCheckBox::stateChanged,
            [=](const int state){
        if(state == Qt::Checked)
            ui->candidatesList->selectAll();
        else
            ui->candidatesList->clearSelection();
    });

    connect(ui->selectAllPartysCheckBox, &QCheckBox::stateChanged,
            [=](const int state){
        if(state == Qt::Checked)
            ui->partyList->selectAll();
        else
            ui->partyList->clearSelection();
    });

    connect(ui->actionquerys, &QAction::triggered,
            queryDialog, &QueryDialog::show);

    if(db->isOpen()){
        Logger::log << L_INFO << "opened Database!";

        //put all partys into the partyListWidget
        QSqlQuery q = db->exec(VWahl::settings->value("querys/partys").toString());
        q.first();
        while(q.next()){
            //2nd method better to use
            //ui->partyList->addItem(q.value(0).toString());
            new QListWidgetItem(q.value(0).toString(), ui->partyList);
        }

        //put all candidates into the candidatesList
        q = db->exec(VWahl::settings->value("querys/candidates").toString());
        while(q.next()){
            //2nd method better to use
            //ui->candidatesList->addItem(q.value(0).toString() + ", " + q.value(1).toString());
            new QListWidgetItem(q.value(0).toString() + ", " + q.value(1).toString(), ui->candidatesList);
        }
    }
    else{
        Logger::log << L_ERROR << db->lastError().text().toStdString();
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
