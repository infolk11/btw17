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
     * fetches the actual data from the database
     *
     * @brief fetchDatabaseValues
     * @return EXIT_SUCCESS if changes were made, EXIT_FAILURE if not
     */
    auto fetchDatabaseValues() -> int;

protected:
    void closeEvent(QCloseEvent *event);
};

#endif // SETTINGSWINDOW_H
