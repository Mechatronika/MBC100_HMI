#ifndef ADSSTRUCTURES_H
#define ADSSTRUCTURES_H
#include <QtGlobal>

//*****************************************************************************************************************************

//ACTUAL DATA
    struct ST_STATUS{
            quint8  byButtons[8];                                  // Future Options - Buttons
            quint8  byReady[8];                                    // Future Options - Readies
            quint8  byAlarms[8];                                   // Future Options - Alarms
            quint8  byEnables[16];                                    // Future Options - Flags
            quint8  byModules[8];                                  // Future Options - Modules

            qint32 iStatus = 0;                                  // Status
            qint32 iInfo = 0;                                    // Status Information
            qint32 iTorque[8];                                  // Future Options - Torues
            qint32 iPower[8];                                   // Future Options - Speeds
            quint32 dwValue[8];                                 //Units Times
            double  lrValue[16];                                 // Future Values   - Long Real
};

//SETPOINT DATA
    struct ST_CONTROL{
            quint8  byButtons[8];                                  // Future Options - Buttons
            quint8  byReady[8];                                    // Future Options - Readies
            quint8  byAlarms[8];                                   // Future Options - Alarms
            quint8  byEnables[16];                                    // Future Options - Flags
            quint32 dwLiveCounter = 0;
            quint32 dwTemplateLoad = 0;            
            double  lrParameters[16];                                // 8 Id for parameters in each group
    };
#endif // MESSAGES_H
