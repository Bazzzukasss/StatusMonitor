#ifndef CUSTOMITEMWIDGET_H
#define CUSTOMITEMWIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QVBoxLayout>

#include "CustomItem.h"
#include "CustomItemWidgets.h"
#include "CustomItemTypes.h"

class CustomItemWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CustomItemWidget(QWidget *parent = 0);
    explicit CustomItemWidget(CustomItem* item,QWidget *parent = 0);

    void setIndicator(CustomItem* item);

    CustomItem* getIndicator() const;

    void setCurrentPropertyIndex(int propertyIndex);

    QSize getSize();

signals:
    void signalCommit();

public slots:

private:
    CustomItem* mIndicator;
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

#endif // CUSTOMITEMWIDGET_H
