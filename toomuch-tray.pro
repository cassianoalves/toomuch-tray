#-------------------------------------------------
#
# Project created by QtCreator 2014-08-14T00:54:43
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = toomuch-tray
TEMPLATE = app

INCLUDEPATH += $(BOOST_HOME)/boost

SOURCES += \
    src/view/floating.cpp \
    src/main.cpp \
    src/model/pomodoro.cpp \
    src/format.cpp \
    src/view/menu.cpp \
    src/model/config.cpp \
    src/view/configdialog.cpp \
    configdatdao.cpp

HEADERS  += \
    src/view/floating.h \
    src/model/pomodoro.h \
    src/format.h \
    src/view/menu.h \
    src/model/config.h \
    src/view/configdialog.h \
    src/repository/configrepository.h \
    configdatdao.h

FORMS    += \
    src/view/floating.ui \
    src/view/configdialog.ui

unix: CONFIG += link_pkgconfig

unix: PKGCONFIG += libcurl

RESOURCES += \
    resources/images.qrc

