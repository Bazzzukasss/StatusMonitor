#include "CustomItemTableView.h"

CustomItemTableView::CustomItemTableView(QWidget *parent)
    :QTableView(parent)
{
    init();
}

void CustomItemTableView::setHeaders(const QVector<QString> &headers)
{
    mModel->setHeaders(headers);
    resizeViewToContents();
}

void CustomItemTableView::setItems(CustomItem *rootItem)
{
    mModel->setItems(rootItem);
    resizeViewToContents();
}

void CustomItemTableView::setItems(const QList<CustomItem> &items)
{
    mModel->setItems(items);
    resizeViewToContents();
}

void CustomItemTableView::updateItems(CustomItem *rootItem)
{
    mModel->setItems(rootItem);
    resizeViewToContents();
}

void CustomItemTableView::resizeViewToContents()
{
    resizeColumnsToContents();
    resizeRowsToContents();
}

void CustomItemTableView::init()
{
    mModel = new CustomItemTableModel(this);
    mDelegate = new CustomItemDelegate(this);
    setModel(mModel);
    setItemDelegate(mDelegate);
    setShowGrid(false);
    verticalHeader()->hide();
    resizeViewToContents();
}
