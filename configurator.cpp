#include "configurator.h"

Configurator::Configurator(QObject *parent) : QObject(parent)
{
    kombis_db = QSqlDatabase::addDatabase("QSQLITE", "KombisLoader");
    kombis_db.setDatabaseName("Kombis.db");    
    ptSETTINGS = &SETTINGS;
    ptCAMERAS = &CAMERAS;
}
//************************* LOAD KOMBIS SETTINGS **************************
bool Configurator::loadSettings()
{
    if(kombis_db.open())
    {
            QString strQUERY;
            QSqlQuery qry(kombis_db);
            //*********************** MACHINE STATUS ****************************
            strQUERY = "select id, Value from '@Settings' order by id asc";
            qry.prepare(strQUERY);
            if( !qry.exec() )
            {
                kombis_db.close();
                return false;
            }
            else
            {                
                while(qry.next())//;do
                {
                    switch (qry.value(0).toInt()) {
                    case 1: SETTINGS.strMachineName =       qry.value(1).toString();    break;
                    case 2: SETTINGS.strLastTemplate =      qry.value(1).toString();    break;
                    case 3: SETTINGS.strPassword =          qry.value(1).toString();    break;
                    case 4: SETTINGS.lreGraph_maxspeed =    qry.value(1).toDouble();    break;
                    case 5: SETTINGS.lreGraph_resolution =  qry.value(1).toDouble();    break;
                    case 6: SETTINGS.boAutoSave =           qry.value(1).toBool();      break;
                    case 7: SETTINGS.boUnits =              qry.value(1).toBool();      break;
                    case 8: SETTINGS.strLanguage =          qry.value(1).toString();    break;
                    case 9: SETTINGS.boUPS_enable =         qry.value(1).toBool();      break;
                    case 10: SETTINGS.iUPS_type =           qry.value(1).toInt();       break;
                    case 11: SETTINGS.iUPS_time =           qry.value(1).toInt();       break;
                    case 12: SETTINGS.iStatusSize =         qry.value(1).toInt();       break;
                    case 13: SETTINGS.iHistoryRows =        qry.value(1).toInt();       break;
                    case 14: {
                                SETTINGS.strMachineNumber = qry.value(1).toString();
                                CAMERAS.Cam1_IP ="192.168." + SETTINGS.strMachineNumber + ".200";
                                CAMERAS.Cam2_IP ="192.168." + SETTINGS.strMachineNumber + ".201";
                                break;
                             }
                    case 15: SETTINGS.iMaxHistoryFiles = qry.value(1).toInt(); break;
                    case 16: SETTINGS.strHistoryFilePath = qry.value(1).toString(); break;
                    case 17: SETTINGS.iMaxServoDrives = qry.value(1).toInt(); break;
                  }
                }
                kombis_db.close();
            }
     }
    else return false;
    return true;
}
//----------------------------- SAVE HMI SETTINGS -----------------------------------
bool Configurator::saveHMIsettings()
{
    if(!kombis_db.open())return false;
    QString strQUERY;
    QSqlQuery qry(kombis_db);
    //*********************** MACHINE STATUS ****************************
   
    for(int i=3; i<14; i++)
    {
        switch (i) {       
        case 3: 
            strQUERY = "update '@Settings' set Value = '";
            strQUERY.append(SETTINGS.strPassword);
            strQUERY.append("' where id = 3");            
            qry.prepare(strQUERY);
            if(!qry.exec()) return false;
            break;
        case 4: 
            strQUERY = "update '@Settings' set Value = '";
            strQUERY.append(QString::number(SETTINGS.lreGraph_maxspeed));
            strQUERY.append("' where id = 4");            
            qry.prepare(strQUERY);
            if(!qry.exec()) return false;
            break;
        case 5: 
            strQUERY = "update '@Settings' set Value = '";
            strQUERY.append(QString::number(SETTINGS.lreGraph_resolution));
            strQUERY.append("' where id = 5");            
            qry.prepare(strQUERY);
            if(!qry.exec()) return false;
            break;
        case 6: 
            strQUERY = "update '@Settings' set Value = '";
            if(SETTINGS.boAutoSave)strQUERY.append("1");
            else strQUERY.append("0");
            strQUERY.append("' where id = 6");            
            qry.prepare(strQUERY);
            if(!qry.exec()) return false;
            break;
        case 7: 
            strQUERY = "update '@Settings' set Value = '";
            if(SETTINGS.boUnits)strQUERY.append("1");
            else strQUERY.append("0");
            strQUERY.append("' where id = 7");            
            qry.prepare(strQUERY);
            if(!qry.exec()) return false;
            break;
        case 8: 
            strQUERY = "update '@Settings' set Value = '";
            strQUERY.append(SETTINGS.strLanguage);
            strQUERY.append("' where id = 8");            
            qry.prepare(strQUERY);
            if(!qry.exec()) return false;
            break;
        case 9: 
            strQUERY = "update '@Settings' set Value = '";
            if(SETTINGS.boUPS_enable)strQUERY.append("1");
            else strQUERY.append("0");
            strQUERY.append("' where id = 9");            
            qry.prepare(strQUERY);
            if(!qry.exec()) return false;
            break;
        case 10: 
            strQUERY = "update '@Settings' set Value = '";
            strQUERY.append(QString::number(SETTINGS.iUPS_type));
            strQUERY.append("' where id = 10");            
            qry.prepare(strQUERY);
            if(!qry.exec()) return false;
            break;
        case 11: 
            strQUERY = "update '@Settings' set Value = '";
            strQUERY.append(QString::number(SETTINGS.iUPS_time));
            strQUERY.append("' where id = 11");            
            qry.prepare(strQUERY);
            if(!qry.exec()) return false;
            break;
        case 12: 
            strQUERY = "update '@Settings' set Value = '";
            strQUERY.append(QString::number(SETTINGS.iStatusSize));
            strQUERY.append("' where id = 12");            
            qry.prepare(strQUERY);
            if(!qry.exec()) return false;
            break;
        case 13: 
            strQUERY = "update '@Settings' set Value = '";
            strQUERY.append(QString::number(SETTINGS.iHistoryRows));
            strQUERY.append("' where id = 13");            
            qry.prepare(strQUERY);
            if(!qry.exec()) return false;
            break;       
        }
    }
    kombis_db.close();
    return true;
}

bool Configurator::loadStatusMesages()
{
    if(kombis_db.open())
    {
            QString strQUERY;
            QSqlQuery qry(kombis_db);
            //*********************** STATUS & MESSAGES ****************************
            strQUERY = "SELECT ID, ";
            strQUERY.append(SETTINGS.strLanguage + " FROM '@Status' ORDER BY 'ID' ASC");
            qry.prepare(strQUERY);
            if( !qry.exec() )
            {
                kombis_db.close();
                return false;
            }
            else
            {
                while(qry.next()) strList_STATUS[qry.value(0).toInt()] = qry.value(1).toString();
            }
            qry.clear();
            strQUERY = "SELECT ID, ";
            strQUERY.append(SETTINGS.strLanguage + " FROM '@Messages' ORDER BY 'ID' ASC");
            qry.prepare(strQUERY);
            if( !qry.exec() )
            {
                kombis_db.close();
                return false;
            }
            else
            {
                while(qry.next()) strList_INFO[qry.value(0).toInt()] = qry.value(1).toString().toUtf8();

                kombis_db.close();
            }

     }
    else return false;
    return true;
}

bool Configurator::loadTemplates()
{
    if(kombis_db.open())
    {
            QString strQUERY;
            QSqlQuery qry(kombis_db);
            strQUERY = "select * from '@Templates' order by WhenOpened desc";
            qry.prepare(strQUERY);
            if( !qry.exec() )
            {
                kombis_db.close();
                return false;
            }
            else
            {
                strList_Templates.clear();                // QString List containing TEMPLATE LIST
                while(qry.next())//;do
                {
                    QStringList list;
                    list.append(qry.value(0).toString());
                    list.append(qry.value(1).toString());
                    list.append(qry.value(2).toString());
                    list.append(qry.value(3).toString());
                    list.append(qry.value(4).toString());
                    strList_Templates <<list;
                }
                return true;
             }
    }
    else    return false;
}

//************************* TRANSLATE USER INTERFACE **************************
bool Configurator::translateHMI()  //SLOT
{
    if(kombis_db.open())
    {       
            QString strQUERY;
            QSqlQuery qry(kombis_db);
            // *********************** MACHINE STATUS ****************************
            strQUERY = "SELECT id, ";
            strQUERY.append(SETTINGS.strLanguage);
            strQUERY.append(" FROM '@HMI_TEXT' ORDER BY id ASC;");
            qry.prepare(strQUERY);
            if( !qry.exec() ) return false;
            else
            {
                strList_HMI.clear();
                strList_HMI.append("???");
                while(qry.next())
                {
                    strList_HMI.append(qry.value(1).toString().toUtf8());
                }
            }
    kombis_db.close();
    }
    else return false;
    return true;
}
//************************************************ SAVE CONFIGURATION **************************************
void Configurator::saveSettings(QString Value, QString id)
{
        kombis_db.open();
        QString strQUERY;
        QSqlQuery qry(kombis_db);
        //*********************** MACHINE STATUS ****************************
        strQUERY = "update '@Settings' set Value = '";
        strQUERY.append(Value);
        strQUERY.append("' where id = ");
        strQUERY.append(id);
        qry.prepare(strQUERY);
        qry.exec();
        kombis_db.close();
}

//********************************************** LOAD TEMPLATE - LAST **************************************
bool Configurator::loadLastTemplate()
{
    if(kombis_db.open())
    {
        QString strQUERY;
        QSqlQuery qry(kombis_db);
        strQUERY = "SELECT *FROM '";
        strQUERY.append(SETTINGS.strLastTemplate);
        strQUERY.append("'");
        qry.prepare(strQUERY);
        //--------------------------------------- Load values ---
        if( !qry.exec() ) return false;
        else
        {
            int Group = 0;
            int Id = 0;
            while(qry.next())//;do
            {
                Group = qry.value(0).toInt();
                Id = qry.value(1).toInt();
                if(Group>31 || Group< 0) continue;
                if(Id>31 || Id < 0) continue;
                PARAMETERS[Group][Id].boExist = true;
                PARAMETERS[Group][Id].iAccessLevel = qry.value(2).toInt();
                PARAMETERS[Group][Id].dValue = qry.value(3).toDouble();
                PARAMETERS[Group][Id].dMin = qry.value(4).toDouble();
                PARAMETERS[Group][Id].dMax = qry.value(5).toDouble();
                PARAMETERS[Group][Id].dStep = qry.value(7).toDouble();
                PARAMETERS[Group][Id].strUnits = qry.value(8).toString();
                //--------------- Load Camera settings ------------------ CAMERAS
                if(Group == 30) // Cam1
                {
                    switch(Id)
                    {
                        case 0: CAMERAS.Cam1_Enable_QUINT32 = qry.value(3).toUInt(); break;
                        case 1: CAMERAS.Cam1_Analyze_INT  = qry.value(3).toInt(); break;
                        case 2: CAMERAS.Cam1_Xpos_INT  = qry.value(3).toInt(); break;
                        case 3: CAMERAS.Cam1_Ypos_INT  = qry.value(3).toInt(); break;
                        case 4: CAMERAS.Cam1_Xsize_INT = qry.value(3).toInt(); break;
                        case 5: CAMERAS.Cam1_Ysize_INT = qry.value(3).toInt(); break;
                        case 6: CAMERAS.Cam1_Threshold_INT = qry.value(3).toInt(); break;
                        case 7: CAMERAS.Cam1_BlackWhite_INT = qry.value(3).toInt(); break;
                    }
                }
                if(Group == 31) // Cam1
                {
                    switch(Id)
                    {
                        case 0: CAMERAS.Cam2_Enable_QUINT32 = qry.value(3).toUInt(); break;
                        case 1: CAMERAS.Cam2_Analyze_INT  = qry.value(3).toInt(); break;
                        case 2: CAMERAS.Cam2_Xpos_INT  = qry.value(3).toInt(); break;
                        case 3: CAMERAS.Cam2_Ypos_INT  = qry.value(3).toInt(); break;
                        case 4: CAMERAS.Cam2_Xsize_INT = qry.value(3).toInt(); break;
                        case 5: CAMERAS.Cam2_Ysize_INT = qry.value(3).toInt(); break;
                        case 6: CAMERAS.Cam2_Threshold_INT = qry.value(3).toInt(); break;
                        case 7: CAMERAS.Cam2_BlackWhite_INT = qry.value(3).toInt(); break;
                    }
                }
            }
        }
        qry.clear();
        //--------------------------------------- Load description ---
        strQUERY = "select GROUP_ID, Id, ";
        strQUERY.append(SETTINGS.strLanguage);
        strQUERY.append(" from '@ID_TEXT' order by id asc");
        qry.prepare(strQUERY);
        if( !qry.exec() ) return false;
        else
        {
            int Group = 0;
            int Id = 0;
            while(qry.next())//;do
            {
                Group = qry.value(0).toInt();
                Id = qry.value(1).toInt();
                PARAMETERS[Group][Id].strDescription = qry.value(2).toString();
            }
        }
        qry.clear();
        //-------------------------------------- Set Last opened date + number of times ----
        //--------------------------------------- Load description ---
        strQUERY = "update '@Templates' set WhenOpened = '";
        strQUERY.append(strDate);
        strQUERY.append("', OpenCounter = OpenCounter+1 where Template = '");
        strQUERY.append(SETTINGS.strLastTemplate);
        strQUERY.append("';");
        qry.prepare(strQUERY);
        if( !qry.exec() ) return false;
        kombis_db.close();
        return true;

    }
    else return false;
}
//******************************************* DELETE TEMPLATE *********************************************
bool Configurator::deleteTemplate()
{
    if(kombis_db.open())
    {
        QString strQUERY;
        QSqlQuery qry(kombis_db);
        strQUERY = "DROP TABLE IF EXISTS '";
        strQUERY.append(strWhatSelected);
        strQUERY.append("';");
        qry.prepare(strQUERY);
        if( !qry.exec() )
        {
            kombis_db.close();
            return false;
        }
        else
        {
            strQUERY = "DELETE FROM '@Templates' WHERE Template = '";
            strQUERY.append(strWhatSelected);
            strQUERY.append("';");
            qry.prepare(strQUERY);
            if( !qry.exec() )
            {
                kombis_db.close();
                return false;
            }
            else
            {
                kombis_db.close();
                return true;
            }
        }
    }
    else
        return false;
}

//******************************************* SLOT Save Template ******************************************
bool Configurator::saveTemplate()
{
    if(kombis_db.open())
    {
    //Create sql querry
        QString strSQL1 = "UPDATE '" + SETTINGS.strLastTemplate;
        QString strSQL2 = "' SET Value = ";
        QString strSQL3 = " WHERE Group_ID = ";
        QString strSQL4 = " AND Id = ";
        QString sql;
        QSqlQuery qry(kombis_db);

        for(int g=0; g < 32; g++)
        {
            for(int p=0; p<32; p++)
                {
                    if(!PARAMETERS[g][p].boExist) continue;
                     sql = strSQL1 + strSQL2 + QString::number(PARAMETERS[g][p].dValue) + strSQL3 + QString::number(g) + strSQL4 + QString::number(p);
                     qry.prepare(sql);                                
                     if(!qry.exec())
                     {
                         kombis_db.close();
                         return false;
                     }                               
                }
        }
        //--------------- Load Camera settings ------------------ CAMERAS
        for(int iC1 = 0; iC1 < 8; iC1++) // Cam1
        {
            sql = strSQL1 + strSQL2;// + QString::number(PARAMETERS[g][p].dValue) + strSQL3 + QString::number(g) + strSQL4 + QString::number(p);

            switch(iC1)
            {
                case 0: sql.append(QString::number(CAMERAS.Cam1_Enable_QUINT32)); break;
                case 1: sql.append(QString::number(CAMERAS.Cam1_Analyze_INT)); break;
                case 2: sql.append(QString::number(CAMERAS.Cam1_Xpos_INT)); break;
                case 3: sql.append(QString::number(CAMERAS.Cam1_Ypos_INT)); break;
                case 4: sql.append(QString::number(CAMERAS.Cam1_Xsize_INT)); break;
                case 5: sql.append(QString::number(CAMERAS.Cam1_Ysize_INT)); break;
                case 6: sql.append(QString::number(CAMERAS.Cam1_Threshold_INT)); break;
                case 7: sql.append(QString::number(CAMERAS.Cam1_BlackWhite_INT)); break;
            }
            sql.append(strSQL3 + "30" + strSQL4 + QString::number(iC1));
            qry.prepare(sql);
            if(!qry.exec())
            {
                kombis_db.close();
                return false;
            }
        }
        for(int iC2 = 0; iC2 < 8; iC2++) // Cam1
        {
            sql = strSQL1 + strSQL2;// + QString::number(PARAMETERS[g][p].dValue) + strSQL3 + QString::number(g) + strSQL4 + QString::number(p);

            switch(iC2)
            {
                case 0: sql.append(QString::number(CAMERAS.Cam2_Enable_QUINT32)); break;
                case 1: sql.append(QString::number(CAMERAS.Cam2_Analyze_INT)); break;
                case 2: sql.append(QString::number(CAMERAS.Cam2_Xpos_INT)); break;
                case 3: sql.append(QString::number(CAMERAS.Cam2_Ypos_INT)); break;
                case 4: sql.append(QString::number(CAMERAS.Cam2_Xsize_INT)); break;
                case 5: sql.append(QString::number(CAMERAS.Cam2_Ysize_INT)); break;
                case 6: sql.append(QString::number(CAMERAS.Cam2_Threshold_INT)); break;
                case 7: sql.append(QString::number(CAMERAS.Cam2_BlackWhite_INT)); break;
            }
            sql.append(strSQL3 + "31" + strSQL4 + QString::number(iC2));
            qry.prepare(sql);
            if(!qry.exec())
            {
                kombis_db.close();
                return false;
            }
        }
        kombis_db.close();
        return true;
    }
    else
        return false;
}
//******************************************* SLOT Load Template ******************************************
bool Configurator::loadTemplate()
{
    if(kombis_db.open())
    {
        QString strQUERY;
        QSqlQuery qry(kombis_db);
        strQUERY = "SELECT *FROM '";
        strQUERY.append(SETTINGS.strLastTemplate);
        strQUERY.append("';");
        qry.prepare(strQUERY);
        //--------------------------------------- Load values ---
        if( !qry.exec() )
        {
            kombis_db.close();
            return false;
        }
        else
        {
            int Group = 0;
            int Id = 0;
            while(qry.next())//;do
            {
                Group = qry.value(0).toInt();
                Id = qry.value(1).toInt();
                if(Group>31 || Group< 0) continue;
                if(Id>31 || Id < 0) continue;
                PARAMETERS[Group][Id].boExist = true;
                PARAMETERS[Group][Id].iAccessLevel = qry.value(2).toInt();
                PARAMETERS[Group][Id].dValue = qry.value(3).toDouble();
                PARAMETERS[Group][Id].dMin = qry.value(4).toDouble();
                PARAMETERS[Group][Id].dMax = qry.value(5).toDouble();
                PARAMETERS[Group][Id].dStep = qry.value(7).toDouble();
                //--------------- Load Camera settings ------------------ CAMERAS
                if(Group == 30) // Cam1
                {
                    switch(Id)
                    {
                        case 0: CAMERAS.Cam1_Enable_QUINT32 = qry.value(3).toUInt(); break;
                        case 1: CAMERAS.Cam1_Analyze_INT  = qry.value(3).toInt(); break;
                        case 2: CAMERAS.Cam1_Xpos_INT  = qry.value(3).toInt(); break;
                        case 3: CAMERAS.Cam1_Ypos_INT  = qry.value(3).toInt(); break;
                        case 4: CAMERAS.Cam1_Xsize_INT = qry.value(3).toInt(); break;
                        case 5: CAMERAS.Cam1_Ysize_INT = qry.value(3).toInt(); break;
                        case 6: CAMERAS.Cam1_Threshold_INT = qry.value(3).toInt(); break;
                        case 7: CAMERAS.Cam1_BlackWhite_INT = qry.value(3).toInt(); break;
                    }
                }
                if(Group == 31) // Cam1
                {
                    switch(Id)
                    {
                        case 0: CAMERAS.Cam2_Enable_QUINT32 = qry.value(3).toUInt(); break;
                        case 1: CAMERAS.Cam2_Analyze_INT  = qry.value(3).toInt(); break;
                        case 2: CAMERAS.Cam2_Xpos_INT  = qry.value(3).toInt(); break;
                        case 3: CAMERAS.Cam2_Ypos_INT  = qry.value(3).toInt(); break;
                        case 4: CAMERAS.Cam2_Xsize_INT = qry.value(3).toInt(); break;
                        case 5: CAMERAS.Cam2_Ysize_INT = qry.value(3).toInt(); break;
                        case 6: CAMERAS.Cam2_Threshold_INT = qry.value(3).toInt(); break;
                        case 7: CAMERAS.Cam2_BlackWhite_INT = qry.value(3).toInt(); break;
                    }
                }
            }
        }
        qry.clear();

        //-------------------------------------- Set Last opened date + number of times ----
        strQUERY = "update '@Templates' set WhenOpened = '";
        strQUERY.append(strDate);
        strQUERY.append("', OpenCounter = OpenCounter+1 where Template = '");
        strQUERY.append(SETTINGS.strLastTemplate);
         strQUERY.append("';");
        qry.prepare(strQUERY);
        if( !qry.exec() )
        {
            qry.clear();
            kombis_db.close();
            return false;
        }
         qry.clear();

         //-------------------------------------- Set SETTINGS LAST OPENED TEMPLATE ----
         strQUERY = "update '@Settings' set Value = '";
         strQUERY.append(SETTINGS.strLastTemplate);
         strQUERY.append("' where id = '2'");
         qry.prepare(strQUERY);
         if( !qry.exec() )
         {
             qry.clear();
             kombis_db.close();
             return false;
         }
         qry.clear();

        kombis_db.close();
        return true;
    }
    else
    {
         return false;
    }
}
//****************************************** NEW Template **************************************************
bool Configurator::newTemplate()
{
    for(int i = 0; i<strList_Templates.count(); i++) if(strList_Templates[i].at(0) == strNewTemplate) return false;
    if(kombis_db.open())
    {    
        QString strQUERY = "CREATE TABLE '" + strNewTemplate + "' AS SELECT * FROM '" + strWhatSelected + "';";
        QSqlQuery qry(kombis_db);
        qry.prepare(strQUERY);
        if(!qry.exec())
        { 
            qry.clear();
            kombis_db.close();
            return false;
        }
        else
        {
           qry.clear();
           strQUERY = "insert into '@Templates' (Template, WhenCreated, WhenOpened, OpenCounter, TubeCounter) VALUES ('";
           strQUERY.append(strNewTemplate + "', '");
           strQUERY.append(strDate + "', '");
           strQUERY.append(strDate + "', 1, 1);");
           qry.prepare(strQUERY);
           if( !qry.exec() )
           {
               qry.clear();
               kombis_db.close();
               return false;
           }
           QStringList list;
           list.append(strNewTemplate);
           list.append(strDate);
           list.append(strDate);
           list.append("1");
           list.append("1");
           strList_Templates <<list;
            qry.clear();
           kombis_db.close();
           return true;
        }
    }
    else
    {
        return false;
    }
}

//****************************************** SLOT -> Do Some Work ******************************************
void Configurator:: doSomeWork()
{
    switch(iWhatToDo)
    {
        case const_LOAD: //----------------------------------------------- LOAD
                if(loadTemplate())
                {
                    boWorkResult = true;
                    emit workFinished();
                }
                else
                {
                    boWorkResult = false;
                    emit workFinished();
                }
        break;

        case const_SAVE: //----------------------------------------------- SAVE
                if(saveTemplate())
                {
                    boWorkResult = true;
                    emit workFinished();
                }
                else
                {
                    boWorkResult = false;
                    emit workFinished();
                }
        break;

        case const_NEW:
                if(newTemplate())
                {
                    boWorkResult = true;
                    emit workFinished();
                }
                else
                {
                    boWorkResult = false;
                    emit workFinished();
                }
        break;

        case const_DELETE: //----------------------------------------------- DELETE
                if(deleteTemplate())
                {
                    boWorkResult = true;
                    emit workFinished();
                }
                else
                {
                    boWorkResult = false;
                    emit workFinished();
                }
        break;

        case const_SAVE_HMI: //--------------------------------------------- SAVE HMI
                if(saveHMIsettings())
                {
                    boWorkResult = true;
                    emit workFinished();
                }
                else
                {
                    boWorkResult = false;
                    emit workFinished();
                }
        break;

        default:    //------------------------------------------------------- DEFAULT
                boWorkResult = false;
                emit workFinished();
        break;
    }
}

