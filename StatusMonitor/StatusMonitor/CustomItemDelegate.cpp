#include "CustomItemDelegate.h"

CustomItemDelegate::CustomItemDelegate(QObject *parent)
    :QStyledItemDelegate(parent)
{
    mWidget=new CustomItemWidget();
}

CustomItemDelegate::~CustomItemDelegate()
{
    delete mWidget;
}

void CustomItemDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if(!index.isValid())
        return;
    qDebug()<<"index="<<index.column()<<index.row();
    mWidget->setCurrentPropertyIndex( index.column() );
    qDebug()<<"property ok";
    QVariant var=index.model()->data(index);
    //qDebug()<<"var"<<var;

    if(var.isValid())
    {
        CustomItem* item=var.value<CustomItem*>();
        mWidget->setIndicator(item);
        mWidget->setFixedSize(option.rect.width(),option.rect.height());
        QPixmap pixmap(mWidget->size());
        mWidget->render(&pixmap);
        painter->drawPixmap(option.rect,pixmap);
    }
}

QSize CustomItemDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    return mWidget->getSize();
}

QWidget *CustomItemDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    CustomItemWidget* pEditor=new CustomItemWidget(parent);
    connect(pEditor,SIGNAL(signalCommit()),this,SLOT(slotCommit()));
    return pEditor;
}

void CustomItemDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    CustomItemWidget* pEditor=qobject_cast<CustomItemWidget*>(editor);
    CustomItem* item = index.model()->data(index).value<CustomItem*>();
    pEditor->setCurrentPropertyIndex( index.column() );
    pEditor->setIndicator(item);
}

void CustomItemDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    CustomItemWidget* pEditor=qobject_cast<CustomItemWidget*>(editor);
    model->setData(index,QVariant().fromValue(pEditor->getIndicator()));
}

void CustomItemDelegate::slotCommit()
{
    CustomItemWidget* pEditor=qobject_cast<CustomItemWidget*>(sender());
    emit commitData(pEditor);
    emit closeEditor(pEditor);
}
