#ifndef PRESENTATIONWINDOW_H
#define PRESENTATIONWINDOW_H

#include <QFrame>

#include "plots.h"

namespace Ui {
class PresentationWindow;
}

class PresentationWindow : public QFrame
{
    Q_OBJECT

public:
    explicit PresentationWindow(QWidget *parent = 0);
    ~PresentationWindow();

public slots:
    void makePlot(Plots p);
private:
    Ui::PresentationWindow *ui;
};

#endif // PRESENTATIONWINDOW_H
