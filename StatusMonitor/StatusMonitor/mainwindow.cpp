#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "CustomItemTableModel.h"
#include "CustomItemDelegate.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->statusMonitor->setHeaders({"NAME","VALUE","DESC","TEST"});
    ui->buildlistMonitor->setHeaders({"NAME","VALUE","DESC"});//,"TEST"});
    mTimer = new QTimer(this);
    connect(mTimer, SIGNAL(timeout()),   this,   SLOT(slotTimeout()));
    connect(this,   SIGNAL(signalStatusMonitorUpdate(CustomItem*)),     ui->statusMonitor,      SLOT(slotUpdateItems(CustomItem*)));
    connect(this,   SIGNAL(signalBuildListMonitorUpdate(CustomItem*)),  ui->buildlistMonitor,   SLOT(slotUpdateItems(CustomItem*)));

    slotTimeout();
    //mTimer->start(200);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slotTimeout()
{
    static bool stage = true;
    QList<CustomItem> indList;

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

    CustomItem* rootItem = new CustomItem();
#if(1)
    CustomItem* item = new CustomItem("SIString:",QVariant().fromValue(si_string),"desc1");

    item->addItem( new CustomItem("SIDouble:",QVariant().fromValue(si_double),"desc2"));
    item->addItem( new CustomItem("SIProgress:",QVariant().fromValue(si_progress),"desc3"));


    rootItem->addItem( item );

    rootItem->addItem( new CustomItem("SIString:",QVariant().fromValue(si_string),"desc1"));
    rootItem->addItem( new CustomItem("SIDouble:",QVariant().fromValue(si_double),"desc2"));
    rootItem->addItem( new CustomItem("SIProgress:",QVariant().fromValue(si_progress),"desc3"));
    rootItem->addItem( new CustomItem("SIInteger:",QVariant().fromValue(si_integer),"desc4"));
    rootItem->addItem( new CustomItem("SILCD:",QVariant().fromValue(si_lcd),"desc5"));
    rootItem->addItem( new CustomItem("SIBoolean:",QVariant().fromValue(si_boolean),"desc6"));
    rootItem->addItem( new CustomItem("SIBars:",QVariant().fromValue( si_bars ),"desc7"));
    rootItem->addItem( new CustomItem("SIGraph:",QVariant().fromValue( si_graph ),"desc7"));
    rootItem->addItem( new CustomItem("Integer:",integerValue,"desc8"));
    rootItem->addItem( new CustomItem("Double:",doubleValue,"desc9"));
    rootItem->addItem( new CustomItem("Boolean:",booleanValue,"desc10"));
    rootItem->addItem( new CustomItem("String:",stringValue,"desc11"));

#else

    rootItem->addItem( new CustomItem("SIString:",QVariant().fromValue(si_string),"desc1"));
    rootItem->addItem( new CustomItem("SIDouble:",QVariant().fromValue(si_double),"desc2"));
    rootItem->addItem( new CustomItem("SIProgress:",QVariant().fromValue(si_progress),"desc3"));
    rootItem->addItem( new CustomItem("SIInteger:",QVariant().fromValue(si_integer),"desc4"));
    rootItem->addItem( new CustomItem("SILCD:",QVariant().fromValue(si_lcd),"desc5"));
    rootItem->addItem( new CustomItem("SIBoolean:",QVariant().fromValue(si_boolean),"desc6"));
    rootItem->addItem( new CustomItem("SIBars:",QVariant().fromValue( si_bars ),"desc7"));
    rootItem->addItem( new CustomItem("Integer:",integerValue,"desc8"));
    rootItem->addItem( new CustomItem("Double:",doubleValue,"desc9"));
    rootItem->addItem( new CustomItem("Boolean:",booleanValue,"desc10"));
    rootItem->addItem( new CustomItem("String:",stringValue,"desc11"));
#endif
    emit signalStatusMonitorUpdate(rootItem);
    emit signalBuildListMonitorUpdate(rootItem);

    stage = !stage;
}
