#ifndef PLOTS_H
#define PLOTS_H

#include "main.h"
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

    enum DIA_TYPE{ PIE_CHART, BAR_GRAPH, BAR_CHART};

    Plots() = default;
    Plots(Record& rec, QCustomPlot* plot, DIA_TYPE tp) : record(rec), type(tp), customPlot(plot) {}

    auto getPlot() -> QWidget;
    void buildPlot();

    static DIA_TYPE getDiaType(QString name);
private:
    void buildPieChartPlot();
    void buildBarGraphPlot();
    void buildBarChartPlot();

    Record record;
    DIA_TYPE type;
    QCustomPlot *customPlot;

};

#endif // PLOTS_H
