#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H

#include "plots.h"
#include "database.h"
#include "main.h"
#include "databasedialog.h"
#include "querydialog.h"
#include "pollingstation.h"

#include <QMainWindow>
#include <QErrorMessage>
#include <QListWidget>
#include <QListWidgetItem>
#include <QCheckBox>
#include <QSignalMapper>
#include <QAction>
#include <QKeySequence>
#include <QCloseEvent>
#include <QMessageBox>
#include <QThread>

class Database;
class DatabaseDialog;
class QueryDialog;

namespace Ui {
class SettingsWindow;
}

class PresentationWindow;
class Plots;
class Record;
class PlottingThread;
class SettingsWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SettingsWindow(QWidget *parent = 0);
    ~SettingsWindow();
public slots:
    void showPlot();
    void refreshSlot();
    void finishedPlotting(QList<Plots> plots);
private:
    PlottingThread *plottingThread;
    Ui::SettingsWindow *ui;
    PresentationWindow *presentationWindow;
    DatabaseDialog *dbDialog;
    QErrorMessage* error;
    QSignalMapper *signalMapper;
    QueryDialog *queryDialog;


    /**
     * Initializes the used pointers and builds up the general class structure
     *
     * @brief init
     */
    auto init() -> void;

    /**
     * Sets up the signals and slots structure
     *
     * @brief buildConnects
     */
    auto buildConnects() -> void;

    /**
     * Refreshes the data-cache
     *
     * @brief refreshData
     * @param db
     */
    void refreshData(Database *db);

    QList<PollingStation> getSelectedPollingStations();


    QList<Partei> getSelectedParties();
    QList<Kandidat> getSelectedCandidates();
protected:
    void closeEvent(QCloseEvent *event);


};

class PlottingThread : public QThread
{
    Q_OBJECT

public:
    explicit PlottingThread(QList<Partei>& pL,QList<Kandidat>&cL,QList<PollingStation>& polL,
                   Plots::DIA_TYPE& pdt,Plots::DIA_TYPE& cdt, int ptm, QString desc, bool soa, Database d,QObject* parent) : partiesList(pL),candidatesList(cL),
        pollingStations(polL),partiesDiaType(pdt),candidatesDiaType(cdt),plotToMake(ptm),description(desc),showOtherAlso(soa),
      db(d),QThread(parent) {}
    void run();
    ~PlottingThread();

signals:
    void resultReady(QList<Plots> plots);
private:
    Database db;
    QList<Partei> partiesList;
    QList<Kandidat> candidatesList;
    QList<PollingStation> pollingStations;
    Plots::DIA_TYPE partiesDiaType;
    Plots::DIA_TYPE candidatesDiaType;
    int plotToMake;
    QString description;
    bool showOtherAlso;
    void makeCandidatePlot(QList<Partei> &partiesList, QList<Kandidat> &candidatesList, QList<PollingStation> &pollingStations, Plots::DIA_TYPE &partiesDiaType, Plots::DIA_TYPE &candidatesDiaType, int all2votes, int all1votes);
    void makePartyPlot(QList<Partei> &partiesList, QList<Kandidat> &candidatesList, QList<PollingStation> &pollingStations, Plots::DIA_TYPE &partiesDiaType, Plots::DIA_TYPE &candidatesDiaType, int all2votes, int all1votes);
};


#endif // SETTINGSWINDOW_H
