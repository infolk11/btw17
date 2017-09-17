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
        buildBarChartPlot(true);
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

void Plots::buildBarChartPlot(bool invertAxes)
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



//    //Determine group size. Must be always the same!
//    int groupSize = record.getObjects().at(0).size();

//    //Initialize variables
//    QVector<VWwahlBars*> bars(groupSize);
//    QVector<double> value;
//    QVector<double> ticks;
//    QVector<QString> desc;
//    QVector<QColor> colors;

//    for(QList<RecordObject> objects : record.getObjects())
//    {
//        for(RecordObject ro : objects)
//        {
//            value << ro.getVotes();
//            desc << ro.getDescription();
//            colors << ro.getColor();
//            int tmp = 0;
//            if(ticks.isEmpty())
//                tmp = 1;
//            else
//                tmp = (ticks.at(ticks.size()-1)+1);
//            ticks << tmp;
//        }
//    }

//    for(int i = 0; i < 1; ++i)
//    {
//        if(invertAxes)
//            bars[i] = new VWwahlBars(customPlot->yAxis,customPlot->xAxis,colors);
//        else
//            bars[i] = new VWwahlBars(customPlot->xAxis,customPlot->yAxis,colors);

//        bars[i]->setData(ticks,value);
//        bars[i]->setWidth(0.2);
//    }

//    //set x-axis
//    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
//    textTicker->setTicks(ticks,desc);
//    customPlot->xAxis->setPadding(10);

//    if(!invertAxes)
//        customPlot->xAxis->setTicker(textTicker);

//    customPlot->xAxis->grid()->setVisible(false);
//    customPlot->xAxis->setLabel(record.getElection());
//    customPlot->xAxis->setSubTicks(true);


//    //set y-axis
//    customPlot->yAxis->setPadding(10);

//    if(invertAxes)
//        customPlot->yAxis->setTicker(textTicker);

//    customPlot->rescaleAxes();
//    customPlot->replot();

}




//void VWwahlBars::draw(QCPPainter *painter)
//{

//    if (!mKeyAxis || !mValueAxis) { qDebug() << Q_FUNC_INFO << "invalid key or value axis"; return; }
//    if (mDataContainer->isEmpty()) return;

//    QCPBarsDataContainer::const_iterator visibleBegin, visibleEnd;
//    getVisibleDataBounds(visibleBegin, visibleEnd);

//    // loop over and draw segments of unselected/selected data:
//    QList<QCPDataRange> selectedSegments, unselectedSegments, allSegments;
//    getDataSegments(selectedSegments, unselectedSegments);
//    allSegments << unselectedSegments << selectedSegments;

//    int ci =0;
//    for (int i=0; i<allSegments.size(); ++i)
//    {
//        bool isSelectedSegment = i >= unselectedSegments.size();
//        QCPBarsDataContainer::const_iterator begin = visibleBegin;
//        QCPBarsDataContainer::const_iterator end = visibleEnd;
//        mDataContainer->limitIteratorsToDataRange(begin, end, allSegments.at(i));
//        if (begin == end)
//            continue;

//        for (QCPBarsDataContainer::const_iterator it=begin; it!=end; ++it)
//        {
//            // draw bar:

//            //Set individual color
//            painter->setBrush(colors.at(ci));
//            painter->setPen(colors.at(ci).lighter(150));
//            ++ci;

//            if (isSelectedSegment && mSelectionDecorator)
//            {
//                mSelectionDecorator->applyBrush(painter);
//                mSelectionDecorator->applyPen(painter);
//            } else
//            {
//                //painter->setBrush(mBrush);
//                //painter->setPen(mPen);
//            }
//            applyDefaultAntialiasingHint(painter);
//            painter->drawPolygon(getBarRect(it->key, it->value));
//        }
//    }

//    // draw other selection decoration that isn't just line/scatter pens and brushes:
//    if (mSelectionDecorator)
//        mSelectionDecorator->drawDecoration(painter, selection());
//}

