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
    try
    {
        Logger::log << L_INFO << "Plot changed" << "\n";

        QList<Partei> partiesList;
        QList<Kandidat> candidatesList;

        QList<PollingStation> pollingStations = getSelectedPollingStations();
        QString description = ui->descriptionEdit->text();
        bool showOtherAlso = false;
        Plots::DIA_TYPE partiesDiaType;
        Plots::DIA_TYPE candidatesDiaType;
        Database db(*VWahl::db);

        switch(ui->tabWidget->currentIndex())
        {
        case 0: //Parteien
            partiesList= getSelectedParties();
            partiesDiaType = Plots::getDiaType(ui->plotTypeCombo->currentText());
            candidatesDiaType = Plots::getDiaType(ui->candidatesAlsoShownPlotType->currentText());
            showOtherAlso = ui->showCandidatesAlso->isChecked();
            break;
        case 1: //Kandidaten
            candidatesList = getSelectedCandidates();
            partiesDiaType = Plots::getDiaType(ui->partiesAlsoShownPlotTypeComboBox->currentText());
            candidatesDiaType = Plots::getDiaType(ui->plotTypeCombo->currentText());
            ui->showPartiesAlso->isChecked();
            break;
        default:
            Logger::log << L_ERROR << "Unknown tab: " << ui->tabWidget->currentIndex() << "\n";
            return;
        }

        plottingThread = new PlottingThread(partiesList,candidatesList,pollingStations,
                                            partiesDiaType,candidatesDiaType,ui->tabWidget->currentIndex(),
                                            description,showOtherAlso,db,this);
        QObject::connect(plottingThread,SIGNAL(resultReady(QList<Plots>)),this,SLOT(finishedPlotting(QList<Plots>)));

        presentationWindow->showLoadingScreen();
        plottingThread->start();
    }catch(VWahlException e)
    {
        Logger::log << L_ERROR << "Error while making new plot: " << e.what() << "\n";
        QMessageBox::warning(this,"Fehler!",e.what(),QMessageBox::Ok);
    }

}

QList<Partei> SettingsWindow::getSelectedParties()
{
    QList<Partei> result;
    if(ui->partyList->selectedItems().size() <=0)
        throw new VWahlException(QString("User requested empty party list"));

    for(QListWidgetItem *item : ui->partyList->selectedItems())
    {
        int index = QString(item->text().split(",").at(0)).toInt();

        if(index == VWahl::db->getIGNORED_PARTY())
            continue;
        Partei p = VWahl::db->getParty(index);
        result.push_back(p);
    }
    return result;
}

QList<Kandidat> SettingsWindow::getSelectedCandidates()
{
    QList<Kandidat> result;
    if(ui->candidatesList->selectedItems().size()<= 0)
        throw new VWahlException(QString("User requested empty candidates list"));

    for(QListWidgetItem *item : ui->candidatesList->selectedItems())
    {
        int index = QString(item->text().split(",").at(0)).toInt();
        Logger::log << L_DEBUG << "Selected candidate: " << index << "\n";

        //Description
        Kandidat k = VWahl::db->getCandidate(index);
        result.push_back(k);
    }
    return result;
}
void SettingsWindow::refreshSlot()
{
    refreshData(VWahl::db);
    QMessageBox::information(this,"Aktualisierung","Die Aktualisierung wurde abgeschlossen",QMessageBox::Ok);
}

void SettingsWindow::finishedPlotting(QList<Plots> plots)
{
    //Showing the new plot
    try {Plots::buildPlots(plots,presentationWindow);}catch(VWahlException e)
    {Logger::log << L_ERROR << e.what() << "\n";QMessageBox::warning(this,"Fehler!",e.what());}
}



QList<PollingStation> SettingsWindow::getSelectedPollingStations()
{
    if(ui->pollingStationList->selectedItems().size() <= 0)
        throw VWahlException(QString("No polling stations selected!"));

    QList<PollingStation> pollingStations;
    for(QListWidgetItem* item : ui->pollingStationList->selectedItems())
    {
        int id = QString(item->text().split(",").at(0)).toInt();
        pollingStations.push_back(VWahl::db->getPollingStation(id));
    }
    return pollingStations;
}

void SettingsWindow::init()
{
    error = new QErrorMessage(this);
    presentationWindow = new PresentationWindow(this);
    presentationWindow->show();

    //set shortcuts
    ui->actionBeenden->setShortcut(Qt::CTRL + Qt::Key_Q);

    dbDialog = new DatabaseDialog(this);
    queryDialog = new QueryDialog(this);

    //it should be possible to select multiple items
    ui->partyList->setSelectionMode(QAbstractItemView::MultiSelection);
    ui->candidatesList->setSelectionMode(QAbstractItemView::MultiSelection);
    ui->pollingStationList->setSelectionMode(QAbstractItemView::MultiSelection);


    //add chosing options for diagrams.
    ui->plotTypeCombo->addItem("Balkendiagramm");
    ui->plotTypeCombo->addItem("Kreisdiagramm");
    ui->plotTypeCombo->addItem("Säulendiagramm");

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

    connect(ui->alleWahllokaleAuswHlenCheckBox, &QCheckBox::stateChanged,
            [=] (const int state){
        if(state == Qt::Checked)
            ui->pollingStationList->selectAll();
        else
            ui->pollingStationList->clearSelection();
    });

    //Show plot, when showButton is pressed.
    connect(ui->showButton,&QPushButton::pressed,this,&SettingsWindow::showPlot);

    //refresh data with refresh button
    connect(ui->refreshButton,&QPushButton::pressed,this,&SettingsWindow::refreshSlot);

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

    ui->pollingStationList->clear();
    for(PollingStation p : db->getPollingStations())
        new QListWidgetItem(QStringLiteral("%1").arg(p.getId()) + ", " + p.getDescription(), ui->pollingStationList);
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
        event->accept();
    }
    else
    {
        Logger::log << L_DEBUG << "User canceled close event" << "\n";
        event->setAccepted(false);
    }
}


void PlottingThread::run()
{
    try
    {
        db.connect();
        QList<Plots> objects;
        Logger::log << L_DEBUG << "Making plot for parties\n";

        int all2Votes = db.getVotes2Count(pollingStations);
        int all1Votes = db.getVotes1Count(pollingStations);
        int year = VWahl::settings->value("database/year").toInt();

        switch(plotToMake)
        {
        case 0: //Parteien
            makePartyPlot(partiesList,candidatesList,pollingStations,partiesDiaType,candidatesDiaType,all2Votes,all1Votes);
            break;
        case 1: //Kandidaten
            makeCandidatePlot(partiesList,candidatesList,pollingStations,partiesDiaType,candidatesDiaType,all2Votes,all1Votes);
            break;
        default:
            Logger::log << L_ERROR << "Unknown tab: " << plotToMake << "\n";
        }

        QList<QList<RecordObject>> partiesRecordList;
        partiesRecordList.push_back(Partei::convertToRecordList(partiesList));
        Record partiesRecord(description,year,partiesRecordList);
        Plots partyPlot(partiesRecord,partiesDiaType);

        QList<QList<RecordObject>> candidatesRecordList;
        candidatesRecordList.push_back(Kandidat::convertToRecordList(candidatesList));
        Record candidatesRecord(description,year,candidatesRecordList);
        Plots candidatePlot(candidatesRecord,candidatesDiaType);

        if(partiesList.size()>0)
            objects.push_back(partyPlot);

        if(candidatesList.size()>0)
            objects.push_back(candidatePlot);

        emit resultReady(objects);

    }catch(VWahlException e)
    {
        Logger::log << L_ERROR << "Error while creating the new plot: " << e.what() << "\n";
        QMessageBox::warning(Q_NULLPTR,"Fehler!",e.what(),QMessageBox::Ok);
    }

}

PlottingThread::~PlottingThread()
{
    db.close();
}

void PlottingThread::makeCandidatePlot(QList<Partei> &partiesList, QList<Kandidat> &candidatesList, QList<PollingStation>& pollingStations,Plots::DIA_TYPE &partiesDiaType, Plots::DIA_TYPE &candidatesDiaType, int all2votes, int all1votes)
{
    Logger::log << L_DEBUG << "Making plot for candidates\n";

    try
    {

        for(int i = 0; i < candidatesList.size(); ++i)
        {
            Kandidat k = candidatesList[i];

            Logger::log  << L_DEBUG << "Description: " << k.getDescription() << "\n";

            //Votes
            double rawVotes = db.getVotesCandidate(k,pollingStations);
            double votes = (rawVotes/ (double)all1votes) *100.0;
            Logger::log << L_DEBUG << "Votes: " << votes << "\n";
            candidatesList[i].setVotes(votes);

            //Party
            if(showOtherAlso)
            {
                Partei p;
                try { p = db.getPartyForCandidate(k); }
                catch(VWahlException e){Logger::log << L_WARN << e.what() << "\n";continue;}

                double p_rawVotes = db.getVotesParty(p,pollingStations);
                double p_votes = (p_rawVotes / (double)all2votes) * 100.0;
                p.setVotes(p_votes);
                partiesList.push_back(p);
            }
        }

    }catch(VWahlException e)
    {
        throw e;
    }
}

void PlottingThread::makePartyPlot(QList<Partei>& partiesList,QList<Kandidat>&candidatesList,QList<PollingStation>& pollingStations,
                                   Plots::DIA_TYPE& partiesDiaType,Plots::DIA_TYPE& candidatesDiaType, int all2votes, int all1votes)
{
    try
    {


        for(int i=0; i< partiesList.size(); ++i)
        {
            Partei p = partiesList[i];
            if(p.getP_id() == db.getIGNORED_PARTY())
                continue;

            Logger::log  << L_DEBUG << "Description: " << p.getDescription() << "\n";

            //Votes
            double rawVotes = db.getVotesParty(p,pollingStations);
            double votes = (rawVotes / (double)all2votes) * 100.0;
            Logger::log << L_DEBUG << "Votes: " << votes << "\n";
            partiesList[i].setVotes(votes);

            //Candidate
            if(showOtherAlso)
            {
                Kandidat k;
                try { k = db.getCandidateForParty(p); }
                catch(VWahlException e){Logger::log << L_WARN << e.what() << "\n";continue;}

                int k_rawVotes = db.getVotesCandidate(k,pollingStations);
                double k_votes = ( (double)k_rawVotes / all1votes) *100.0;
                k.setVotes(k_votes);
                Logger::log << L_DEBUG << "Also showing candidate " << k.getDescription() << " with " << k_votes << " votes.\n";
                candidatesList.push_back(k);
            }
        }

    }catch(VWahlException e)
    {
        throw e;
    }
}
