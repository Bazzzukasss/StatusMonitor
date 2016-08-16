#ifndef STATUSINDICATORWIDGET_H
#define STATUSINDICATORWIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QVBoxLayout>

#include "StatusIndicator.h"
#include "StatusIndicatorWidgets.h"
#include "StatusIndicatorTypes.h"

class StatusIndicatorWidget : public QWidget
{
    Q_OBJECT
public:
    explicit StatusIndicatorWidget(QWidget *parent = 0);
    explicit StatusIndicatorWidget(const StatusIndicator& indicator,QWidget *parent = 0);

    void setIndicator(const StatusIndicator& indicator);

    const StatusIndicator& getIndicator() const;

    void setCurrentPropertyIndex(int propertyIndex);

    QSize getSize();

signals:
    void signalCommit();

public slots:

private:
    StatusIndicator mIndicator;
    int mCurrentPropertyIndex;

    void build();

    void init();

    QVector<QWidget*> mWidgets;
    QWidget* mCurrentWidget;

    QLineEditSI*         mStringWidget;
    QSpinBoxSI*          mIntWidget;
    QDoubleSpinBoxSI*    mDoubleWidget;
    QRadioButtonSI*      mBooleanWidget;
    QBarsPlotSI*         mBarWidget;
    QGraphPlotSI*        mGraphWidget;
    QProgressBarSI*      mProgressWidget;
    QLCDNumberSI*        mLCDWidget;

    QVBoxLayout* mLayout;
};

#endif // STATUSINDICATORWIDGET_H
