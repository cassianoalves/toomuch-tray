#-------------------------------------------------
#
# Project created by QtCreator 2014-08-17T23:56:17
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

TARGET = toomuch-test
CONFIG   += console
CONFIG   -= app_bundle

INCLUDEPATH += ..
INCLUDEPATH += .
INCLUDEPATH += $(HOME)/lib/boost
INCLUDEPATH += ./mocks


LIBS += $(HOME)/lib/boost/stage/lib/libboost_filesystem.a
LIBS += $(HOME)/lib/boost/stage/lib/libboost_system.a
LIBS += $(HOME)/lib/boost/stage/lib/libboost_regex.a

QMAKE_CXXFLAGS += -Wno-unused-local-typedefs

TEMPLATE = app

SOURCES += \
    alltests.cpp \
    ../src/format.cpp \
    ../src/dao/configdatdao.cpp \
    ../src/model/config.cpp \
    ../src/dao/tomatoidao.cpp \
    ../src/model/pomodoro.cpp


DEFINES += SRCDIR=\\\"$$PWD/\\\"

HEADERS += \
    mocks/curl/curl.h

OTHER_FILES += \
    mocks/curl/tomatoi-example.html
