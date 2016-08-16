#include "StatusIndicatorWidget.h"

StatusIndicatorWidget::StatusIndicatorWidget(QWidget *parent):QWidget(parent)
{
    init();
}

StatusIndicatorWidget::StatusIndicatorWidget(const StatusIndicator &indicator, QWidget *parent)
    :QWidget(parent)
{
    init();
    setIndicator(indicator);
}

void StatusIndicatorWidget::setIndicator(const StatusIndicator &indicator)
{
    mIndicator = indicator;
    build();
}

const StatusIndicator &StatusIndicatorWidget::getIndicator() const
{
    return mIndicator;
}

void StatusIndicatorWidget::setCurrentPropertyIndex(int propertyIndex)
{
    mCurrentPropertyIndex = propertyIndex;
}

QSize StatusIndicatorWidget::getSize()
{
    if((mCurrentWidget != nullptr) && (!mCurrentWidget))
        return mCurrentWidget->size();
    else
        return mStringWidget->size();
}

void StatusIndicatorWidget::build()
{
    QVariant value = mIndicator.getPropertyValue(mCurrentPropertyIndex);
    QString typeName(value.typeName());

    mCurrentWidget = nullptr;
    for(auto w : mWidgets)
        w->setVisible(false);

    switch(value.type())
    {
    case QVariant::Type::String :
        mStringWidget->setText( value.toString() );
        mCurrentWidget = mStringWidget;
        break;

    case QVariant::Type::Int :
        mIntWidget->setMaximum(std::numeric_limits<int>::max());
        mIntWidget->setMinimum(std::numeric_limits<int>::min());
        mIntWidget->setValue( value.toInt() );
        mIntWidget->specialValueText();
        mCurrentWidget = mIntWidget;
        break;

    case QVariant::Type::Double :
        mDoubleWidget->setMaximum(std::numeric_limits<int>::max());
        mDoubleWidget->setMinimum(std::numeric_limits<int>::min());
        mDoubleWidget->setValue( value.toDouble() );
        mDoubleWidget->specialValueText();
        mCurrentWidget = mDoubleWidget;
        break;

    case QVariant::Type::Bool :
        mBooleanWidget->setChecked( value.toBool() );
        mCurrentWidget = mBooleanWidget;
        break;

    default:
        if(typeName == "SIProgress")
        {
            mProgressWidget->setSIValue( value );
            mCurrentWidget = mProgressWidget;
        }
        if(typeName == "SILcd")
        {
            mLCDWidget->setSIValue( value );
            mCurrentWidget = mLCDWidget;
        }
        if(typeName == "SIInteger")
        {
            mIntWidget->setSIValue( value );
            mCurrentWidget = mIntWidget;
        }
        if(typeName == "SIDouble")
        {
            mDoubleWidget->setSIValue( value );
            mCurrentWidget = mDoubleWidget;
        }
        if(typeName == "SIBars")
        {
            mBarWidget->setSIValue(value);
            mCurrentWidget = mBarWidget;
        }
        if(typeName == "SIGraph")
        {
            mGraphWidget->setSIValue(value);
            mCurrentWidget = mGraphWidget;
        }
        if(typeName == "SIBoolean")
        {
            mBooleanWidget->setSIValue( value );
            mCurrentWidget = mBooleanWidget;
        }
        if(typeName == "SIString")
        {
            mStringWidget->setSIValue( value );
            mCurrentWidget = mStringWidget;
        }
        break;
    }

    if(mCurrentWidget != nullptr)
        mCurrentWidget->setVisible(true);
}

void StatusIndicatorWidget::init()
{
    setStyleSheet("background-color:white;");
    mStringWidget =     new QLineEditSI(this);
    mIntWidget =        new QSpinBoxSI(this);
    mDoubleWidget =     new QDoubleSpinBoxSI(this);
    mBooleanWidget =    new QRadioButtonSI(this);
    mBarWidget =        new QBarsPlotSI(this);
    mGraphWidget =      new QGraphPlotSI(this);
    mProgressWidget =   new QProgressBarSI(this);
    mLCDWidget =        new QLCDNumberSI(this);

    mWidgets.push_back( mStringWidget );
    mWidgets.push_back( mIntWidget );
    mWidgets.push_back( mDoubleWidget );
    mWidgets.push_back( mBooleanWidget );
    mWidgets.push_back( mBarWidget );
    mWidgets.push_back( mGraphWidget );
    mWidgets.push_back( mProgressWidget );
    mWidgets.push_back( mLCDWidget );

    mLayout = new QVBoxLayout(this);
    mLayout->setSpacing(0);
    mLayout->setMargin(0);

    for(auto w : mWidgets)
        mLayout->addWidget(w);
    mCurrentWidget = nullptr;
}
