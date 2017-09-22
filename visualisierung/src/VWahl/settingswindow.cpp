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
    QList<Plots> plots;

    makePlot(plots);

    //Showing the new plot
    try {Plots::buildPlots(plots,presentationWindow);}catch(VWahlException e)
    {Logger::log << L_ERROR << e.what() << "\n";QMessageBox::warning(this,"Fehler!",e.what());}

}

void SettingsWindow::refreshSlot()
{
    refreshData(VWahl::db);
    QMessageBox::information(this,"Aktualisierung","Die Aktualisierung wurde abgeschlossen",QMessageBox::Ok);
}

void SettingsWindow::makePartyPlot(QList<RecordObject>& partiesList,QList<RecordObject>&candidatesList,QList<PollingStation>& pollingStations,
                                   Plots::DIA_TYPE& partiesDiaType,Plots::DIA_TYPE& candidatesDiaType, int all2votes, int all1votes)
{
    if(ui->partyList->selectedItems().size()<= 0)
    {
        throw VWahlException(QString("User requested plot for no parties!"));
    }
    try
    {
        partiesDiaType = Plots::getDiaType(ui->plotTypeCombo->currentText());
        candidatesDiaType = Plots::getDiaType(ui->candidatesAlsoShownPlotType->currentText());

        for(QListWidgetItem *item : ui->partyList->selectedItems())
        {
            int index = QString(item->text().split(",").at(0)).toInt();
            Logger::log << L_DEBUG << "Selected party: " << index << "\n";

            if(index == VWahl::db->getIGNORED_PARTY())
                continue;

            //Description
            Partei p = VWahl::db->getParty(index);
            Logger::log  << L_DEBUG << "Description: " << p.getDescription() << "\n";

            //Votes
            double rawVotes = VWahl::db->getVotesParty(p,getSelectedPollingStations());
            int votes = (rawVotes / all2votes * 1.0) * 100;
            Logger::log << L_DEBUG << "Votes: " << votes << "\n";

            //Construction
            RecordObject ro(p.getDescription(),votes,p.getColor());
            partiesList.push_back(ro);

            //Candidate
            if(ui->showCandidatesAlso->isChecked())
            {
                Kandidat k;
                try { k = VWahl::db->getCandidateForParty(p); }
                catch(VWahlException e){Logger::log << L_WARN << e.what() << "\n";continue;}

                double k_rawVotes = VWahl::db->getVotesCandidate(k,pollingStations);
                int k_votes = (k_rawVotes / all1votes) *100;
                RecordObject k_ro(k.getDescription(),k_votes, k.getColor());
                Logger::log << L_DEBUG << "Also showing candidate " << k.getDescription() << " with " << k_votes << " votes.\n";
                candidatesList.push_back(k_ro);
            }
        }

    }catch(VWahlException e)
    {
        throw e;
    }
}

void SettingsWindow::makePlot(QList<Plots> &objects)
{
    try
    {
        Logger::log << L_DEBUG << "Making plot for parties\n";

        QList<RecordObject> partiesList;
        QList<RecordObject> candidatesList;

        QList<PollingStation> pollingStations = getSelectedPollingStations();
        int all2Votes = VWahl::db->getVotes2Count(pollingStations);
        int all1Votes = VWahl::db->getVotes1Count(pollingStations);
        int year = VWahl::settings->value("database/year").toInt();
        QString description = ui->descriptionEdit->text();
        Plots::DIA_TYPE partiesDiaType;
        Plots::DIA_TYPE candidatesDiaType;

        switch(ui->tabWidget->currentIndex())
        {
        case 0: //Parteien
            makePartyPlot(partiesList,candidatesList,pollingStations,partiesDiaType,candidatesDiaType,all2Votes,all1Votes);
            break;
        case 1: //Kandidaten
            makeCandidatePlot(partiesList,candidatesList,pollingStations,partiesDiaType,candidatesDiaType,all2Votes,all1Votes);
            break;
        default:
            Logger::log << L_ERROR << "Unknown tab: " << ui->tabWidget->currentIndex() << "\n";
        }

        QList<QList<RecordObject>> partiesRecordList;
        partiesRecordList.push_back(partiesList);
        Record partiesRecord(description,year,partiesRecordList);
        Plots partyPlot(partiesRecord,presentationWindow,partiesDiaType);

        QList<QList<RecordObject>> candidatesRecordList;
        candidatesRecordList.push_back(candidatesList);
        Record candidatesRecord(description,year,candidatesRecordList);
        Plots candidatePlot(candidatesRecord,presentationWindow,candidatesDiaType);

        if(partiesList.size()>0)
            objects.push_back(partyPlot);

        if(candidatesList.size()>0)
            objects.push_back(candidatePlot);

    }catch(VWahlException e)
    {
        Logger::log << L_ERROR << "Error while creating the new plot: " << e.what() << "\n";
        QMessageBox::warning(this,"Fehler!",e.what(),QMessageBox::Ok);
    }
}

void SettingsWindow::makeCandidatePlot(QList<RecordObject> &partiesList, QList<RecordObject> &candidatesList, QList<PollingStation>& pollingStations,Plots::DIA_TYPE &partiesDiaType, Plots::DIA_TYPE &candidatesDiaType, int all2votes, int all1votes)
{
    Logger::log << L_DEBUG << "Making plot for candidates\n";

    if(ui->candidatesList->selectedItems().size()<= 0)
        throw VWahlException(QString("User requested plot for no candidates!\n"));

    try
    {
        partiesDiaType = Plots::getDiaType(ui->partiesAlsoShownPlotTypeComboBox->currentText());
        candidatesDiaType = Plots::getDiaType(ui->plotTypeCombo->currentText());


        for(QListWidgetItem *item : ui->candidatesList->selectedItems())
        {
            int index = QString(item->text().split(",").at(0)).toInt();
            Logger::log << L_DEBUG << "Selected candidate: " << index << "\n";

            //Description
            Kandidat k = VWahl::db->getCandidate(index);
            Logger::log  << L_DEBUG << "Description: " << k.getDescription() << "\n";

            //Votes
            double rawVotes = VWahl::db->getVotesCandidate(k,getSelectedPollingStations());
            int votes = (rawVotes/ all1votes) *100;
            Logger::log << L_DEBUG << "Votes: " << votes << "\n";

            //Construction
            RecordObject ro(k.getDescription(),votes,k.getColor());
            candidatesList.push_back(ro);

            //Party
            if(ui->showPartiesAlso->isChecked())
            {
                Partei p;
                try { p = VWahl::db->getPartyForCandidate(k); }
                catch(VWahlException e){Logger::log << L_WARN << e.what() << "\n";continue;}

                double p_rawVotes = VWahl::db->getVotesParty(p,pollingStations);
                int p_votes = (p_rawVotes / all2votes) * 100;
                RecordObject p_ro(p.getDescription(),p_votes, p.getColor());
                partiesList.push_back(p_ro);
            }
        }

    }catch(VWahlException e)
    {
        Logger::log << L_ERROR << "Error while making candidates plot: " << e.what() << "\n";
        QMessageBox::warning(this,"Fehler!",e.what(),QMessageBox::Ok);
    }
}

QList<PollingStation> SettingsWindow::getSelectedPollingStations()
{
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
