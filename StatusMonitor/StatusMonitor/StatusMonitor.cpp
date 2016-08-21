#include "StatusMonitor.h"

StatusMonitor::StatusMonitor(QWidget *parent)
    :QFrame(parent)
{
    init();
    build();
}

void StatusMonitor::init()
{
    mView = new CustomItemTableView(this);
    mCaption = new QRadioButton("Status Monitor",this);
    mLayout = new QVBoxLayout(this);
}

void StatusMonitor::build()
{
    mLayout->setMargin(0);
    mLayout->setSpacing(0);
    mLayout->addWidget(mCaption);
    mLayout->addWidget(mView);
    mCaption->setChecked(false);
    mView->resizeViewToContents();
}

void StatusMonitor::setHeaders(const QVector<QString> &headers)
{
    mView->setHeaders(headers);
}

void StatusMonitor::setItems(CustomItem* rootItem)
{
    mView->setItems(rootItem);

}
void StatusMonitor::updateItems(CustomItem* rootItem)
{
    mView->updateItems(rootItem);
}
//SLOTS
void StatusMonitor::slotSetHeaders(const QVector<QString> &headers)
{
    setHeaders(headers);
}

void StatusMonitor::slotResizeViewToContents()
{
    mView->resizeViewToContents();
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



