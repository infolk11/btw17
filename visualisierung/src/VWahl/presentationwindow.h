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
    void showPlot(Plots p);
    QChartView* getCustomPlot();
    ~PresentationWindow();

private:
    Ui::PresentationWindow *ui;
};

#endif // PRESENTATIONWINDOW_H
