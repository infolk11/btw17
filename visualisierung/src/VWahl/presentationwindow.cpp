#include "presentationwindow.h"
#include "ui_presentationwindow.h"

PresentationWindow::PresentationWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PresentationWindow)
{
    ui->setupUi(this);
}

void PresentationWindow::showPlot(Plots p)
{
    //Will later show the plot
}

PresentationWindow::~PresentationWindow()
{
    delete ui;
}
