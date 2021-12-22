#ifndef ADSWORKER_H
#define ADSWORKER_H
typedef int BOOL;
#define TRUE 1
#define FALSE 0
#include <QObject>
#include <QThread>
#include <BeckhoffADS/AdsStructures.h>
#include "C:\TwinCAT\AdsApi\TcAdsDll\Include\TcAdsDef.h"
#include "C:\TwinCAT\AdsApi\TcAdsDll\Include\TcAdsAPI.h"

class ADSworker : public QThread
{
    Q_OBJECT
public:
    explicit ADSworker();
    ~ADSworker();
    void    run();                   //Run ADS worker

    void stopNow();
    ST_STATUS stStatus;       // Actal data from Beckhoff ADS
    ST_STATUS *ptrstStatus;

    ST_CONTROL stControl;     //Setpoint data ro Beckhoff ADS
    ST_CONTROL *ptrstControl;

signals:
    void updateHMI();     
    void runningTwinCat(bool boState);

public slots:
    bool    TryConnectADS();             //Try to connect with TwinCat
    void    resetTC();                   //Reset TwinCat  in RUN mode
    void    configTC();                  //Config TwinCat in config mode

private:
        bool     boConnected = false;
        bool     boReadThenWrite = true;
        bool     boRun = true;
        bool     boReset = false;
        bool     boConfig = false;
        void     *pData = nullptr;
        quint16  nDeviceStateWrite = 0;
        quint16  nAdsStateWrite = 0;
        quint16  nDeviceStateRead = 0;
        quint16  nAdsStateRead = 0;
        quint32  dwOldGroup = 0;
        quint32   dwOldId = 0;
        quint32  lHandleREADstruct, lHandleWRITEstruct;
        long     nErr, nPort, nPortTC, nErrTC;           // ADS Error and Port number
        AmsAddr  Addr;
        AmsAddr  AddrTC;
        PAmsAddr pAddr = &Addr;
        PAmsAddr pAddrTC = &AddrTC;
        void     ConnectADS();
        void     ReadADS();
        void     WriteADS();

};

#endif // ADSWORKER_H
