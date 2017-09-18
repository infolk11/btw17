#include "plots.h"

#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCharts>

Plots::DIA_TYPE Plots::getDiaType(QString name)
{
    if(name == "Balkendiagramm")
        return DIA_TYPE::BAR_GRAPH;
    if(name == "Säulendiagramm")
        return DIA_TYPE::BAR_CHART;
    if(name == "Kreisdiagramm")
        return DIA_TYPE::PIE_CHART;
    if(name == "Ein Diagramm")
        return DIA_TYPE::ONE_PLOT;
    throw VWahlException("Specified dia type " + name + " not known");
}

void Plots::buildPieChartPlot(QChartView *chart)
{
    buildPieChartPlot(chart,record);
}

void Plots::buildPlot(QChartView *chart, DIA_TYPE ty, Record &record)
{
    if(ty == DIA_TYPE::BAR_GRAPH)
    {
        buildHorizontalBarChartPlot(chart,record);
        return;
    }

    if(ty == DIA_TYPE::BAR_CHART)
    {
        buildBarChartPlot(chart,record);
        return;
    }
    if(ty == DIA_TYPE::PIE_CHART)
    {
        buildPieChartPlot(chart,record);
        return;
    }
    throw PlottingException(QString("Chosen dia type actually not supported!"));
}

void Plots::buildPlot(QChartView *chart)
{
    buildPlot(chart,type,record);
}

void Plots::buildPlots(QList<Plots> &plots, PresentationWindow *window)
{
        int plotsSize = plots.size();
        if(1 > plotsSize || 2 < plotsSize)
            throw PlottingException(QString("Invalid plots size: " + plotsSize));
        if(1 == plotsSize)
        {
            window->showPageForPlots(1);
            plots[0].buildPlot(window->singleChart());
        }
        if(2 == plotsSize)
        {
            window->showPageForPlots(2);
            plots[0].buildPlot(window->two_firstChart());
            plots[1].buildPlot(window->two_secondChart());
        }
}

void Plots::buildPieChartPlot(QChartView *chartView,Record& record)
{

    QPieSeries *series = new QPieSeries();
    for(QList<RecordObject> objects : record.getObjects())
    {
        for(RecordObject ro : objects)
        {
            QPieSlice *slice = new QPieSlice(ro.getDescription(),ro.getVotes());
            slice->setPen(ro.getColor());
            slice->setBrush(ro.getColor().lighter(150));
            slice->setLabelVisible(true);
            series->append(slice);
        }
    }

    QChart *chart = new QChart();
    chart->setAnimationOptions(QChart::SeriesAnimations);
    chart->addSeries(series);
    chart->setTitle(record.getElection());
    chart->legend()->hide();
    chartView->setChart(chart);
    chartView->repaint();
}

void Plots::buildBarChartPlot(QChartView *chart)
{
    buildBarChartPlot(chart,record);
}

void Plots::buildBarChartPlot(QChartView *chartView, Record& record)
{
    QBarSeries *series = new QBarSeries();
    QStringList desc;
    for(QList<RecordObject> objects : record.getObjects())
    {
        for(RecordObject ro : objects)
        {
            QBarSet *set = new QBarSet(ro.getDescription());
            desc << ro.getDescription();

            *set << ro.getVotes();
            set->setPen(ro.getColor());
            set->setBrush(ro.getColor().lighter(BRUSH_LIGHTING));

            series->append(set);
        }
    }

    QChart* chart = new QChart();
    chart->addSeries(series);
    chart->setTitle(record.getElection());
    chart->setAnimationOptions(QChart::SeriesAnimations);
    QBarCategoryAxis *axis = new QBarCategoryAxis();
    chart->createDefaultAxes();

    chart->setAxisX(axis,series);

    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    chartView->setChart(chart);
    chartView->repaint();

}

void Plots::buildHorizontalBarChartPlot(QChartView *chartView)
{
    buildHorizontalBarChartPlot(chartView,record);
}

void Plots::buildHorizontalBarChartPlot(QChartView *chartView,Record& record)
{

    QHorizontalBarSeries *series = new QHorizontalBarSeries();
    QStringList desc;
    for(QList<RecordObject> objects : record.getObjects())
    {
        for(RecordObject ro : objects)
        {
            QBarSet *set = new QBarSet(ro.getDescription());
            desc << ro.getDescription();

            *set << ro.getVotes();
            set->setPen(ro.getColor());
            set->setBrush(ro.getColor().lighter(BRUSH_LIGHTING));

            series->append(set);
        }
    }
    QChart* chart = new QChart();
    chart->addSeries(series);
    chart->setTitle(record.getElection());
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QBarCategoryAxis *axisY = new QBarCategoryAxis();
    chart->setAxisY(axisY,series);

    QValueAxis *axisX = new QValueAxis();
    chart->setAxisX(axisX,series);
    axisX->applyNiceNumbers();


    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    chartView->setChart(chart);
    chartView->repaint();
}

