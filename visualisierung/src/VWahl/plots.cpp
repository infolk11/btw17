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
    Logger::log << L_DEBUG << "Creating pie chart..\n";

    QColor othersColor = VWahl::settings->value("gfx/othersColor").value<QColor>();
    int minPercent = VWahl::settings->value("gfx/minPercent").toInt();
    int minInFull = VWahl::settings->value("gfx/minChosenRecords").toInt();
    int ignoredVotes = 0;
    QList<RecordObject> ignoredParties,selectedParties;
    selectedParties = record.recordsAsOneList();
    filterObjects(selectedParties,ignoredParties,minPercent,minInFull,ignoredVotes);

    Logger::log << L_DEBUG << selectedParties.size() << " records will be shown. " << ignoredVotes << " are 'others'\n";

    QPieSeries *series = new QPieSeries();
    for(RecordObject ro : selectedParties)
    {

        QPieSlice *slice = new QPieSlice(ro.getDescription(),ro.getVotes());
        QFont labelFont = slice->labelFont();
        labelFont.setPointSize(VWahl::settings->value("gfx/fontSize").toInt());
        slice->setLabelFont(labelFont);
        slice->setPen(ro.getColor());
        slice->setBrush(ro.getColor().lighter(150));
        slice->setLabelVisible(true);
        series->append(slice);
    }

    if(ignoredVotes>0)
    {
        QPieSlice *others = new QPieSlice("Andere",ignoredVotes);
        others->setPen(othersColor);
        others->setBrush(othersColor.lighter(BRUSH_LIGHTING));
        others->setLabelVisible(true);
        series->append(others);
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
    Logger::log << L_DEBUG << "Creating bar chart...\n";
    QColor othersColor = VWahl::settings->value("gfx/othersColor").value<QColor>();
    int minPercent = VWahl::settings->value("gfx/minPercent").toInt();
    int minInFull = VWahl::settings->value("gfx/minChosenRecords").toInt();
    int ignoredVotes = 0;
    QList<RecordObject> ignoredParties,selectedParties;
    selectedParties = record.recordsAsOneList();
    filterObjects(selectedParties,ignoredParties,minPercent,minInFull,ignoredVotes);
    Logger::log << L_DEBUG << selectedParties.size() << " records will be shown. " << ignoredVotes << " are 'others'\n";

    QBarSeries *series = new QBarSeries();
    for(RecordObject ro : selectedParties)
    {
        QBarSet *set = new QBarSet(ro.getDescription());

        *set << ro.getVotes();
        set->setPen(ro.getColor());
        set->setBrush(ro.getColor().lighter(BRUSH_LIGHTING));

        series->append(set);
    }

    if(ignoredVotes>0)
    {
        QBarSet *set = new QBarSet("Andere");
        *set << ignoredVotes;
        set->setPen(othersColor);
        set->setBrush(othersColor.lighter(BRUSH_LIGHTING));
        series->append(set);
    }

    QChart* chart = new QChart();
    chart->addSeries(series);
    chart->setTitle(record.getElection());
    chart->setAnimationOptions(QChart::SeriesAnimations);
    QBarCategoryAxis *axis = new QBarCategoryAxis();
    chart->createDefaultAxes();

    chart->setAxisX(axis,series);

    chart->legend()->setVisible(true);
    QFont legendFont = chart->legend()->font();
    legendFont.setPointSize(VWahl::settings->value("gfx/fontSize").toInt());
    chart->legend()->setFont(legendFont);
    chart->legend()->setAlignment(Qt::AlignBottom);

    chartView->setChart(chart);
    chartView->repaint();

    Logger::log << L_DEBUG << "Creation successfull.\n";

}

void Plots::buildHorizontalBarChartPlot(QChartView *chartView)
{
    buildHorizontalBarChartPlot(chartView,record);
}

void Plots::buildHorizontalBarChartPlot(QChartView *chartView,Record& record)
{
    Logger::log << L_DEBUG << "Creating horizontal bar chart...\n";
    QHorizontalBarSeries *series = new QHorizontalBarSeries();
    QColor othersColor = VWahl::settings->value("gfx/othersColor").value<QColor>();
    int minPercent = VWahl::settings->value("gfx/minPercent").toInt();
    int minInFull = VWahl::settings->value("gfx/minChosenRecords").toInt();
    int ignoredVotes = 0;
    QList<RecordObject> ignoredParties,selectedParties;
    selectedParties = record.recordsAsOneList();
    filterObjects(selectedParties,ignoredParties,minPercent,minInFull,ignoredVotes);
    Logger::log << L_DEBUG << selectedParties.size() << " records will be shown. " << ignoredVotes << " are 'others'\n";

    for(RecordObject ro : selectedParties)
    {
        QBarSet *set = new QBarSet(ro.getDescription());

        *set << ro.getVotes();
        set->setPen(ro.getColor());
        set->setBrush(ro.getColor().lighter(BRUSH_LIGHTING));

        series->append(set);
    }

    if(ignoredVotes>0)
    {
        QBarSet *set = new QBarSet("Andere");
        *set << ignoredVotes;
        set->setPen(othersColor);
        set->setBrush(othersColor.lighter(BRUSH_LIGHTING));
        series->append(set);
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

    QFont legendFont = chart->legend()->font();
    legendFont.setPointSize(VWahl::settings->value("gfx/fontSize").toInt());
    chart->legend()->setFont(legendFont);
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    chartView->setChart(chart);
    chartView->repaint();
    Logger::log << L_DEBUG << "Creation successfull.\n";
}

void Plots::filterObjects(QList<RecordObject> &full, QList<RecordObject> &filtered, int minPercent, int minInFull, int& ignoredVotes)
{
    Logger::log << L_INFO << "Filtering recordObject...\n";
    Logger::log << L_DEBUG << "Min percent: " << minPercent << "\n";
    Logger::log << L_DEBUG << "minInFull: " << minInFull << "\n";

    for(int i = 0; i < full.size(); ++i)
    {
        if(full.at(i).getVotes() < minPercent)
        {
            filtered.push_back(full.at(i));
            full.removeAt(i);
            i=0;
        }
    }
    if(full.size()<minInFull)
    {
        qSort(filtered.begin(),filtered.end(),[](const RecordObject a, const RecordObject b) -> bool {
            return a.getVotes() > b.getVotes();
        });
        int diff = minInFull - full.size();
        for(int i = 0; i<diff && 0<filtered.size();++i)
        {
            full.push_back(filtered.at(0));
            filtered.removeFirst();
        }

    }
    for(RecordObject ro : filtered)
        ignoredVotes += ro.getVotes();
    Logger::log << L_INFO << "Filterd objects successfully. " << ignoredVotes << " votes have been ignored.\n";
}

