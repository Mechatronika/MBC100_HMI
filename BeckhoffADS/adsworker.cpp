#include "adsworker.h"
//*********************************************************************ADS reader
char      arrAdsGETPath []={"HMI.stStatus"};
//*********************************************************************ADS reader
char      arrAdsSETPath []={"HMI.stControl"};

ADSworker::ADSworker() : QThread()
{

    ptrstStatus = &stStatus;
    ptrstControl = &stControl;    
    for(int i = 0; i<8; i++)
    {
        //Status Structure
        stStatus.byButtons[i] = 0;
        stStatus.byReady[i] = 0;
        stStatus.byAlarms[i] = 0;
        stStatus.byModules[i] = 0;
        stStatus.iTorque[i] = 0;
        stStatus.iPower[i] = 0;
        stStatus.dwValue[i] = 0;
        //Control Structure//Control Structure
        stControl.byButtons[i] = 0;
        stControl.byReady[i] = 0;
        stControl.byAlarms[i] = 0;
    }
    for(int i = 0; i<16; i++)
    {
        //Status Structure
        stStatus.byEnables[i] = 0;
        stStatus.lrValue[i] = 0.0;

        //Control Structure
        stControl.byEnables[i] = 0;
        stControl.lrParameters[i] = 0.0;
    }
    /*
        pAddr->netId.b[0] = 192;
        pAddr->netId.b[1] = 168;
        pAddr->netId.b[2] = 20;
        pAddr->netId.b[3] = 100;
        pAddr->netId.b[4] = 1;
        pAddr->netId.b[5] = 1;
    */
}

ADSworker::~ADSworker()
{
    boRun = false;
    AdsPortClose();
}

void ADSworker::stopNow()
{
    boRun = false;

}

//SLOT TwinCAT - CONFIG MODE
void ADSworker::configTC()
{
       nPortTC = AdsPortOpen();
       nErrTC = AdsGetLocalAddress(pAddrTC);
       /*pAddrTC->netId.b[0] = 192;
       pAddrTC->netId.b[1] = 168;
       pAddrTC->netId.b[2] = 20;
       pAddrTC->netId.b[3] = 100;
       pAddrTC->netId.b[4] = 1;
       pAddrTC->netId.b[5] = 1;*/

       pAddrTC->port = 10000;
       nAdsStateWrite = ADSSTATE_RECONFIG;
       nDeviceStateWrite = 1;
       nErrTC = AdsSyncWriteControlReq(pAddrTC, nAdsStateWrite, nDeviceStateWrite, 0, pData);
       AdsPortClose();

}
//SLOT TwinCAT
void ADSworker::resetTC()
{
    nPortTC = AdsPortOpen();
    nErrTC = AdsGetLocalAddress(pAddrTC);
    /*pAddrTC->netId.b[0] = 192;
    pAddrTC->netId.b[1] = 168;
    pAddrTC->netId.b[2] = 20;
    pAddrTC->netId.b[3] = 100;
    pAddrTC->netId.b[4] = 1;
    pAddrTC->netId.b[5] = 1;
    */

    pAddrTC->port = 10000;
    nAdsStateWrite = ADSSTATE_RESET;
    nDeviceStateWrite = 1;
    nErrTC = AdsSyncWriteControlReq(pAddrTC, nAdsStateWrite, nDeviceStateWrite, 0, pData);
    AdsPortClose();
}
//Cyclic call to read or write;
void ADSworker::run()
{
    while(boRun)
    {       
        if(!boConnected)
        {
            ConnectADS();
        }
        else
        {
            if(boReadThenWrite)
            {
                ReadADS();
                boReadThenWrite = false;            // Next Cycle WRITE data
            }
            else
            {
                WriteADS();
                boReadThenWrite = true;             //Next Cycle READ
            }
        }
        this->msleep(200);
     }
}
//******************************************************************** Try Connect ADS
bool ADSworker::TryConnectADS()
{
    //return true;
    nPort = AdsPortOpen();
    nErr = AdsGetLocalAddress(pAddr);
    /*
        pAddr->netId.b[0] = 192;
        pAddr->netId.b[1] = 168;
        pAddr->netId.b[2] = 20;
        pAddr->netId.b[3] = 100;
        pAddr->netId.b[4] = 1;
        pAddr->netId.b[5] = 1;
    */
    pAddr->port = AMSPORT_R0_PLC_TC3;   // for TwinCAT3 use only
    nErr = AdsSyncReadWriteReq(pAddr, ADSIGRP_SYM_HNDBYNAME, 0x0, sizeof(lHandleREADstruct), &lHandleREADstruct, sizeof(arrAdsGETPath), arrAdsGETPath);
    nErr = AdsSyncReadWriteReq(pAddr, ADSIGRP_SYM_HNDBYNAME, 0x0, sizeof(lHandleWRITEstruct), &lHandleWRITEstruct, sizeof(arrAdsSETPath), arrAdsSETPath);   
    if(nErr == 0)return true;
    else return false;
    AdsPortClose();
}
//******************************************************************** Connect ADS
void ADSworker::ConnectADS()
{
    nPort = AdsPortOpen();
    nErr = AdsGetLocalAddress(pAddr);
    /*
        pAddr->netId.b[0] = 192;
        pAddr->netId.b[1] = 168;
        pAddr->netId.b[2] = 2;
        pAddr->netId.b[3] = 100;
        pAddr->netId.b[4] = 1;
        pAddr->netId.b[5] = 1;
    */
    pAddr->port = AMSPORT_R0_PLC_TC3;   // for TwinCAT3 use only
    nErr = AdsSyncReadWriteReq(pAddr, ADSIGRP_SYM_HNDBYNAME, 0x0, sizeof(lHandleREADstruct), &lHandleREADstruct, sizeof(arrAdsGETPath), arrAdsGETPath);
    nErr = AdsSyncReadWriteReq(pAddr, ADSIGRP_SYM_HNDBYNAME, 0x0, sizeof(lHandleWRITEstruct), &lHandleWRITEstruct, sizeof(arrAdsSETPath), arrAdsSETPath);
    if(nErr == 0)
    {
        boConnected = true;        
    }
    else
    {
        boConnected = false;       
    }
    AdsPortClose();
}

//******************************************************************** READ ADS
void ADSworker::ReadADS()
{
    if(boConnected)
    {
        AdsPortOpen();
        nErr = AdsSyncReadReq( pAddr, ADSIGRP_SYM_VALBYHND, lHandleREADstruct, sizeof(stStatus), &stStatus );
        if(nErr == 0)
        {
            emit updateHMI();                       
        }
        else boConnected = false;
        AdsPortClose();
    }
}

//******************************************************************** WRITE ADS
void ADSworker::WriteADS()
{
    if(boConnected)
    {
        AdsPortOpen();
        stControl.dwLiveCounter++;
        nErr = AdsSyncWriteReq(pAddr, ADSIGRP_SYM_VALBYHND, lHandleWRITEstruct, sizeof(stControl), &stControl);
        if(nErr != 0) boConnected = false;
        AdsPortClose();
    }
}

