#ifndef PRESENTATIONWINDOW_H
#define PRESENTATIONWINDOW_H

#include <QMainWindow>
#include <QtCharts>
#include <QtCharts/QChartView>

#include "plots.h"

namespace Ui {
class PresentationWindow;
}

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
    ~PresentationWindow();

private:
    Ui::PresentationWindow *ui;
};

#endif // PRESENTATIONWINDOW_H
