#-------------------------------------------------
#
# Project created by QtCreator 2017-04-06T22:30:40
#
#-------------------------------------------------

QT       += core gui sql

QMAKE_RPATHDIR += /usr/lib
QMAKE_RPATHDIR += /usr/local/lib


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

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
    plots.cpp

HEADERS  += partei.h \
    kandidat.h \
    wahllokal.h \
    main.h \
    logger.h \
    database.h \
    presentationwindow.h \
    settingswindow.h \
    welcomewidget.h \
    plots.h


unix:!macx: LIBS += -llog4cpp

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../lib/release/ -lqcustomplot
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../lib/debug/ -lqcustomplot
else:unix: LIBS += -L$$PWD/../../lib/ -lqcustomplot

INCLUDEPATH += $$PWD/../../lib
DEPENDPATH += $$PWD/../../lib
