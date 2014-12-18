#-------------------------------------------------
#
# Project created by QtCreator 2014-11-09T19:42:03
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Jukrbox
TEMPLATE = app

LIBS += -lvlc


SOURCES += main.cpp\
        mainwindow.cpp \
    mediaplayer.cpp \
    fileio.cpp \
    cdselector.cpp \
    database.cpp \
    equalizer.cpp

HEADERS  += mainwindow.h \
    mediaplayer.h \
    fileio.h \
    cdselector.h \
    database.h \
    equalizer.h

FORMS    += mainwindow.ui
