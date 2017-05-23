#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H

#include "database.h"
#include "main.h"
#include "databasedialog.h"

#include <QMainWindow>
#include <QComboBox>

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



public slots:
    void on_actionDatabase_Settings_triggered();

private slots:
    void on_actionBeenden_triggered();

private:
    Ui::SettingsWindow *ui;
    DatabaseDialog *dbDialog;
};

#endif // SETTINGSWINDOW_H
