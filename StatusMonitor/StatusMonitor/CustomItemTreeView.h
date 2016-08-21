#ifndef CUSTOMITEMTREEVIEW_H
#define CUSTOMITEMTREEVIEW_H

#include <QObject>
#include <QTreeView>

#include "CustomItemTreeModel.h"
#include "CustomItemDelegate.h"

class CustomItemTreeView : public QTreeView
{
    Q_OBJECT
public:
    CustomItemTreeView(QWidget *parent = Q_NULLPTR);
    void setHeaders(const QVector<QString>& headers);
    void setItems(CustomItem* rootItem);
    void updateItems(CustomItem* rootItem);
    void resizeViewToContents();
private:
    CustomItemTreeModel* mModel;
    CustomItemDelegate* mDelegate;
    void init();
};

#endif // CUSTOMITEMTREEVIEW_H
