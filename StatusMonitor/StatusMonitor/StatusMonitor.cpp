#include "StatusMonitor.h"

StatusMonitor::StatusMonitor(QWidget *parent)
    :QFrame(parent)
{
    build();
}
void StatusMonitor::build()
{
    mModel = new CustomItemTableModel(this);
    mDelegate = new CustomItemDelegate(this);
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
void StatusMonitor::resizeViewToContents()
{
    mTableView->resizeColumnsToContents();
    mTableView->resizeRowsToContents();
}

void StatusMonitor::setHeaders(const QVector<QString> &headers)
{
    mModel->setHeaders(headers);
    resizeViewToContents();
}

void StatusMonitor::setItems(CustomItem* rootItem)
{
    mModel->setItems(rootItem);
    resizeViewToContents();
}
void StatusMonitor::updateItems(CustomItem* rootItem)
{
    mModel->setItems(rootItem);
}
//SLOTS
void StatusMonitor::slotSetHeaders(const QVector<QString> &headers)
{
    setHeaders(headers);
}

void StatusMonitor::slotResizeViewToContents()
{
    resizeViewToContents();
}

void StatusMonitor::slotUpdateItems(CustomItem* rootItem)
{
    updateItems(rootItem);
    mCaption->setChecked( !mCaption->isChecked() );
}
void StatusMonitor::slotSetItems(CustomItem* rootItem)
{
    setItems(rootItem);
}



