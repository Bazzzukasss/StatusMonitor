#include "CustomItemTreeView.h"

CustomItemTreeView::CustomItemTreeView(QWidget *parent)
    :QTreeView(parent)
{
    init();
}

void CustomItemTreeView::setHeaders(const QVector<QString> &headers)
{
    mModel->setHeaders(headers);
    resizeViewToContents();
}

void CustomItemTreeView::setItems(CustomItem *rootItem)
{
    mModel->setItems(rootItem);
    resizeViewToContents();
}

void CustomItemTreeView::updateItems(CustomItem *rootItem)
{
    mModel->setItems(rootItem);
    resizeViewToContents();
}

void CustomItemTreeView::resizeViewToContents()
{
    //resizeColumnToContents(0);
    //resizeRowsToContents();
}

void CustomItemTreeView::init()
{
    mModel = new CustomItemTreeModel(this);
    mDelegate = new CustomItemDelegate(this);
    setModel(mModel);
    setItemDelegate(mDelegate);
    resizeViewToContents();
}
