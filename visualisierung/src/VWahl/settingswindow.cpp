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
    QList<QList<RecordObject>> objects;
    Logger::log << L_DEBUG << "Selected tab: " << ui->tabWidget->currentIndex() << "\n";

    switch(ui->tabWidget->currentIndex())
    {
    case 0: //Parteien
        objects.push_back(makePartyPlot());
        break;
    case 1: //Kandidaten
        objects.push_back(makeCandidatePlot());
        break;
    default:
        Logger::log << L_ERROR << "Unknown tab: " << ui->tabWidget->currentIndex() << "\n";
    }

    int year = VWahl::settings->value("database/year").toInt();
    Record r("Beschreibung",year,objects);
    Plots p(r,Q_NULLPTR,Plots::DIA_TYPE::BAR_GRAPH);
    //TO-DO: create plot
    presentationWindow->showPlot(p);
}

QList<RecordObject>& SettingsWindow::makePartyPlot()
{
    QList<RecordObject> objects;
    Logger::log << L_DEBUG << "Making plot for parties\n";
    for(QListWidgetItem *item : ui->partyList->selectedItems())
    {
        int index = QString(item->text().split(",").at(0)).toInt();
        Logger::log << L_DEBUG << "Selected party: " << index << "\n";
        for(Partei p : VWahl::db->getParties())
            if(p.getP_id() == index)
            {
                Logger::log  << L_DEBUG << "Description: " << p.getDescription() << "\n";
                int votes = VWahl::db->getVotesParty(p,VWahl::db->getPollingStations());
                Logger::log << L_DEBUG << "Votes: " << votes << "\n";
                RecordObject ro(p.getDescription(),votes,p.getColor());
                objects.push_back(ro);
            }
    }
    return objects;
}

QList<RecordObject>& SettingsWindow::makeCandidatePlot()
{
    QList<RecordObject> objects;
    Logger::log << L_DEBUG << "Making plot for candidates\n";
    for(QListWidgetItem *item : ui->candidatesList->selectedItems())
    {
        int index = QString(item->text().split(",").at(0)).toInt();
        Logger::log << L_DEBUG << "Selected candidate: " << index << "\n";
        for(Kandidat k : VWahl::db->getCandidates())
        {
            if(k.getId() == index)
            {
                Logger::log << L_DEBUG << "Description: " << k.getDescription() << "\n";
                int votes = VWahl::db->getVotesCandidate(k,VWahl::db->getPollingStations());
                Logger::log << L_DEBUG << "Votes: " << votes << "\n";
                RecordObject ro(k.getDescription(),votes,k.getColor());
                objects.push_back(ro);
            }
        }
    }
    return objects;
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
    //connect(ui->showButton,&QPushButton::pressed,this,&SettingsWindow::showPlot); //Direktkandidaten-Anzeige-Button
    //connect(ui->pushButton,&QPushButton::pressed,this,&SettingsWindow::showPlot); //Partein-Anzeige-Button

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
