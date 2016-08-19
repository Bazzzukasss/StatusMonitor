#include <QtWidgets>
#include "CustomItem.h"
#include "CustomItemTreeModel.h"
#include <QDebug>

CustomItemTreeModel::CustomItemTreeModel(QObject *parent)
    : QAbstractItemModel(parent)
{
    mRootItem = 0;//new CustomItem();
}
CustomItemTreeModel::CustomItemTreeModel(CustomItem *rootItem, QObject *parent)
    : QAbstractItemModel(parent)
{
    mRootItem = rootItem;
}

CustomItemTreeModel::~CustomItemTreeModel()
{
    delete mRootItem;
}

QVariant CustomItemTreeModel::data(const QModelIndex &index, int role) const
{
    qDebug()<<"data";
    if (!index.isValid())
        return QVariant();

    if (role != Qt::DisplayRole && role != Qt::EditRole)
        return QVariant();

    CustomItem *item = getItem(index);

    if(item == 0)
        return QVariant();

    qDebug()<<item->getPropertyValue("name")<<item->itemsCount();
    //CustomItem it = *item;
    //QVariant var = QVariant().fromValue(it);
    //qDebug()<<var;
    //return var;
    return QVariant().fromValue(item);
    //return QVariant().fromValue(CustomItem());
}

bool CustomItemTreeModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    //qDebug()<<"setData";
    if (role != Qt::EditRole)
        return false;

    CustomItem *item = getItem(index);
    if(item == 0)
        return false;
    //qDebug()<<"setData";
    *item=value.value<CustomItem>();
    emit dataChanged(index, index);

    return true;
}

QVariant CustomItemTreeModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    //qDebug()<<"headerData";
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
        return mHeaders[section];

    return QVariant();
}

bool CustomItemTreeModel::setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role)
{
    return false;
}

int CustomItemTreeModel::columnCount(const QModelIndex & /* parent */) const
{
    return mHeaders.size();
}

Qt::ItemFlags CustomItemTreeModel::flags(const QModelIndex &index) const
{
    //qDebug()<<"flags";
    if (!index.isValid())
        return 0;
    Qt::ItemFlags flags = QAbstractItemModel::flags(index);

    return flags;
}

CustomItem *CustomItemTreeModel::getItem(const QModelIndex &index) const
{
    //qDebug()<<"getItem";
    if(mRootItem == 0)
        return 0;
    //qDebug()<<"getItem 0";
    if (!index.isValid())
        return mRootItem;
    //qDebug()<<"getItem 1";
    CustomItem *item = static_cast<CustomItem*>(index.internalPointer());
    //qDebug()<<"getItem 2";
    if (item)
        return item;
    else
        return 0;
}

QModelIndex CustomItemTreeModel::index(int row, int column, const QModelIndex &parent) const
{
    //qDebug()<<"index";
    if (parent.isValid() && parent.column() != 0)
        return QModelIndex();
    //qDebug()<<"index0";
    CustomItem *mParent = getItem(parent);
    //qDebug()<<"index1";
    if(!mParent)
        return QModelIndex();
    //qDebug()<<"index2";
    CustomItem *childItem = mParent->getItem(row);
    //qDebug()<<"index3";
    if (childItem)
        return createIndex(row, column, childItem);
    else
        return QModelIndex();
}

QModelIndex CustomItemTreeModel::parent(const QModelIndex &index) const
{
    //qDebug()<<"parent";
    if (!index.isValid())
        return QModelIndex();

    CustomItem *childItem = getItem(index);
    //qDebug()<<"parent0";
    if(childItem == 0)
        return QModelIndex();
    //qDebug()<<"parent1";
    CustomItem *mParent = childItem->getParent();
    //qDebug()<<"parent2";
    //if(mParent == 0 )
        //return QModelIndex();
    if (mParent == mRootItem)
        return QModelIndex();

    return createIndex(mParent->getNumber(), 0, mParent);
}

int CustomItemTreeModel::rowCount(const QModelIndex &parent) const
{
    //qDebug()<<"rowCount";
    CustomItem *mParent = getItem(parent);
    if(mParent !=0)
        return mParent->itemsCount();
    else
        return 0;
}

void CustomItemTreeModel::setItems(CustomItem* items)
{
    qDebug()<<"setItems";
    beginResetModel();
    if(mRootItem != 0 )
        delete mRootItem;
    mRootItem = items;
    endResetModel();
}

void CustomItemTreeModel::setHeaders(const QVector<QString> &headers)
{
    mHeaders = headers;
}
