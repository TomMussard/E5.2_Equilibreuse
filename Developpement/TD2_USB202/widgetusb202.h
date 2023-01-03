#ifndef WIDGETUSB202_H
#define WIDGETUSB202_H

#include "mcculdaq.h"
#include <QWidget>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class WidgetUSB202; }
QT_END_NAMESPACE

class WidgetUSB202 : public QWidget
{
    Q_OBJECT

public:
    WidgetUSB202(QWidget *parent = nullptr);
    ~WidgetUSB202();

private slots:
    void on_checkBox_LED1_stateChanged(int arg1);

    void on_checkBox_LED2_stateChanged(int arg1);

    void on_checkBox_LED3_stateChanged(int arg1);

    void on_checkBox_LED4_stateChanged(int arg1);

    void onTimer_timeOut();


private:
    Ui::WidgetUSB202 *ui;
    MccUldaq laCarte;
    QTimer timerBP;
    enum {LED1=4,
          LED2,
          LED3,
          LED4};

    enum {BP1=1,
          BP2=2,
          BP3=4,
          BP4=8};
};

#endif // WIDGETUSB202_H
