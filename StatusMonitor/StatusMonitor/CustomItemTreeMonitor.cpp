#include "CustomItemTreeMonitor.h"

CustomItemTreeMonitor::CustomItemTreeMonitor(QWidget *parent)
    :QFrame(parent)
{
    init();
    build();
}

void CustomItemTreeMonitor::init()
{
    mView = new CustomItemTreeView(this);
    mCaption = new QRadioButton("Tree Monitor",this);
    mLayout = new QVBoxLayout(this);

    connect(mView, SIGNAL(signalCurrentChanged(CustomItemData,int,int)), this,   SIGNAL(signalCurrentChanged(CustomItemData,int,int)));
}

void CustomItemTreeMonitor::build()
{
    mLayout->setMargin(0);
    mLayout->setSpacing(0);
    mLayout->addWidget(mCaption);
    mLayout->addWidget(mView);
    mCaption->setChecked(false);
    mView->resizeViewToContents();
    setHeaders({"NAME","VALUE","DESC"});
}

void CustomItemTreeMonitor::setHeaders(const QVector<QString> &headers)
{
    mView->setHeaders(headers);
}

void CustomItemTreeMonitor::setItems(CustomItem* rootItem)
{
    mView->setItems(rootItem);

}
void CustomItemTreeMonitor::updateItems(CustomItem* rootItem)
{
    mView->updateItems(rootItem);
}
//SLOTS
void CustomItemTreeMonitor::slotSetHeaders(const QVector<QString> &headers)
{
    setHeaders(headers);
}

void CustomItemTreeMonitor::slotResizeViewToContents()
{
    mView->resizeViewToContents();
}

void CustomItemTreeMonitor::slotUpdateItems(CustomItem* rootItem)
{
    updateItems(rootItem);
    mCaption->setChecked( !mCaption->isChecked() );
}
void CustomItemTreeMonitor::slotSetItems(CustomItem* rootItem)
{
    setItems(rootItem);
}


