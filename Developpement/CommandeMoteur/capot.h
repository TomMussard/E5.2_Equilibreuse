#ifndef CAPOT_H
#define CAPOT_H

#include "mcculdaq.h"
#include <QObject>

class MccUlDaq;

class capot : public QObject
{
    Q_OBJECT
public:
    capot(MccUldaq &_laCarte, const int _numDio, QObject *parent);
    ~capot();
    void onTimerCapot_timeout();
private:
    bool etatCapot;
    int numDio;
    MccUldaq &laCarte;
};

#endif // CAPOT_H
