#include "presentationwindow.h"
#include "ui_presentationwindow.h"
//to do #include "logger.h"

PresentationWindow::PresentationWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PresentationWindow)
{
    ui->setupUi(this);
}

void PresentationWindow::showPlot(Plots p)
{
    //Will later show the plot
    //to do Logger::log << L_INFO << "Showing the new plot.";
}

PresentationWindow::~PresentationWindow()
{
    delete ui;
}
