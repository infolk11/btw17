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
    throw VWahlException("Specified dia type " + name + " not known");
}

void Plots::buildPlot()
{
    if(type == DIA_TYPE::BAR_GRAPH)
    {
        buildHorizontalBarChartPlot();
        return;
    }

    if(type == DIA_TYPE::BAR_CHART)
    {
        buildBarChartPlot();
        return;
    }
    if(type == DIA_TYPE::PIE_CHART)
    {
        buildPieChartPlot();
        return;
    }
    throw PlottingException(QString("Chosen dia type actually not supported!"));
}

void Plots::buildPieChartPlot()
{
    //Determine group size. Must be always the same!
    int groupSize = record.getObjects().at(0).size();
    if(groupSize != 1)
        throw PlottingException(QString("Pie charts only support one dimensional data"));

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
    chart->legend()->show();
    customPlot->setChart(chart);
    customPlot->repaint();
}

void Plots::buildBarChartPlot()
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

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle(record.getElection());
    chart->setAnimationOptions(QChart::SeriesAnimations);
    QBarCategoryAxis *axis = new QBarCategoryAxis();
    chart->createDefaultAxes();

    chart->setAxisX(axis,series);

    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    customPlot->setChart(chart);
    customPlot->repaint();

}

void Plots::buildHorizontalBarChartPlot()
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

    QChart *chart = new QChart();
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

    customPlot->setChart(chart);
    customPlot->repaint();
}

