#ifndef DATABASEDIALOG_H
#define DATABASEDIALOG_H

#include "settingswindow.h"

#include <QDialog>
#include <QLineEdit>


//class SettingsWindow;
//class DatabaseDialog;

namespace Ui {
class DatabaseDialog;
}

class DatabaseDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DatabaseDialog(QWidget *parent = 0);
    ~DatabaseDialog();

private slots:
    void on_acceptButton_clicked();

private:
    Ui::DatabaseDialog *ui;
};

#endif // DATABASEDIALOG_H
