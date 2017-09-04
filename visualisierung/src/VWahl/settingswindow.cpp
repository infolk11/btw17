#include "settingswindow.h"
#include "ui_settingswindow.h"

SettingsWindow::SettingsWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SettingsWindow)
{
    ui->setupUi(this);
    init();
    buildConnects();
    fetchDatabaseValues();
}

SettingsWindow::~SettingsWindow()
{
    delete db;
    delete ui;
    delete presentationWindow;
}

/**
 * Shows the plot
 *
 * @brief SettingsWindow::showPlot
 */
void SettingsWindow::showPlot()
{
    Logger::log() << L_INFO << "Plot changed" << "\n";
    Plots p;
    presentationWindow->showPlot(p);
}

void SettingsWindow::init()
{
    db = new Database("wahl17");
    error = new QErrorMessage(this);
    presentationWindow = new PresentationWindow();
    presentationWindow->show();
    db->initByDatabaseSettings();

    //set shortcuts
    ui->actionBeenden->setShortcut(Qt::CTRL + Qt::Key_Q);

    //Open database connections
    if(db->connect() != EXIT_SUCCESS)
    {
        error->showMessage(db->lastError().text());
        Logger::log() << L_ERROR << db->lastError().text().toStdString() << "\n";
    } else
         Logger::log() << L_INFO << "opened Database!" << "\n";

    dbDialog = new DatabaseDialog(this);
    queryDialog = new QueryDialog(this);

    //it should be possible to select multiple items
    ui->partyList->setSelectionMode(QAbstractItemView::MultiSelection);
    ui->candidatesList->setSelectionMode(QAbstractItemView::MultiSelection);

}

void SettingsWindow::buildConnects()
{
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
                Logger::log() << L_ERROR << q.lastError().text().toStdString() << "\n";
                error->showMessage(q.lastError().text());
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
                Logger::log() << L_ERROR << q.lastError().text().toStdString() << "\n";
                error->showMessage(q.lastError().text());
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

    //Show plot, when showButton is pressed.
    connect(ui->showButton,&QPushButton::pressed,this,&SettingsWindow::showPlot);

    connect(ui->actionquerys, &QAction::triggered,
            queryDialog, &QueryDialog::show);
}

int SettingsWindow::fetchDatabaseValues()
{
    //Only run, if database connection is established
    if(db->isOpen()){

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
        Logger::log() << L_WARN << "Database connection not established, no changes made." << "\n";
        return EXIT_FAILURE;
    }
    Logger::log() << L_INFO << "The data have been succesfully fetched from the database." << "\n";
    return EXIT_SUCCESS;
}

void SettingsWindow::closeEvent(QCloseEvent *event)
{
    Logger::log() << L_DEBUG << "Close event triggered." << "\n";
    QMessageBox msgBox;
    msgBox.setText("Möchten Sie das Programm wirklich schließen?");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    int res = msgBox.exec();
    if(QMessageBox::Yes == res)
    {
        Logger::log() << L_DEBUG << "User confirmed close event" << "\n";
        presentationWindow->close();
        event->accept();
    }
    else
    {
        Logger::log() << L_DEBUG << "User canceled close event" << "\n";
        event->setAccepted(false);
    }
}
