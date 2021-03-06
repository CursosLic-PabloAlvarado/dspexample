#-------------------------------------------------
#
# Project created by QtCreator 2010-12-06T19:18:23
#
#-------------------------------------------------

QT       += widgets core gui

TARGET = dspexample
TEMPLATE = app

LIBS += -lfftw3f -ljack -lsndfile

SOURCES += main.cpp\
           mainwindow.cpp \
           equalizer.cpp \
           freqFilter.cpp \
           jack.cpp \
           dspsystem.cpp \
           combfilter.cpp \
           reverb.cpp \
           test.cpp

HEADERS  += mainwindow.h \
            equalizer.h \
            freqFilter.h \
            jack.h \
            processor.h \
            dspsystem.h \
            combfilter.h \
            reverb.h \
            test.h

FORMS    += mainwindow.ui
