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
    StatusIndicator.cpp \
    StatusIndicatorWidget.cpp \
    StatusIndicatorDelegate.cpp \
    StatusIndicatorTableModel.cpp \
    StatusMonitor.cpp \
    qcustomplot.cpp \
    StatusIndicatorWidgets.cpp

HEADERS  += mainwindow.h \
    StatusIndicator.h \
    StatusIndicatorWidget.h \
    StatusIndicatorDelegate.h \
    StatusIndicatorTableModel.h \
    StatusMonitor.h \
    qcustomplot.h \
    StatusIndicatorTypes.h \
    StatusIndicatorWidgets.h

FORMS    += mainwindow.ui

RESOURCES +=
