# MBC100_HMI
Front-end application used for touch screen HMI in laminated tube making mashines.

This application is intended to use as an HMI for laminated tube making mashines with Beckhoff PLC. It uses an ADS connection to the PLC for data reading and writing - it is running in separate thread. 
The application suggest main s`creen which is responsible for displaying actual information about actual welding power, laminate speed and actual data from metal belts servo motors. Next screens contains the settings for each of the welding belts.
Main screen:
![MainScreen](https://user-images.githubusercontent.com/7886408/153146443-37d20289-dcb4-4713-9a13-977ff910c0a8.PNG)
Settings screen:
![SeccondScreen](https://user-images.githubusercontent.com/7886408/153147234-747baeed-0a6c-43ba-bb20-88d6a4944544.PNG)


- Status data reading path from TwinCat: "HMI.stStatus":

      struct ST_STATUS{
                quint8  byButtons[8];                                  // Future Options - Buttons
                quint8  byReady[8];                                    // Future Options - Readies
                quint8  byAlarms[8];                                   // Future Options - Alarms
                quint8  byEnables[16];                                 // Future Options - Flags
                quint8  byModules[8];                                  // Future Options - Modules

                qint32 iStatus = 0;                                     // Status
                qint32 iInfo = 0;                                       // Status Information
                qint32 iTorque[8];                                      // Future Options - Torues
                qint32 iPower[8];                                       // Future Options - Speeds
                quint32 dwValue[8];                                     // Units Times
                double  lrValue[16];                                    // Future Values   - Long Real
      };


- Control data writing path to Twincat: "HMI.stControl":

           struct ST_CONTROL{
                      quint8  byButtons[8];                                  // Future Options - Buttons
                      quint8  byReady[8];                                    // Future Options - Readies
                      quint8  byAlarms[8];                                   // Future Options - Alarms
                      quint8  byEnables[16];                                 // Future Options - Flags
                      quint32 dwLiveCounter = 0;                             // Watch Dog counter - increments on each cycle
                      quint32 dwTemplateLoad = 0;                            // Number of template number which is loaded
                      double  lrParameters[16];                              // 8 Id for parameters in each group
              };
        


