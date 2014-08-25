#-------------------------------------------------
#
# Project created by QtCreator 2014-08-14T00:54:43
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = toomuch-tray
TEMPLATE = app

INCLUDEPATH += $(HOME)/lib/boost
LIBS += $(HOME)/lib/boost/stage/lib/libboost_filesystem.a
LIBS += $(HOME)/lib/boost/stage/lib/libboost_system.a
LIBS += $(HOME)/lib/boost/stage/lib/libboost_regex.a

QMAKE_CXXFLAGS += -Wno-unused-local-typedefs

SOURCES += \
    src/view/floating.cpp \
    src/main.cpp \
    src/model/pomodoro.cpp \
    src/format.cpp \
    src/view/menu.cpp \
    src/model/config.cpp \
    src/view/configdialog.cpp \
    src/dao/configdatdao.cpp \
    src/model/pomodorostatus.cpp \
    src/view/about.cpp \
    src/dao/tomatoidao.cpp

HEADERS  += \
    src/view/floating.h \
    src/model/pomodoro.h \
    src/format.h \
    src/view/menu.h \
    src/model/config.h \
    src/view/configdialog.h \
    src/repository/configrepository.h \
    src/dao/configdatdao.h \
    src/model/pomodorostatus.h \
    src/view/about.h \
    src/repository/remotestatusrepository.h \
    src/dao/tomatoidao.h

FORMS    += \
    src/view/floating.ui \
    src/view/configdialog.ui \
    src/view/about.ui

unix: CONFIG += link_pkgconfig

unix: PKGCONFIG += libcurl

RESOURCES += \
    resources/images.qrc

