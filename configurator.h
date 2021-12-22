#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QVariant>
#include "Main/config_structures.h"

#define const_MaxN_MODULES 20

#define const_LOAD 1
#define const_SAVE 2
#define const_NEW 3
#define const_DELETE 4
#define const_SAVE_HMI 5

class Configurator: public QObject
{
    Q_OBJECT
public:
    explicit Configurator(QObject *parent = nullptr);
    //************************* COMMON VALUES ********************************
    bool boWorkResult = false;
    int iUserAccess = 0;
    int iWhatToDo = 0;
    QString strWhatSelected = "";
    QString strNewTemplate = "";
    //************************* SETTINGS VALUES *******************************
    //Settings_Structure SETTINGS;
    Settings_Structure  SETTINGS;
    Cameras_Structure   CAMERAS;   
    Settings_Structure  *ptSETTINGS;
    Cameras_Structure   *ptCAMERAS;    

    //************************* DATE & TIME **********************************
    QString strDate = "dd/mm/yy";                       //String with actual date
    QString strTime = "hh:mm:ss";                       // String with actual time
    //*********************** HMI STRING LIST **********************
    QStringList strList_HMI;
    //*********************** Templates LIST **********************************
    QList       <QStringList> strList_Templates;
    //*********************** STATUS MESSAGES **********************
    QString strList_STATUS[16] = {
                                    "SYSTEM BOOT",
                                    "EMERGENCY STOP",
                                    "PNEUMATICS OFF",
                                    "ERROR:",
                                    "SERVICE MODE",
                                    "NOT HOMED",
                                    "HOMING",
                                    "STOP",
                                    "AUTOMATIC",
                                    "STEP",
                                    "-", "-","-","-","-","-"
                                    };
    QString strList_INFO[1000000];

    Parameter PARAMETERS[32][32];
    //*********************** FUNCTIONS *****************************
    bool loadSettings();    
    void saveSettings(QString Value, QString id);

    bool loadStatusMesages();

    bool loadTemplates();

    bool loadLastTemplate();
    void saveLastTemplate();

    bool translateHMI();


public slots:
    void doSomeWork();

signals:
    void workFinished();
    void configSaved();
    void configLoaded();
    //*********************** PRIVATE members ***********************
private:
    QSqlDatabase kombis_db;
    bool loadTemplate();
    bool saveTemplate();
    bool newTemplate();
    bool deleteTemplate();
    bool saveHMIsettings();
};

#endif // CONFIGURATION_H
