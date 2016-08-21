#-------------------------------------------------
#
# Project created by QtCreator 2016-08-10T10:03:18
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = StatusMonitor
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    StatusMonitor.cpp \
    qcustomplot.cpp \
    CustomItem.cpp \
    CustomItemTableModel.cpp \
    CustomItemDelegate.cpp \
    CustomItemWidget.cpp \
    CustomItemWidgets.cpp \
    CustomItemData.cpp \
    CustomItemTreeModel.cpp \
    BuildListMonitor.cpp \
    CustomItemTableView.cpp \
    CustomItemTreeView.cpp

HEADERS  += mainwindow.h \
    StatusMonitor.h \
    qcustomplot.h \
    CustomItem.h \
    CustomItemTableModel.h \
    CustomItemDelegate.h \
    CustomItemWidget.h \
    CustomItemWidgets.h \
    CustomItemTypes.h \
    CustomItemData.h \
    CustomItemTreeModel.h \
    BuildListMonitor.h \
    CustomItemTableView.h \
    CustomItemTreeView.h

FORMS    += mainwindow.ui

RESOURCES +=
