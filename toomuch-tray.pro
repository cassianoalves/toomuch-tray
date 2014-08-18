#-------------------------------------------------
#
# Project created by QtCreator 2014-08-14T00:54:43
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = toomuch-tray
TEMPLATE = app


SOURCES += \
    src/view/floating.cpp \
    src/main.cpp \
    src/model/pomodoro.cpp \
    src/utils.cpp \
    src/format.cpp

HEADERS  += \
    src/view/floating.h \
    src/model/pomodoro.h \
    src/utils.h \
    src/format.h

FORMS    += \
    src/view/floating.ui

unix: CONFIG += link_pkgconfig

unix: PKGCONFIG += libcurl

RESOURCES += \
    resources/images.qrc

