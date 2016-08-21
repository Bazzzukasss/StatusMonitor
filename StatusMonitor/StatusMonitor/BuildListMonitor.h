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

#include "CustomItemTreeView.h"

class BuildListMonitor : public QFrame
{
    Q_OBJECT
public:
    BuildListMonitor(QWidget* parent = 0);
    void updateItems(CustomItem* rootItem);
    void setItems(CustomItem* rootItem);
    void setHeaders(const QVector<QString>& headers);

public slots:
    void slotUpdateItems(CustomItem* rootItem);
    void slotSetItems(CustomItem* rootItem);
    void slotSetHeaders(const QVector<QString>& headers);
    void slotResizeViewToContents();

private:
    CustomItemTreeView* mView;
    QRadioButton* mCaption;
    QVBoxLayout* mLayout;

    void build();
    void init();
};

#endif // BUILDLISTMONITOR_H
