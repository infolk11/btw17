#ifndef QUERYDIALOG_H
#define QUERYDIALOG_H

#include "main.h"

#include <QDialog>
#include <QSettings>
#include <QStringList>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QVector>

namespace Ui {
class QueryDialog;
}

class QueryDialog : public QDialog
{
    Q_OBJECT

public:
    explicit QueryDialog(QWidget *parent = 0);
    ~QueryDialog();
    void addItem();
    void writeBasicItemsToSettings();

private:
    Ui::QueryDialog *ui;
    void init();
    QVector <QVector <QTableWidgetItem *> > items;
};

#endif // QUERYDIALOG_H
