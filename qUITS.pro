#-------------------------------------------------
#
# Project created by QtCreator 2014-09-28T19:08:07
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qUITS
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp

HEADERS  += widget.h

FORMS    += widget.ui

RESOURCES += \
    resource_form.qrc
RC_FILE = my.rc

