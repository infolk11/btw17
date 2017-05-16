#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H

#include <QMainWindow>

#include "presentationwindow.h"

namespace Ui {
class SettingsWindow;
}

class SettingsWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SettingsWindow(PresentationWindow* p, QWidget *parent = 0);
    ~SettingsWindow();

private:
    Ui::SettingsWindow *ui;
    PresentationWindow* presentation;

    //Data
    Plots plots;
signals:
    void newPlot();
};

#endif // SETTINGSWINDOW_H
