#ifndef PLOTS_H
#define PLOTS_H

#include "main.h"
#include "record.h"
#include "presentationwindow.h"

#include <QtCharts>
#include <QtCharts/QChartView>

#include <QWidget>

#define BRUSH_LIGHTING 150



/**
 * Renders the plots
 *
 * @brief The Plots class
 */
class Plots
{
public:

    enum DIA_TYPE{ PIE_CHART, BAR_GRAPH, BAR_CHART, ONE_PLOT};

    Plots() = default;
    Plots(Record& rec, PresentationWindow* pw, DIA_TYPE tp) : record(rec), type(tp) {}

    void buildPlot(QChartView *chart);
    static void buildPlots(QList<Plots>& plots,PresentationWindow *window);

    static DIA_TYPE getDiaType(QString name);
private:
    void buildPieChartPlot(QChartView *chart);
    void buildBarChartPlot(QChartView *chart);
    void buildHorizontalBarChartPlot(QChartView *chartView);

    Record record;
    DIA_TYPE type;

};



#endif // PLOTS_H
