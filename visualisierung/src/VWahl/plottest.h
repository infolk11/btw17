#ifndef PLOTTEST_H
#define PLOTTEST_H

#include <QFrame>

namespace Ui {
class PlotTest;
}

class PlotTest : public QFrame
{
    Q_OBJECT

public:
    explicit PlotTest(QWidget *parent = 0);
    ~PlotTest();

public slots:
    void makePlot();
private:
    Ui::PlotTest *ui;
};

#endif // PLOTTEST_H
