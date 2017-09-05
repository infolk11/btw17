#include "presentationwindow.h"
#include "ui_presentationwindow.h"
#include "logger.h"

PresentationWindow::PresentationWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PresentationWindow)
{
    ui->setupUi(this);
}

void PresentationWindow::showPlot(Plots p)
{
    //Will later show the plot
    Logger::log << L_INFO << "Showing the new plot." << "\n";
}

PresentationWindow::~PresentationWindow()
{
    delete ui;
}
