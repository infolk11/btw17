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
    QErrorMessage error;
    QueryDialog *queryDialog;

};

#endif // SETTINGSWINDOW_H
