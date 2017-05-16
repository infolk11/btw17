#include "settingswindow.h"
#include "ui_settingswindow.h"

SettingsWindow::SettingsWindow(PresentationWindow* p, QWidget *parent) :
    QMainWindow(parent), ui(new Ui::SettingsWindow), presentation(p)
{
    ui->setupUi(this);
    QObject::connect(this, SIGNAL(newPlot()), presentation, SLOT(makePlot(plots)));

}

SettingsWindow::~SettingsWindow()
{
    delete ui;
    delete presentation;
}
