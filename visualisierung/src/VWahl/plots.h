#ifndef PLOTS_H
#define PLOTS_H

#include <record.h>


class Plots
{
public:

    enum DIA_TYPE{ PIE_CHART, BAR_GRAPH};
    Plots() = delete;

    static auto render(Record& rec, DIA_TYPE type) -> Plots;

private:
    Plots(Record& rec, DIA_TYPE tp) : record(rec), type(tp) {}
    Record record;
    DIA_TYPE type;

};

#endif // PLOTS_H
