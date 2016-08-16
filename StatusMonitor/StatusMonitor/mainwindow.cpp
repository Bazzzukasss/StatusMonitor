#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "StatusIndicatorTableModel.h"
#include "StatusIndicatorDelegate.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->statusMonitor->setHeaders({"NAME","VALUE","DESC","TEST"});
    mTimer = new QTimer(this);
    connect(mTimer, SIGNAL(timeout()),   this,   SLOT(slotTimeout()));
    connect(this,   SIGNAL(slotStatusMonitorUpdate(const QList<StatusIndicator>&)),    ui->statusMonitor,  SLOT(slotUpdateIndicators(const QList<StatusIndicator>&)));

    mTimer->start(200);
    //slotTimeout();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slotTimeout()
{
    static bool stage = true;
    QList<StatusIndicator> indList;

    int vecSize = std::rand()/1000;
    //qDebug()<<vecSize;

    std::vector<double> stdVector;
    stdVector.resize(vecSize);
    std::generate_n(stdVector.begin(),vecSize,std::rand);

    int integerValue(std::rand()/100);
    double doubleValue (std::rand()/100.0);
    bool booleanValue (stage);
    QString stringValue;
    stringValue="str:"+QString().number(integerValue);

    SIString si_string(stringValue);
    SIProgress si_progress(integerValue,0,100);
    SILcd si_lcd (std::rand()/300.0,SILcd::HEX);
    SIInteger si_integer(integerValue,0,500);
    SIDouble si_double(doubleValue,10,90);
    SIBoolean si_boolean(booleanValue);
    SIBars si_bars(QVector<double>().fromStdVector(stdVector));
    SIGraph si_graph(QVector<double>().fromStdVector(stdVector));

    indList     << StatusIndicator("SIString:",QVariant().fromValue(si_string),"desc1")
                << StatusIndicator("SIDouble:",QVariant().fromValue(si_double),"desc2")
                << StatusIndicator("SIProgress:",QVariant().fromValue(si_progress),"desc3")
                << StatusIndicator("SIInteger:",QVariant().fromValue(si_integer),"desc4")
                << StatusIndicator("SILCD:",QVariant().fromValue(si_lcd),"desc5")
                << StatusIndicator("SIBoolean:",QVariant().fromValue(si_boolean),"desc6")
                << StatusIndicator("SIBars:",QVariant().fromValue( si_bars ),"desc7")
                << StatusIndicator("Integer:",integerValue,"desc8")
                << StatusIndicator("Double:",doubleValue,"desc9")
                << StatusIndicator("Boolean:",booleanValue,"desc10")
                << StatusIndicator("String:",stringValue,"desc11");

indList[2].addProperty("graph",QVariant().fromValue( si_graph ));

    emit slotStatusMonitorUpdate(indList);

    stage = !stage;
}
