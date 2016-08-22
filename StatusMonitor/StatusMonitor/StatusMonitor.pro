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
    qcustomplot.cpp \
    CustomItem.cpp \
    CustomItemTableModel.cpp \
    CustomItemDelegate.cpp \
    CustomItemWidget.cpp \
    CustomItemWidgets.cpp \
    CustomItemData.cpp \
    CustomItemTreeModel.cpp \
    CustomItemTableView.cpp \
    CustomItemTreeView.cpp \
    CustomItemTableMonitor.cpp \
    CustomItemTreeMonitor.cpp

HEADERS  += mainwindow.h \
    qcustomplot.h \
    CustomItem.h \
    CustomItemTableModel.h \
    CustomItemDelegate.h \
    CustomItemWidget.h \
    CustomItemWidgets.h \
    CustomItemTypes.h \
    CustomItemData.h \
    CustomItemTreeModel.h \
    CustomItemTableView.h \
    CustomItemTreeView.h \
    CustomItemTableMonitor.h \
    CustomItemTreeMonitor.h

FORMS    += mainwindow.ui

RESOURCES +=
