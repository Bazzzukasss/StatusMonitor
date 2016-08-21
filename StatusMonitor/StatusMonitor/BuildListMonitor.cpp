#include "BuildListMonitor.h"

BuildListMonitor::BuildListMonitor(QWidget *parent)
    :QFrame(parent)
{
    init();
    build();
}

void BuildListMonitor::init()
{
    mView = new CustomItemTreeView(this);
    mCaption = new QRadioButton("Status Monitor",this);
    mLayout = new QVBoxLayout(this);
}

void BuildListMonitor::build()
{
    mLayout->setMargin(0);
    mLayout->setSpacing(0);
    mLayout->addWidget(mCaption);
    mLayout->addWidget(mView);
    mCaption->setChecked(false);
    mView->resizeViewToContents();
}

void BuildListMonitor::setHeaders(const QVector<QString> &headers)
{
    mView->setHeaders(headers);
}

void BuildListMonitor::setItems(CustomItem* rootItem)
{
    mView->setItems(rootItem);

}
void BuildListMonitor::updateItems(CustomItem* rootItem)
{
    mView->updateItems(rootItem);
}
//SLOTS
void BuildListMonitor::slotSetHeaders(const QVector<QString> &headers)
{
    setHeaders(headers);
}

void BuildListMonitor::slotResizeViewToContents()
{
    mView->resizeViewToContents();
}

void BuildListMonitor::slotUpdateItems(CustomItem* rootItem)
{
    updateItems(rootItem);
    mCaption->setChecked( !mCaption->isChecked() );
}
void BuildListMonitor::slotSetItems(CustomItem* rootItem)
{
    setItems(rootItem);
}



