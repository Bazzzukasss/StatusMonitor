#include "StatusIndicatorDelegate.h"

StatusIndicatorDelegate::StatusIndicatorDelegate(QObject *parent)
    :QStyledItemDelegate(parent)
{
    mWidget=new StatusIndicatorWidget();
}

StatusIndicatorDelegate::~StatusIndicatorDelegate()
{
    delete mWidget;
}

void StatusIndicatorDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    mWidget->setCurrentPropertyIndex( index.column() );
    QVariant var=index.model()->data(index);
    if(var.isValid())
    {
        StatusIndicator indicator=var.value<StatusIndicator>();
        mWidget->setIndicator(indicator);
        mWidget->setFixedSize(option.rect.width(),option.rect.height());
        QPixmap pixmap(mWidget->size());
        mWidget->render(&pixmap);
        painter->drawPixmap(option.rect,pixmap);
    }
}

QSize StatusIndicatorDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    return mWidget->getSize();
}

QWidget *StatusIndicatorDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    StatusIndicatorWidget* pEditor=new StatusIndicatorWidget(parent);
    connect(pEditor,SIGNAL(signalCommit()),this,SLOT(slotCommit()));
    return pEditor;
}

void StatusIndicatorDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    StatusIndicatorWidget* pEditor=qobject_cast<StatusIndicatorWidget*>(editor);
    StatusIndicator indicator = index.model()->data(index).value<StatusIndicator>();
    pEditor->setCurrentPropertyIndex( index.column() );
    pEditor->setIndicator(indicator);
}

void StatusIndicatorDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    StatusIndicatorWidget* pEditor=qobject_cast<StatusIndicatorWidget*>(editor);
    model->setData(index,QVariant().fromValue(pEditor->getIndicator()));
}

void StatusIndicatorDelegate::slotCommit()
{
    StatusIndicatorWidget* pEditor=qobject_cast<StatusIndicatorWidget*>(sender());
    emit commitData(pEditor);
    emit closeEditor(pEditor);
}
