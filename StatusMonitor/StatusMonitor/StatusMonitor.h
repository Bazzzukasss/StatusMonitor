#ifndef STATUSMONITOR_H
#define STATUSMONITOR_H

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

#include "CustomItemTableModel.h"
#include "CustomItemDelegate.h"

class StatusMonitor : public QFrame
{
    Q_OBJECT
public:
    StatusMonitor(QWidget* parent = 0);
    void updateItems(CustomItem* rootItem);
    void setItems(CustomItem* rootItem);
    void setHeaders(const QVector<QString>& headers);
    void resizeViewToContents();

public slots:
    void slotUpdateItems(CustomItem* rootItem);
    void slotSetItems(CustomItem* rootItem);
    void slotSetHeaders(const QVector<QString>& headers);
    void slotResizeViewToContents();

private:
    CustomItemTableModel* mModel;
    CustomItemDelegate* mDelegate;

    QTableView* mTableView;
    QRadioButton* mCaption;
    QVBoxLayout* mLayout;    

    void build();
};

#endif // STATUSMONITOR_H
