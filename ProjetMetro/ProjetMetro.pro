#-------------------------------------------------
#
# Project created by QtCreator 2014-03-18T08:34:13
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ProjetMetro
TEMPLATE = app


SOURCES += main.cpp\
        display/window.cpp \
        display/topgraphic.cpp \
        beans/top.cpp \
        beans/track.cpp \
        beans/ant.cpp \
    display/arcgraphic.cpp \
    intelligence/intelligence.cpp \
    intelligence/parameters.cpp \
    display/scenegraphic.cpp \
    intelligence/dataload.cpp \
    beans/narc.cpp

HEADERS  += main.h \
        display/window.h \
        display/topgraphic.h \
        beans/top.h \
        beans/track.h \
        beans/ant.h \
    display/arcgraphic.h \
    intelligence/intelligence.h \
    intelligence/parameters.h \
    display/scenegraphic.h \
    intelligence/dataload.h \
    beans/narc.h

FORMS    += window.ui
