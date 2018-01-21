#-------------------------------------------------
#
# Project created by QtCreator 2018-01-06T15:14:03
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qt2048
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    position.cpp

HEADERS  += widget.h \
    position.h \
    data.h

FORMS    += widget.ui
