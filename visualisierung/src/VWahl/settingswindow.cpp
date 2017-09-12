#include "settingswindow.h"
#include "ui_settingswindow.h"

SettingsWindow::SettingsWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SettingsWindow)
{
    ui->setupUi(this);
    init();
    buildConnects();
}

SettingsWindow::~SettingsWindow()
{
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
    Logger::log << L_INFO << "Plot changed" << "\n";
    Plots p;

    //TO-DO: create plot
    presentationWindow->showPlot(p);
}

void SettingsWindow::init()
{
    error = new QErrorMessage(this);
    presentationWindow = new PresentationWindow();
    presentationWindow->show();

    //set shortcuts
    ui->actionBeenden->setShortcut(Qt::CTRL + Qt::Key_Q);

    dbDialog = new DatabaseDialog(this);
    queryDialog = new QueryDialog(this);

    //it should be possible to select multiple items
    ui->partyList->setSelectionMode(QAbstractItemView::MultiSelection);
    ui->candidatesList->setSelectionMode(QAbstractItemView::MultiSelection);

    refreshData(VWahl::db);

}

void SettingsWindow::buildConnects()
{
    //signal and slot in new qt5 syntax
    connect(ui->actionBeenden, &QAction::triggered,
            this, &SettingsWindow::close);

    connect(ui->actionDatabaseSettings, &QAction::triggered,
            this->dbDialog, &DatabaseDialog::show);

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

void SettingsWindow::refreshData(Database *db)
{
    //Aktualisieren des Data-Caches
    db->updateData();


    //Einlesen des Caches
    ui->candidatesList->clear();
    for(Kandidat k : db->getCandidates())
        new QListWidgetItem(QStringLiteral("%1").arg(k.getId()) + ", " + k.getName() + " " + k.getLname(), ui->candidatesList);

    ui->partyList->clear();
    for(Partei p : db->getParties())
        new QListWidgetItem(QStringLiteral("%1").arg(p.getP_id()) + ", " + p.getDescription(), ui->partyList);
}



void SettingsWindow::closeEvent(QCloseEvent *event)
{
    Logger::log << L_DEBUG << "Close event triggered." << "\n";
    QMessageBox msgBox;
    msgBox.setText("Möchten Sie das Programm wirklich schließen?");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    int res = msgBox.exec();
    if(QMessageBox::Yes == res)
    {
        Logger::log << L_DEBUG << "User confirmed close event" << "\n";
        presentationWindow->close();
        event->accept();
    }
    else
    {
        Logger::log << L_DEBUG << "User canceled close event" << "\n";
        event->setAccepted(false);
    }
}
