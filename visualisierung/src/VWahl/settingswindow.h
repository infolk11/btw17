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

class Database;
class DatabaseDialog;
class QueryDialog;
//class SettingsWindow;

namespace Ui {
class SettingsWindow;
}

class SettingsWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SettingsWindow(QWidget *parent = 0);
    ~SettingsWindow();

    Database *db;

private:
    Ui::SettingsWindow *ui;
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
};

#endif // SETTINGSWINDOW_H
