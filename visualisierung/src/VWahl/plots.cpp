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
    //Determine group size. Must be always the same!
    int groupSize = record.getObjects().at(0).size();

    //Initialize variables
    QVector<VWwahlBars*> bars(groupSize);
    QVector<double> value;
    QVector<double> ticks;
    QVector<QString> desc;
    QVector<QColor> colors;

    for(QList<RecordObject> objects : record.getObjects())
    {
        for(RecordObject ro : objects)
        {
            value << ro.getVotes();
            desc << ro.getDescription();
            colors << ro.getColor();
            int tmp = 0;
            if(ticks.isEmpty())
                tmp = 1;
            else
                tmp = (ticks.at(ticks.size()-1)+1);
            ticks << tmp;
        }
    }

    for(int i = 0; i < 1; ++i)
    {
        bars[i] = new VWwahlBars(customPlot->xAxis,customPlot->yAxis,colors);
        bars[i]->setData(ticks,value);
        bars[i]->setWidth(0.2);
    }

    //set x-axis
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->setTicks(ticks,desc);
    customPlot->xAxis->setPadding(10);
    customPlot->xAxis->setTicker(textTicker);
    customPlot->xAxis->grid()->setVisible(true);
    customPlot->xAxis->setLabel(record.getElection());
    customPlot->xAxis->setSubTicks(true);


    //set y-axis
    customPlot->yAxis->setPadding(10);

    customPlot->rescaleAxes();
    customPlot->replot();

}




void VWwahlBars::draw(QCPPainter *painter)
{

    if (!mKeyAxis || !mValueAxis) { qDebug() << Q_FUNC_INFO << "invalid key or value axis"; return; }
    if (mDataContainer->isEmpty()) return;

    QCPBarsDataContainer::const_iterator visibleBegin, visibleEnd;
    getVisibleDataBounds(visibleBegin, visibleEnd);

    // loop over and draw segments of unselected/selected data:
    QList<QCPDataRange> selectedSegments, unselectedSegments, allSegments;
    getDataSegments(selectedSegments, unselectedSegments);
    allSegments << unselectedSegments << selectedSegments;

    int ci =0;
    for (int i=0; i<allSegments.size(); ++i)
    {
        bool isSelectedSegment = i >= unselectedSegments.size();
        QCPBarsDataContainer::const_iterator begin = visibleBegin;
        QCPBarsDataContainer::const_iterator end = visibleEnd;
        mDataContainer->limitIteratorsToDataRange(begin, end, allSegments.at(i));
        if (begin == end)
            continue;

        for (QCPBarsDataContainer::const_iterator it=begin; it!=end; ++it)
        {
            // draw bar:

            //Set individual color
            painter->setBrush(colors.at(ci));
            painter->setPen(colors.at(ci).lighter(150));
            ++ci;

            if (isSelectedSegment && mSelectionDecorator)
            {
                mSelectionDecorator->applyBrush(painter);
                mSelectionDecorator->applyPen(painter);
            } else
            {
                //painter->setBrush(mBrush);
                //painter->setPen(mPen);
            }
            applyDefaultAntialiasingHint(painter);
            painter->drawPolygon(getBarRect(it->key, it->value));
        }
    }

    // draw other selection decoration that isn't just line/scatter pens and brushes:
    if (mSelectionDecorator)
        mSelectionDecorator->drawDecoration(painter, selection());
}

