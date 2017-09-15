#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H

#include "database.h"
#include "main.h"
#include "databasedialog.h"
#include "querydialog.h"

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

class Database;
class DatabaseDialog;
class QueryDialog;

namespace Ui {
class SettingsWindow;
}

class PresentationWindow;
class Plots;
class Record;
class SettingsWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SettingsWindow(QWidget *parent = 0);
    ~SettingsWindow();
public slots:
    void showPlot();
    void refreshSlot();
private:
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

   void makePartyPlot(QList<QList<RecordObject>>& objects);
    QList<RecordObject>& makeCandidatePlot();


protected:
    void closeEvent(QCloseEvent *event);


};

#endif // SETTINGSWINDOW_H
