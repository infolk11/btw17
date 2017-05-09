#-------------------------------------------------
#
# Project created by QtCreator 2017-04-06T22:30:40
#
#-------------------------------------------------

QT       += core gui sql

QMAKE_RPATHDIR += /usr/lib
QMAKE_RPATHDIR += /usr/local/lib


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = VWahl
TEMPLATE = app



SOURCES += main.cpp\
    partei.cpp \
    kandidat.cpp \
    wahllokal.cpp \
    logger.cpp \
    database.cpp \
    settingswindow.cpp \
    presentationwindow.cpp \
    welcomewidget.cpp \
    plots.cpp \
    record.cpp \
    qcustomplot.cpp \
    plottest.cpp

HEADERS  += partei.h \
    kandidat.h \
    wahllokal.h \
    main.h \
    logger.h \
    database.h \
    presentationwindow.h \
    settingswindow.h \
    welcomewidget.h \
    plots.h \
    record.h \
    qcustomplot.h \
    plottest.h


unix:!macx: LIBS += -llog4cpp

INCLUDEPATH += $$PWD/../../lib
DEPENDPATH += $$PWD/../../lib

STATECHARTS +=

FORMS += \
    plottest.ui
