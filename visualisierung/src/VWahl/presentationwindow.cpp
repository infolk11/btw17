#include "presentationwindow.h"
#include "ui_presentationwindow.h"
#include "logger.h"

PresentationWindow::PresentationWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PresentationWindow)
{
    ui->setupUi(this);
}

QChartView *PresentationWindow::singleChart()
{
    return ui->oneChart;
}

QChartView *PresentationWindow::two_firstChart()
{
    return ui->chart2_1;
}

QChartView *PresentationWindow::two_secondChart()
{
    return ui->chart2_2;
}

void PresentationWindow::showPageForPlots(int plots)
{
    if(1 == plots)
        ui->superStack->setCurrentWidget(ui->oneChart);
    if(2 == plots)
        ui->superStack->setCurrentWidget(ui->twoCharts);
}


PresentationWindow::~PresentationWindow()
{
    delete ui;
}

void PresentationWindow::closeEvent(QCloseEvent *event)
{
     event->setAccepted(false);
}
