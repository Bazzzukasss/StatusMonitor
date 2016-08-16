#include "StatusIndicatorTableModel.h"

StatusIndicatorTableModel::StatusIndicatorTableModel(QObject *parent)
    :QAbstractTableModel(parent)
{
}

int StatusIndicatorTableModel::rowCount(const QModelIndex &parent) const
{
    return parent.isValid()?0:mIndicators.count();
}

int StatusIndicatorTableModel::columnCount(const QModelIndex &parent) const
{
    return parent.isValid()?0:mHeaders.count();
}

bool StatusIndicatorTableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(!index.isValid()||role!=Qt::EditRole)
        return false;
    if( index.row()<0 || index.row()>mIndicators.count() || index.column()<0 || index.column()>mHeaders.count()-1)
        return false;
    StatusIndicator& indicator = mIndicators[index.row()];
    indicator=value.value<StatusIndicator>();
    emit dataChanged(index,index);
    return true;
}

bool StatusIndicatorTableModel::setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role)
{
    return false;
}

bool StatusIndicatorTableModel::insertRows(int row, int count, const QModelIndex &parent)
{
    beginInsertRows(QModelIndex(),row,row+count-1);
    for(int i=0;i<count;i++)
        mIndicators.insert(0,StatusIndicator());
    endInsertRows();
    return true;
}

Qt::ItemFlags StatusIndicatorTableModel::flags(const QModelIndex &index) const
{
    Qt::ItemFlags flags=QAbstractTableModel::flags(index);
    if(index.isValid())
        flags|=Qt::ItemIsEnabled|Qt::ItemIsSelectable;//|Qt::ItemIsEditable;
    return flags;
}

QVariant StatusIndicatorTableModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
        return QVariant();

    if( index.row()<0 || index.row()>mIndicators.count() || index.column()<0 || index.column()>mHeaders.count()-1)
        return false;

    if( role != Qt::DisplayRole && role!= Qt::EditRole)
        return QVariant();

    const StatusIndicator indicator = mIndicators.at(index.row());
    return QVariant().fromValue(indicator);
}

QVariant StatusIndicatorTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role!=Qt::DisplayRole)
        return QVariant();
    if(orientation==Qt::Horizontal)
        return mHeaders[section];
    else
        return section+1;
    return QVariant();
}

void StatusIndicatorTableModel::setIndicators(const QList<StatusIndicator> &indicators)
{
    beginResetModel();
    mIndicators = indicators;
    endResetModel();
}

void StatusIndicatorTableModel::addIndicator(const StatusIndicator &indicator)
{
    beginResetModel();
    mIndicators.append(indicator);
    endResetModel();
}

void StatusIndicatorTableModel::setHeaders(const QVector<QString> &headers)
{
    mHeaders = headers;
}

void StatusIndicatorTableModel::generate()
{
    mHeaders={"Name","Value"};
    //insertRows(0,3,QModelIndex());
    for(int i=0;i<3;i++)
        mIndicators.insert(0,StatusIndicator());
}
