#ifndef PRESENTATIONWINDOW_H
#define PRESENTATIONWINDOW_H

#include <QMainWindow>

#include "plots.h"
#include "qcustomplot.h"

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
    ~PresentationWindow();

private:
    Ui::PresentationWindow *ui;
};

#endif // PRESENTATIONWINDOW_H
