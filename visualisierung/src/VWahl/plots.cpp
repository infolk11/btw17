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
    throw PlottingException(QString("Bar graphs are actually not supported!"));
}

void Plots::buildBarChartPlot()
{
    //Create bar charts
    for(QList<RecordObject> objects : record.getObjects())
    {
        QCPBarsGroup* group = new QCPBarsGroup(customPlot);
        QVector<QString> labels;

        for(RecordObject ro : objects)
        {
            //create empty bar objects
            QVector<double> votes,keys;
            labels << ro.getDescription();
            votes << ro.getVotes();
            keys << 1;

            QCPBars* bar = new QCPBars(customPlot->xAxis,customPlot->yAxis);
            bar->setBrush(ro.getColor());
            bar->setPen(ro.getColor().lighter(150));
            bar->setAntialiased(false);
            bar->setName(ro.getDescription());
            bar->setData(keys,votes);
            bar->setBarsGroup(group);
        }

    }
    customPlot->rescaleAxes();
    customPlot->replot();
}



