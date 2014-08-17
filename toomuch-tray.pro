#-------------------------------------------------
#
# Project created by QtCreator 2014-08-14T00:54:43
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = toomuch-tray
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    floating.cpp \
    pomodorostatus.cpp \
    tomatoidao.cpp \
    ticker.cpp

HEADERS  += mainwindow.h \
    floating.h \
    pomodorostatus.h \
    pomodorostatusrepository.h \
    tomatoidao.h \
    ticker.h

FORMS    += mainwindow.ui \
    floating.ui




unix: CONFIG += link_pkgconfig
unix: PKGCONFIG += libcurl
