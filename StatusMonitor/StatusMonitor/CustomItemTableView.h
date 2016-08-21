#ifndef CUSTOMITEMTABLEVIEW_H
#define CUSTOMITEMTABLEVIEW_H

#include <QObject>
#include <QTableView>

#include "CustomItemTableModel.h"
#include "CustomItemDelegate.h"

class CustomItemTableView : public QTableView
{
    Q_OBJECT
public:
    CustomItemTableView(QWidget *parent = Q_NULLPTR);
    void setHeaders(const QVector<QString>& headers);
    void setItems(CustomItem* rootItem);
    void setItems(const QList<CustomItem>& items);
    void updateItems(CustomItem* rootItem);
    void resizeViewToContents();
private:
    CustomItemTableModel* mModel;
    CustomItemDelegate* mDelegate;
    void init();
};

#endif // CUSTOMITEMTABLEVIEW_H
