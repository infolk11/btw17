#ifndef PLOTS_H
#define PLOTS_H

#include "main.h"
#include "record.h"
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

    enum DIA_TYPE{ PIE_CHART, BAR_GRAPH, BAR_CHART};

    Plots() = default;
    Plots(Record& rec, QChartView* plot, DIA_TYPE tp) : record(rec), type(tp), customPlot(plot) {}

    auto getPlot() -> QWidget;
    void buildPlot();

    static DIA_TYPE getDiaType(QString name);
private:
    void buildPieChartPlot();
    void buildBarChartPlot(bool invertAxes=false);

    Record record;
    DIA_TYPE type;
    QChartView *customPlot;

};

//class VWwahlBars : public QCPBars
//{
//public:
//    VWwahlBars(QCPAxis* baseAxis, QCPAxis* valueAxis,QVector<QColor> cl) : QCPBars(baseAxis,valueAxis),colors(cl) {}
//    void setColors(QVector<QColor> colors);
//protected:
//    void draw(QCPPainter* painter) override;
//    QVector<QColor> colors;
//};

#endif // PLOTS_H
