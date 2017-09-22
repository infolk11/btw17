#ifndef PRESENTATIONWINDOW_H
#define PRESENTATIONWINDOW_H

#include <QMainWindow>
#include <QCloseEvent>
#include <QtCharts>
#include <QtCharts/QChartView>
#include <QImage>
#include <QtGui/QMovie>
#include <qmediaplayer.h>

#include "main.h"


namespace Ui {
class PresentationWindow;
}

class QUrl;
class Plots;
class PresentationWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit PresentationWindow(QWidget *parent = 0);
    QChartView *singleChart();
    QChartView *two_firstChart();
    QChartView *two_secondChart();
    void showPageForPlots(int plots);
    void showLoadingScreen();
    ~PresentationWindow();

private:
    Ui::PresentationWindow *ui;
    void init();

    QImage welcomeImage;
    QMediaPlayer mediaPlayer;
    QUrl loadingSreenUrl;
private slots:
    void repeatLoadingScreenLoop();

protected:
    void closeEvent(QCloseEvent* event);
};

#endif // PRESENTATIONWINDOW_H
