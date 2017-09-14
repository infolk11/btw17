#include "plots.h"

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
        buildBarGraphPlot();
        return;
    }
    if(type == DIA_TYPE::PIE_CHART)
    {
        buildPieChartPlot();
        return;
    }
}

void Plots::buildPieChartPlot()
{
    // generate some data:
    QVector<double> x(101), y(101); // initialize with entries 0..100
    for (int i=0; i<101; ++i)
    {
        x[i] = i/50.0 - 1; // x goes from -1 to 1
        y[i] = x[i]*x[i]; // let's plot a quadratic function
    }
    // create graph and assign data to it:
    customPlot->addGraph();
    customPlot->graph(0)->setData(x, y);
    // give the axes some labels:
    customPlot->xAxis->setLabel("x");
    customPlot->yAxis->setLabel("y");
    // set axes ranges, so we see all data:
    customPlot->xAxis->setRange(-1, 1);
    customPlot->yAxis->setRange(0, 1);
    customPlot->replot();
}

void Plots::buildBarGraphPlot()
{
    //Not implemented yet
}



