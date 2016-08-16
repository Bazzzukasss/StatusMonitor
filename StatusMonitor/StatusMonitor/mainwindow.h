#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

#include "StatusIndicator.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void slotTimeout();
signals:
    void slotStatusMonitorUpdate(const QList<StatusIndicator>& indicators);
private:
    void initModel();
    Ui::MainWindow *ui;
    QTimer* mTimer;
};

#endif // MAINWINDOW_H
