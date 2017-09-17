#ifndef PRESENTATIONWINDOW_H
#define PRESENTATIONWINDOW_H

#include <QMainWindow>
#include <QCloseEvent>
#include <QtCharts>
#include <QtCharts/QChartView>


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

protected:
    void closeEvent(QCloseEvent* event);
};

#endif // PRESENTATIONWINDOW_H
