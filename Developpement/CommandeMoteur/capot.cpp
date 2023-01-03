#include "capot.h"

capot::capot(MccUldaq &_laCarte, const int _numDio, QObject *parent):
    QObject(parent),
    numDio(_numDio),
    laCarte(_laCarte)
{

}

capot::~capot()
{

}

void capot::onTimerCapot_timeout()
{

}
