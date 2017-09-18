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

    static void buildPlot(QChartView *chart, DIA_TYPE type, Record& record);
    void buildPlot(QChartView *chart);

    static void buildPlots(QList<Plots>& plots,PresentationWindow *window);

    static DIA_TYPE getDiaType(QString name);

private:
    void buildPieChartPlot(QChartView *chart);
    static void buildPieChartPlot(QChartView *chart, Record &record);

    void buildBarChartPlot(QChartView *chart);
    static void buildBarChartPlot(QChartView *chart, Record &record);

    void buildHorizontalBarChartPlot(QChartView *chartView);
    static void buildHorizontalBarChartPlot(QChartView *chartView,Record& record);

    static void filterObjects(QList<RecordObject>& full, QList<RecordObject>& filtered, int minPercent, int minInFull, int &ignoredVotes);

    Record record;
    DIA_TYPE type;

};



#endif // PLOTS_H
