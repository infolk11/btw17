#ifndef PLOTS_H
#define PLOTS_H

#include "record.h"
#include "qcustomplot.h"
#include <QWidget>

/**
 * Renders the plots
 *
 * @brief The Plots class
 */
class Plots
{
public:

    enum DIA_TYPE{ PIE_CHART, BAR_GRAPH};

    Plots() = default;
    Plots(Record& rec, QCustomPlot* plot, DIA_TYPE tp) : record(rec), type(tp), customPlot(plot) {buildPlot();}

    auto getPlot() -> QWidget;

private:
    void buildPlot();
    void buildPieChartPlot();
    void buildBarGraphPlot();
    Record record;
    DIA_TYPE type;
    QCustomPlot *customPlot;

};

#endif // PLOTS_H
