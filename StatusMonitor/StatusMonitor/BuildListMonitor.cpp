#include "BuildListMonitor.h"

BuildListMonitor::BuildListMonitor(QWidget *parent)
    :QFrame(parent)
{
    build();
}

void BuildListMonitor::setHeaders(const QVector<QString> &headers)
{
    mModel->setHeaders(headers);
    resizeViewToContents();
}

void BuildListMonitor::setItems(CustomItem* items)
{
    mModel->setItems(items);
    resizeViewToContents();
}
void BuildListMonitor::updateItems(CustomItem* items)
{
    mModel->setItems(items);
}
void BuildListMonitor::slotSetHeaders(const QVector<QString> &headers)
{
    setHeaders(headers);
}

void BuildListMonitor::slotResizeViewToContents()
{
    resizeViewToContents();
}
void BuildListMonitor::slotSetItems(CustomItem* items)
{
    setItems(items);
}
void BuildListMonitor::slotUpdateItems(CustomItem* items)
{
    updateItems(items);
    mCaption->setChecked( !mCaption->isChecked() );
}

void BuildListMonitor::resizeViewToContents()
{

}

void BuildListMonitor::build()
{
    mModel = new CustomItemTreeModel(this);
    mDelegate = new CustomItemDelegate(this);
    mTreeView = new QTreeView(this);
    mCaption = new QRadioButton("Build List Monitor",this);
    mLayout = new QVBoxLayout(this);

    mLayout->setMargin(0);
    mLayout->setSpacing(0);
    mLayout->addWidget(mCaption);
    mLayout->addWidget(mTreeView);

    mTreeView->setModel(mModel);
    mTreeView->setItemDelegate(mDelegate);

    mCaption->setChecked(false);
    resizeViewToContents();
}
