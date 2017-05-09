#ifndef PRESENTATIONWINDOW_H
#define PRESENTATIONWINDOW_H

#include <QMainWindow>

#include "qcustomplot.h"
#include <plots.h>

/**
 * Will be displaying the plots in fullscreen on a second screen
 *
 * @brief The PresentationWindow class
 */
class PresentationWindow : public QMainWindow
{
public:
    PresentationWindow();

private:
    QCustomPlot *plot;
};

#endif // PRESENTATIONWINDOW_H
