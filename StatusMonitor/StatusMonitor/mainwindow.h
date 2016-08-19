#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

#include "CustomItem.h"

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
    void signalStatusMonitorUpdate(CustomItem* items);
    void signalBuildListMonitorUpdate(CustomItem* items);
private:
    void initModel();
    Ui::MainWindow *ui;
    QTimer* mTimer;
};

#endif // MAINWINDOW_H
