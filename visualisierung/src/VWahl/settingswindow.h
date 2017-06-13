#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H

#include "database.h"
#include "main.h"
#include "databasedialog.h"

#include <QMainWindow>
#include <QErrorMessage>
#include <QListWidget>
#include <QListWidgetItem>
#include <QCheckBox>
#include <QSignalMapper>
#include <QAction>

class Database;
class DatabaseDialog;
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
    QSignalMapper *signalMapper;

};

#endif // SETTINGSWINDOW_H
