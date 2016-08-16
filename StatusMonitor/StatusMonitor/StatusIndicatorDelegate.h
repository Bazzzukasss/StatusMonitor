#ifndef STATUSINDICATORDELEGATE_H
#define STATUSINDICATORDELEGATE_H

#include <QStyledItemDelegate>
#include <QPainter>
#include "StatusIndicatorWidget.h"
#include "StatusIndicatorTypes.h"

class StatusIndicatorDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    StatusIndicatorDelegate(QObject* parent =0);

    ~StatusIndicatorDelegate();
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const;

    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;

    void setEditorData(QWidget *editor, const QModelIndex &index) const;
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;

public slots:
    void slotCommit();

private:
    StatusIndicatorWidget* mWidget;
};
#endif // STATUSINDICATORDELEGATE_H
