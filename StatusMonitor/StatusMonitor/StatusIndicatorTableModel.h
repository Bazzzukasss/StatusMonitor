#ifndef STATUSINDICATORTABLEMODEL_H
#define STATUSINDICATORTABLEMODEL_H

#include <QAbstractTableModel>
#include <QList>
#include <QVector>
#include "StatusIndicator.h"

class StatusIndicatorTableModel : public QAbstractTableModel
{
public:
    explicit StatusIndicatorTableModel(QObject *parent = 0);

    int rowCount(const QModelIndex &parent) const;

    int columnCount(const QModelIndex &parent) const;

    bool setData(const QModelIndex &index, const QVariant &value, int role)
;

    bool setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role)
;

    bool insertRows(int row, int count, const QModelIndex &parent)
;

    Qt::ItemFlags flags(const QModelIndex &index) const;

    QVariant data(const QModelIndex &index, int role) const;

    QVariant headerData(int section, Qt::Orientation orientation, int role) const;

    void setIndicators(const QList<StatusIndicator>& indicators);
    void addIndicator(const StatusIndicator& indicator);
    void setHeaders(const QVector<QString>& headers);

    void generate();
private:
    QList<StatusIndicator> mIndicators;
    QVector<QString> mHeaders;
};

#endif // STATUSINDICATORTABLEMODEL_H
