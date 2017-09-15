#ifndef MAIN_H
#define MAIN_H

#include "presentationwindow.h"
#include "settingswindow.h"
#include "database.h"

#include <QSettings>
#include <QApplication>
#include <QCoreApplication>
#include <QVector>

#include "logger.h"



//forward declare SettingsWindow in order to use it in main
//I have no idea how to do this in a "better" way, nevertheless it does work
class SettingsWindow;
class Database;

namespace VWahl
{
    void run(QApplication &app);
    int init();
    int initSettings();
    int shutdown();
    void showGui();

    //functions for setting-file
    void writeBasicSettings(QString h, QString n, QString u, QString p);
    bool doBasicSettingsExist();

    //Guis
    extern PresentationWindow *presentationWindow;
    extern SettingsWindow *settingsWindow;

    //setting object, to store settings, i.e. login details for the database
    //company: Evangelische Schule Neuruppin, name: btw17
    extern QSettings *settings;

    extern Logger *log;

    extern Database *db;

    class VWahlApplication : public QApplication
    {
    public:
        VWahlApplication(int &argc, char ** arg) : QApplication(argc,arg) {}
    private:
        bool notify(QObject* receiver, QEvent* event) Q_DECL_OVERRIDE
        {
            try
            {
                return QApplication::notify(receiver,event);
            }catch(...)
            {
                QErrorMessage error;
                error.showMessage("Ein schwerer Fehler ist aufgetreten. Das Programm funktioniert evtl. nicht mehr richtig.");
            }

            return false;
        }
    };

}

#endif // MAIN_H

