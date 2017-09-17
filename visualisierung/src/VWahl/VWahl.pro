r#-------------------------------------------------
#
# Project created by QtCreator 2017-04-06T22:30:40
#
#-------------------------------------------------

QT       += core gui sql widgets charts
CONFIG += c++11

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
    plots.cpp \
    record.cpp \
    plottest.cpp \
    settingswindow.cpp \
    databasedialog.cpp \
    querydialog.cpp \
    presentationwindow.cpp \
    pollingstation.cpp \
    vwahlexception.cpp

HEADERS  += partei.h \
    kandidat.h \
    wahllokal.h \
    main.h \
    logger.h \
    database.h \
    plots.h \
    record.h \
    plottest.h \
    settingswindow.h \
    databasedialog.h \
    querydialog.h \
    presentationwindow.h \
    pollingstation.h \
    vwahlexception.h



INCLUDEPATH += $$PWD/../../lib
DEPENDPATH += $$PWD/../../lib

STATECHARTS +=

FORMS += \
    plottest.ui \
    settingswindow.ui \
    databasedialog.ui \
    querydialog.ui \
    presentationwindow.ui
