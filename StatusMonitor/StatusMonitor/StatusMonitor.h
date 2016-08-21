#ifndef STATUSMONITOR_H
#define STATUSMONITOR_H

#include <QObject>
#include <QWidget>
#include <QFrame>
#include <QString>
#include <QVector>
#include <QRadioButton>
#include <QVBoxLayout>
#include <QHeaderView>

#include "CustomItemTableView.h"

class StatusMonitor : public QFrame
{
    Q_OBJECT
public:
    StatusMonitor(QWidget* parent = 0);
    void updateItems(CustomItem* rootItem);
    void setItems(CustomItem* rootItem);
    void setHeaders(const QVector<QString>& headers);

public slots:
    void slotUpdateItems(CustomItem* rootItem);
    void slotSetItems(CustomItem* rootItem);
    void slotSetHeaders(const QVector<QString>& headers);
    void slotResizeViewToContents();

private:
    CustomItemTableView* mView;
    QRadioButton* mCaption;
    QVBoxLayout* mLayout;    

    void build();
    void init();
};

#endif // STATUSMONITOR_H
