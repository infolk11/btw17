#include "presentationwindow.h"
#include "ui_presentationwindow.h"
#include "logger.h"
#include <QPixmap>


PresentationWindow::PresentationWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PresentationWindow)
{
    ui->setupUi(this);
    init();
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

void PresentationWindow::showLoadingScreen()
{
    ui->superStack->setCurrentWidget(ui->loadingPage);
}


PresentationWindow::~PresentationWindow()
{
    delete ui;
}

void PresentationWindow::init()
{
    //welcome Image
    QString welcomeImagepath = VWahl::settings->value("gfx/welcomeImagePath").toString();
    QImageReader reader(welcomeImagepath);
    reader.setAutoTransform(true);
    welcomeImage = reader.read();
    if(welcomeImage.isNull())
    {
        QMessageBox::warning(this,"Fehler!","Das Willkommensbild konnte nicht gefunden werden.",QMessageBox::Ok);
        Logger::log << L_ERROR << welcomeImagepath << " couldn't be found.\n";
    }
    ui->welcomeImageLabel->setPixmap(QPixmap::fromImage(welcomeImage));
    ui->welcomeImageLabel->adjustSize();
    ui->centralwidget->setStyleSheet("background-color:white;");

    //loading screen
    QString loadingSreenPath = VWahl::settings->value("gfx/loadingScreenPath").toString();
    loadingScreenMovie = new QMovie(loadingSreenPath);
    if(!loadingScreenMovie->isValid())
    {
        QMessageBox::warning(this,"Fehler!","Der Ladebildschirm konnte nicht gefunden werden.",QMessageBox::Ok);
        Logger::log << L_ERROR << loadingSreenPath << " couldn't be found.\n";
    }
    ui->loadingLabel->setAlignment(Qt::AlignCenter);
    ui->loadingLabel->setMovie(loadingScreenMovie);
    ui->loadingLabel->adjustSize();
    QObject::connect(loadingScreenMovie,&QMovie::finished,this,&PresentationWindow::repeatLoadingScreenLoop);
    loadingScreenMovie->start();

}

void PresentationWindow::repeatLoadingScreenLoop()
{
    loadingScreenMovie->start();
}

void PresentationWindow::closeEvent(QCloseEvent *event)
{
    event->setAccepted(false);
}
