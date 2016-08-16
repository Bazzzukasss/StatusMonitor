#ifndef STATUSMONITOR_H
#define STATUSMONITOR_H

#include <QObject>
#include <QWidget>
#include <QFrame>
#include <QString>
#include <QVector>
#include <QTableView>
#include <QRadioButton>
#include <QVBoxLayout>
#include <QHeaderView>

#include "StatusIndicatorTableModel.h"
#include "StatusIndicatorDelegate.h"

class StatusMonitor : public QFrame
{
    Q_OBJECT
public:
    StatusMonitor(QWidget* parent = 0);

    void setHeaders(const QVector<QString>& headers);
    void setIndicators(const QList<StatusIndicator>& indicators);
    void updateIndicators(const QList<StatusIndicator>& indicators);
    void resizeViewToContents();

public slots:
    void slotUpdateIndicators(const QList<StatusIndicator>& indicators);
    void slotSetIndicators(const QList<StatusIndicator>& indicators);
    void slotSetHeaders(const QVector<QString>& headers);
    void slotResizeViewToContents();

private:
    StatusIndicatorTableModel* mModel;
    StatusIndicatorDelegate* mDelegate;

    QTableView* mTableView;
    QRadioButton* mCaption;
    QVBoxLayout* mLayout;    

    void build();
};

#endif // STATUSMONITOR_H
