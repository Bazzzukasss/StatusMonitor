#include "StatusMonitor.h"

StatusMonitor::StatusMonitor(QWidget *parent)
    :QFrame(parent)
{
    build();
}

void StatusMonitor::setHeaders(const QVector<QString> &headers)
{
    mModel->setHeaders(headers);
    resizeViewToContents();
}

void StatusMonitor::setIndicators(const QList<StatusIndicator> &indicators)
{
    mModel->setIndicators(indicators);
    resizeViewToContents();
}
void StatusMonitor::updateIndicators(const QList<StatusIndicator> &indicators)
{
    mModel->setIndicators(indicators);
}



void StatusMonitor::slotSetIndicators(const QList<StatusIndicator> &indicators)
{
    setIndicators(indicators);
}

void StatusMonitor::slotSetHeaders(const QVector<QString> &headers)
{
    setHeaders(headers);
}

void StatusMonitor::slotResizeViewToContents()
{
    resizeViewToContents();
}

void StatusMonitor::slotUpdateIndicators(const QList<StatusIndicator> &indicators)
{
    updateIndicators(indicators);
    mCaption->setChecked( !mCaption->isChecked() );
}

void StatusMonitor::resizeViewToContents()
{
    mTableView->resizeColumnsToContents();
    mTableView->resizeRowsToContents();
}

void StatusMonitor::build()
{
    mModel = new StatusIndicatorTableModel(this);
    mDelegate = new StatusIndicatorDelegate(this);
    mTableView = new QTableView(this);
    mCaption = new QRadioButton("Status Monitor",this);
    mLayout = new QVBoxLayout(this);
    mLayout->setMargin(0);
    mLayout->setSpacing(0);
    mLayout->addWidget(mCaption);
    mLayout->addWidget(mTableView);

    mTableView->setModel(mModel);
    mTableView->setItemDelegate(mDelegate);
    mTableView->setShowGrid(false);
    mTableView->verticalHeader()->hide();

    mCaption->setChecked(false);
    resizeViewToContents();

}
