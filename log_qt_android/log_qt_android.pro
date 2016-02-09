#-------------------------------------------------
#
# Project created by QtCreator 2016-02-09T09:21:20
#
#-------------------------------------------------

QT       += core gui

#QT += ANDROID
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = log_qt_android
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    qdebug2logcat.cpp

HEADERS  += widget.h \
    qdebug2logcat.h
