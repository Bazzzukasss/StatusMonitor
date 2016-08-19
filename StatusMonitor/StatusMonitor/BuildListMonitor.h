#ifndef STATUSMONITOR_H
#define BUILDLISTMONITOR_H

#include <QObject>
#include <QWidget>
#include <QFrame>
#include <QString>
#include <QVector>
#include <QTableView>
#include <QTreeView>
#include <QRadioButton>
#include <QVBoxLayout>
#include <QHeaderView>

#include "CustomItemTreeModel.h"
#include "CustomItemDelegate.h"

class BuildListMonitor : public QFrame
{
    Q_OBJECT
public:
    BuildListMonitor(QWidget* parent = 0);

    void setHeaders(const QVector<QString>& headers);
    void setItems(CustomItem* items);
    void updateItems(CustomItem* items);
    void resizeViewToContents();

public slots:
    void slotSetItems(CustomItem* items);
    void slotUpdateItems(CustomItem* items);
    void slotSetHeaders(const QVector<QString>& headers);
    void slotResizeViewToContents();

private:
    CustomItemTreeModel* mModel;
    CustomItemDelegate* mDelegate;

    QTreeView* mTreeView;
    QRadioButton* mCaption;
    QVBoxLayout* mLayout;

    void build();
};

#endif // BUILDLISTMONITOR_H
