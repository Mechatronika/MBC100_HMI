#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //======================= Init variables ==================    
    boHMI_LOADED = false;
    iHMIStep = 0;
    iInitStep = 1;
    iNoTriesTwinCat = 0;    

    //======================= Init UI ==================
    ui->setupUi(this);
        ui->stackedWidget->setCurrentIndex(0);          //Main Page
            ui->stackedWidget_1->setCurrentIndex(0);        //External Generator
                ui->stackedWidget_2->setCurrentIndex(0);        //Internal Generator
        ui->lblEncoderDiameter->hide();
            ui->lcdEncoderDiameter->hide();    

    //======================= Show Loading Form =======
    loadingForm = new LoadingForm;
    loadingForm->setWindowFlags(Qt::WindowStaysOnTopHint);
    loadingForm->showFullScreen();    

    //======================= Setup ADS ================
    wAdsWorker = new ADSworker;
    //Init DEFAULT VALUES
        wAdsWorker->ptrstControl->byEnables[byEnables_Gen1] = 1;
        wAdsWorker->ptrstControl->byEnables[byEnables_Gen2] = 1;
        wAdsWorker->ptrstControl->byEnables[byAutomatic_Gen1] = 1;
        wAdsWorker->ptrstControl->byEnables[byAutomatic_Gen2] = 1;

        wAdsWorker->ptrstControl->lrParameters[lrParameters_EncRollDiam]    = 80.0;
        wAdsWorker->ptrstControl->lrParameters[lrParameters_ExtRollDiam]    = 120.0;
        wAdsWorker->ptrstControl->lrParameters[lrParameters_IntRollDiam]    = 120.0;
        wAdsWorker->ptrstControl->lrParameters[lrParameters_minGen1]        = 30.0;
        wAdsWorker->ptrstControl->lrParameters[lrParameters_maxGen1]        = 70.0;
        wAdsWorker->ptrstControl->lrParameters[lrParameters_minGen2]        = 30.0;
        wAdsWorker->ptrstControl->lrParameters[lrParameters_maxGen2]        = 70.0;
        wAdsWorker->ptrstControl->lrParameters[lrParameters_LenghtCor_1]        = 0.0;
        wAdsWorker->ptrstControl->lrParameters[lrParameters_PowerCor_1]        = 100.0;
        wAdsWorker->ptrstControl->lrParameters[lrParameters_LenghtCor_2]        = 0.0;
        wAdsWorker->ptrstControl->lrParameters[lrParameters_PowerCor_2]        = 100.0;

    //----------------------- Chart Initialization --------------
        //Font for Actual values - Chart Title
         chartFont.setBold(true); chartFont.setPointSize(12); chartFont.setFamily("Ariel");
    //-_-_ Chart    1
     chart1 = new QChart;
     chart1->legend()->setAlignment(Qt::AlignRight);
     chart1->legend()->setVisible(false);
     chart1->legend()->setFont(QFont("Arial", 12));
     chart1->setMargins(QMargins(0,0,0,0));     

     //-_-_ChartView    1
     chartView1 = new QChartView(chart1);    
     chartView1->setRenderHint(QPainter::Antialiasing);
     ui->groupBox_Chart1->setLayout(new QVBoxLayout); ui->groupBox_Chart1->layout()->setContentsMargins(0, 0, 0, 0);
     ui->groupBox_Chart1->layout()->addWidget(chartView1);

     //-_-_ Chart    2
      chart2 = new QChart;
      chart2->legend()->setAlignment(Qt::AlignRight);
      chart2->legend()->setVisible(false);
      chart2->setMargins(QMargins(0,0,0,0));
     // chart2->setBackgroundBrush(QColor(235, 235, 235));


      //-_-_ChartView    2
      chartView2 = new QChartView(chart2);      
      chartView2->setRenderHint(QPainter::Antialiasing);
      ui->groupBox_Chart2->setLayout(new QVBoxLayout); ui->groupBox_Chart2->layout()->setContentsMargins(0, 0, 0, 0);
      ui->groupBox_Chart2->layout()->addWidget(chartView2);

      //======================= Access Control ======
      accessControl = new AccessControl;
      accessControl->setWindowFlags(Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint);
      connect(accessControl, SIGNAL(lockSignal()), this, SLOT(lockSignal()));
      connect(accessControl, SIGNAL(unlockSignal()), this, SLOT(unlockSignal()));
      connect(accessControl, SIGNAL(exit_toWindows()), this, SLOT(exit_toWindows()));

      //======================= Save As Widget =======
       saveas_widget = new SaveAs_Widget(this);
       saveas_widget->setWindowFlags(Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint);
       connect(saveas_widget, SIGNAL(set_template_name(QString)), this, SLOT(set_template_name(QString)));
       saveas_widget->hide();
      //======================= Top Message =========
       top_message = new TopMessage(this);
       top_message->setWindowFlags(Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint);
       top_message->hide();
       //====================== Check For Last Template ========
       if(QFile::exists("lt"))
       {
           QFile file("lt");
           if(file.open(QIODevice::ReadOnly | QIODevice::Text))
           {
             QTextStream in(&file);
             strLastTemplate = in.readLine();
             strLastTemplate.remove("\n");
             strLastTemplate.remove("\r");

            }

           else
           {
                strLastTemplate = "Template.par";
            }
       }
       else
       {
            strLastTemplate = "Template.par";
       }

       //INIT  TIMER-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
                   tmr = new QTimer();
                   connect(tmr, SIGNAL(timeout()), this, SLOT(tmrTimeout()));
                   tmr->start(1000);
                   iInitStep = 1;
}

MainWindow::~MainWindow()
{
    delete ui;
}
bool MainWindow::eventFilter(QObject *object, QEvent *ev)
{      
    if (ev->type() == QEvent::MouseButtonPress)
    {        
       if(object == ui->lcdMinGen1)
           {
                                       Dialog dlgAZ(20.0, 120.0, 2, this);
                                       connect(&dlgAZ, SIGNAL(iEntered(int)), ui->slideMinGen1, SLOT(setValue(int)));
                                       dlgAZ.exec();
                                       return true;
           }
        else if(object == ui->lcdMaxGen1)
           {
                                       Dialog dlgAZ(20.0, 120.0, 2, this);
                                       connect(&dlgAZ, SIGNAL(iEntered(int)), ui->slideMaxGen1, SLOT(setValue(int)));
                                       dlgAZ.exec();
                                       return true;
           }
        else if(object == ui->lcdMinGen2)
           {
                                       Dialog dlgAZ(20.0, 120.0, 2, this);
                                       connect(&dlgAZ, SIGNAL(iEntered(int)),  ui->slideMinGen2, SLOT(setValue(int)));
                                       dlgAZ.exec();
                                       return true;
           }
        else if(object == ui->lcdMaxGen2)
           {
                                       Dialog dlgAZ(20.0, 120.0, 2, this);
                                       connect(&dlgAZ, SIGNAL(iEntered(int)),  ui->slideMaxGen2, SLOT(setValue(int)));
                                       dlgAZ.exec();
                                       return true;
           }
      /* else if(object == ui->lcdEncoderDiameter)    // Encoder Roll diameter
          {
                                      Dialog dlgAZ(75.0, 85.0, 1, this);    //as double
                                      connect(&dlgAZ, SIGNAL(dEntered(double)),  this, SLOT(setEncoderDiameter(double)));
                                      dlgAZ.exec();
                                      return true;
          }*/
       else if(object == ui->lcdExtRollDiameter)    // Encoder Roll diameter
          {
                                      Dialog dlgAZ(90.0, 110.0, 1, this);    //as double
                                      connect(&dlgAZ, SIGNAL(dEntered(double)),  this, SLOT(setExternalDiameter(double)));
                                      dlgAZ.exec();
                                      return true;
          }
       else if(object == ui->lcdIntRollDiameter)    // Encoder Roll diameter
          {
                                      Dialog dlgAZ(90.0, 110.0, 1, this);    //as double
                                      connect(&dlgAZ, SIGNAL(dEntered(double)),  this, SLOT(setInternalDiameter(double)));
                                      dlgAZ.exec();
                                      return true;
          }
       else if(object == ui->lcdLenghtCor1)    // Lenght for Power correction
          {
                                      Dialog dlgAZ(0.0, 100000.0, 1, this);    //as double
                                      connect(&dlgAZ, SIGNAL(dEntered(double)),  this, SLOT(setLenghtCorr_1(double)));
                                      dlgAZ.exec();
                                      return true;
          }
       else if(object == ui->lcdPowerCor1)    // Lenght for Power correction
          {
                                      Dialog dlgAZ(50.0, 200.0, 1, this);    //as double
                                      connect(&dlgAZ, SIGNAL(dEntered(double)),  this, SLOT(setPowerCorr_1(double)));
                                      dlgAZ.exec();
                                      return true;
          }
       else if(object == ui->lcdLenghtCor2)    // Lenght for Power correction
          {
                                      Dialog dlgAZ(0.0, 100000.0, 1, this);    //as double
                                      connect(&dlgAZ, SIGNAL(dEntered(double)),  this, SLOT(setLenghtCorr_2(double)));
                                      dlgAZ.exec();
                                      return true;
          }
       else if(object == ui->lcdPowerCor2)    // Lenght for Power correction
          {
                                      Dialog dlgAZ(50.0, 200.0, 1, this);    //as double
                                      connect(&dlgAZ, SIGNAL(dEntered(double)),  this, SLOT(setPowerCorr_2(double)));
                                      dlgAZ.exec();
                                      return true;
          }
        else return false;
    }
    else return false;
}
void MainWindow::exit_toWindows()
{
                      accessControl->hide();
                      QString strFileName = "\\Templates\\";
                      strFileName.append(strLastTemplate);
                      FileSave(strFileName);
                      this->close();
}
void MainWindow::lockSignal()
{
    ui->tbtLock->setText("LOCKED");
    ui->tbtLock->setStyleSheet("color: rgb(255, 0, 0);");
    ui->tbtLock->setIcon(QIcon(":/new/prefix1/Icones/LockOffTrans.png"));
    ui->tbtSettingsExt->setChecked(false);
    ui->tbtSettingsInt->setChecked(false);
    if(ui->stackedWidget->currentIndex() != 0) ui->stackedWidget->setCurrentIndex(0);

}
void MainWindow::unlockSignal()
{
    ui->tbtLock->setText("ULOCKED");
    ui->tbtLock->setStyleSheet("color: rgb(0, 255, 0);");
    ui->tbtLock->setIcon(QIcon(":/new/prefix1/Icones/LockOnTrans.png"));
}

//===================================================================================================================

//===================================================== TIMER =============================
void MainWindow::tmrTimeout()
{
    switch(iInitStep)//----------------------------- INITIALIZATION PROCEDURE -------------
    {        
         case 0:// UPDATE TIME / DATE -----------------------------------------------------
                 tmr->stop();
                         ui->label_DATE->setText(date.currentDate().toString());
                         ui->label_TIME->setText(time.currentTime().toString());   
                 tmr->start(100);
                 break;

         case 1: //READ SETTINGS --------------------------------------------------------------
                 tmr->stop();
                         loadingForm->putProgress(10);
                         iInitStep++;
                         tmr->start(200);

                 break;

         case 2: //READ STATUS AND MESSAGES ----------------------------------------------------------
                tmr->stop();
                        loadingForm->putProgress(20);                                                
                        //parameterText = new iddescriptions;
                        actStatus = new Status;
                        ui->lblStatus->setText(actStatus->arrStatus[0]);
                        ui->lblInfo->setText(actStatus->arrMessages[0]);
                        iInitStep++;
                        tmr->start(200);
                break;

        case 3: // CHECK LOG FILES & DIRECTORY-------------------------------------------------------- Translate HMI
                tmr->stop();
                    loadingForm->putProgress(30);
                    strPath = "\\LogFiles";
                    if(!QDir().exists(strPath)) QDir().mkpath(strPath);
                    {
                        QStringList strFiles = QDir(strPath).entryList(QDir::NoDotAndDotDot | QDir::Files);
                        if(strFiles.count()>30)
                        {
                            int iHowToDelete = strFiles.count() - 30;
                            for(int i = 0; i < iHowToDelete; i++)
                            {
                                QFile().remove(strPath + "\\" + strFiles.at(i));
                            }
                        }
                        //Create file name
                        strPath.append("\\History.");
                    }
                    iInitStep++;
                    tmr->start(200);
                break;

         case 4: //READ TEMPLATE LIST ----------------------------------------------------------
                tmr->stop();
                   loadingForm->putProgress(40);
                   if(!QDir().exists("\\Templates")) QDir().mkpath("\\Templates");
                   BrowseFiles();
                   iInitStep++;
                   tmr->start(200);
                break;


         case 5: // WAIT A MINUTE----------------------------------------------------- WAIT A MINUTE
                 tmr->stop();
                 loadingForm->putProgress(50);
                 iInitStep ++;
                 tmr->start(5500);
                 break;

        case 6: //Try TwinCat connection -------------------------------------------------------------
               tmr->stop();
                    loadingForm->putProgress(60);
                   if(wAdsWorker->TryConnectADS())   //ADS 09.2018
                   {
                    //wStatus->SystemMessage(0,0,6);
                    iInitStep++;
                    tmr->start(1000);                    
                   }
                   else
                   {                       
                       if(iNoTriesTwinCat > 10)
                       {                           
                           QMessageBox msg;
                           msg.setText("SYSTEM ERROR #5");
                           msg.setInformativeText("TwinCat Not Running for more than 10 times");
                           loadingForm->hide();
                           msg.exec();
                           //iNoTriesTwinCat++;
                           //wStatus->SystemMessage(0,0,6);
                           iInitStep++;//iInitStep = 0;
                           tmr->start(3000);
                       }
                       else
                       {                           
                           iNoTriesTwinCat++;
                           tmr->start(1000);
                       }
                   }
              break;

    case 7: // MAKE DIAGNOSTICS SCREEN------------------------------------------------------------- DIAGNOSTICS SCREEN
            tmr->stop();             
            loadingForm->putProgress(70);
            iInitStep++;
            tmr->start(100);
            break;


    case 8: // OPEN RECEIPT DATA BASE -------------------------------------------------------------open DB
                 tmr->stop();
                 loadingForm->putProgress(80);
                 //Install Event Filters
                 //=================
                 ui->lcdEncoderDiameter->installEventFilter(this);
                 ui->lcdExtRollDiameter->installEventFilter(this);
                 ui->lcdIntRollDiameter->installEventFilter(this);
                 ui->lcdMinGen1->installEventFilter(this);
                 ui->lcdMaxGen1->installEventFilter(this);
                 ui->lcdMinGen2->installEventFilter(this);
                 ui->lcdMaxGen2->installEventFilter(this);
                 ui->lcdLenghtCor1->installEventFilter(this);
                 ui->lcdLenghtCor2->installEventFilter(this);
                 ui->lcdPowerCor1->installEventFilter(this);
                 ui->lcdPowerCor2->installEventFilter(this);
                 //Make Connectins ====================
                 connect(ui->tbtEnableGen1, SIGNAL(toggled(bool)), this, SLOT(settings_EnableGen1_Checked(bool)));
                 connect(ui->tbtEnableGen2, SIGNAL(toggled(bool)), this, SLOT(settings_EnableGen2_Checked(bool)));
                 connect(ui->tbtEnablePower1 , SIGNAL(toggled(bool)), this, SLOT(settings_AutoPower1_Checked(bool)));
                 connect(ui->tbtEnablePower2, SIGNAL(toggled(bool)), this, SLOT(settings_AutoPower2_Checked(bool)));
                 connect(ui->tbtEnableMotor1, SIGNAL(toggled(bool)), this, SLOT(settings_EnableServo1_Checked(bool)));
                 connect(ui->tbtEnableMotor2, SIGNAL(toggled(bool)), this, SLOT(settings_EnableServo2_Checked(bool)));
                 connect(ui->slideMinGen1, SIGNAL(valueChanged(int)), this, SLOT(settings_minGen1_Changed(int)));
                 connect(ui->slideMaxGen1, SIGNAL(valueChanged(int)), this, SLOT(settings_maxGen1_Changed(int)));
                 connect(ui->slideMinGen2, SIGNAL(valueChanged(int)), this, SLOT(settings_minGen2_Changed(int)));
                 connect(ui->slideMaxGen2, SIGNAL(valueChanged(int)), this, SLOT(settings_maxGen2_Changed(int)));
                 iInitStep ++;
                 tmr->start(2000);
                 break;

        case 9: // OPEN RECEIPT DATA BASE ------------------------------------------------------------- load RECEIPT
                tmr->stop();
                loadingForm->putProgress(90);
                strFirstTime = "\\Templates\\";
                strFirstTime.append(strLastTemplate);
                if(FileLoad(strFirstTime))ui->lblTemplateName->setText(strLastTemplate);
                else
                {
                    strLastTemplate = "Template.par";
                    FileLoad("\\Templates\\Template.par");
                    ui->lblTemplateName->setText(strLastTemplate);
                }
                //wAdsWorker->resetTC();//emit signal_TwinCat_Reset();//ADS 09.2018
                iInitStep ++;
                tmr->start(100);
                break;

         case 10: // RUN ADS WORKER AND EVENT SYSTEM ---------------------------------------------------- RUN ADS
                 tmr->stop();
                 loadingForm->putProgress(100);                 
                    // Make Connections for ADS worker
                     connect(wAdsWorker, SIGNAL(updateHMI()), this, SLOT(updateHMI()));                    
                     connect(this, SIGNAL(signal_TwinCat_Reset()), wAdsWorker, SLOT(resetTC()));
                     //RUN ADS worker in forever loop                                        
                     wAdsWorker->start(QThread::HighPriority); //ADS 09.2018
                     boHMI_LOADED = true;

                     //wStatus->SystemMessage(0,0,1);
                     iInitStep ++;
                     tmr->start(1000);

                 break;

        case 11: // OPEN RECEIPT DATA BASE ------------------------------------------------------------- load RECEIPT
                tmr->stop();                                
                loadingForm->hide();
                loadingForm->deleteLater();
                iInitStep = 12;
                tmr->start(100);                
                break;

         default: // DEFAULT STATEMENT ------------------------------------------------------------------
                 iInitStep = 0;
                 tmr->start(1000);
                 break;

    }

}

void MainWindow::updateHMI()
{

    ui->lblStatus->setText(actStatus->arrStatus[wAdsWorker->ptrstStatus->iStatus]);
    ui->lblInfo->setText(actStatus->arrMessages[wAdsWorker->ptrstStatus->iInfo]);
    switch(wAdsWorker->ptrstStatus->iStatus)
    {
        case 0:
                ui->lblStatus->setStyleSheet("color: black; background-color: white;");
                ui->lblInfo->setStyleSheet("color: black; background-color: white;");
        break;
        case 1:
                ui->lblStatus->setStyleSheet("color: orange; background-color: white;");
                ui->lblInfo->setStyleSheet("color: orange; background-color: white;");
        break;
        case 2:
                ui->lblStatus->setStyleSheet("color: red; background-color: white;");
                ui->lblInfo->setStyleSheet("color: red; background-color: white;");
        break;
        case 3:
                ui->lblStatus->setStyleSheet("color: green; background-color: white;");
                ui->lblInfo->setStyleSheet("color: green; background-color: white;");
        break;
        case 4:
                ui->lblStatus->setStyleSheet("color: blue; background-color: white;");
                ui->lblInfo->setStyleSheet("color: blue; background-color: white;");
        break;
        case 5:
                ui->lblStatus->setStyleSheet("color: green; background-color: white;");
                ui->lblInfo->setStyleSheet("color: green; background-color: white;");
        break;
        case 10:
                ui->lblStatus->setStyleSheet("color: black; background-color: white;");
                ui->lblInfo->setStyleSheet("color: black; background-color: white;");
        break;
        case 11:
                ui->lblStatus->setStyleSheet("color: orange; background-color: white;");
                ui->lblInfo->setStyleSheet("color: orange; background-color: white;");
        break;
        case 12:
                ui->lblStatus->setStyleSheet("color: red; background-color: white;");
                ui->lblInfo->setStyleSheet("color: red; background-color: white;");
        break;
        case 13:
                ui->lblStatus->setStyleSheet("color: green; background-color: white;");
                ui->lblInfo->setStyleSheet("color: green; background-color: white;");
        break;
        case 14:
                ui->lblStatus->setStyleSheet("color: blue; background-color: white;");
                ui->lblInfo->setStyleSheet("color: blue; background-color: white;");
        break;
        case 15:
                ui->lblStatus->setStyleSheet("color: green; background-color: white;");
                ui->lblInfo->setStyleSheet("color: green; background-color: white;");
        break;
        default:
                ui->lblStatus->setStyleSheet("color: black; background-color: white;");
                ui->lblInfo->setStyleSheet("color: black; background-color: white;");
        break;
    }

    switch(iHMIStep)
    {
        case 0:
                // Ready
                if(wAdsWorker->ptrstStatus->byReady[1] ==1)ui->ledGen1_Ready->setChecked(true);
                    else ui->ledGen1_Ready->setChecked(false);
                if(wAdsWorker->ptrstStatus->byReady[2] ==1)ui->ledStrip1_Ready->setChecked(true);
                    else ui->ledStrip1_Ready->setChecked(false);
                if(wAdsWorker->ptrstStatus->byReady[3] ==1)ui->ledGen2_Ready->setChecked(true);
                    else ui->ledGen2_Ready->setChecked(false);
                if(wAdsWorker->ptrstStatus->byReady[4] ==1)ui->ledStrip2_Ready->setChecked(true);
                    else ui->ledStrip2_Ready->setChecked(false);
                iHMIStep = 1;
        break;
        case 1:
                //Alarm
                if(wAdsWorker->ptrstStatus->byAlarms[1] ==1)ui->ledGen1_Alarm->setChecked(true);
                    else ui->ledGen1_Alarm->setChecked(false);
                if(wAdsWorker->ptrstStatus->byAlarms[2] ==1)ui->ledStrip1_Alarm->setChecked(true);
                    else ui->ledStrip1_Alarm->setChecked(false);
                if(wAdsWorker->ptrstStatus->byAlarms[3] ==1)ui->ledGen2_Alarm->setChecked(true);
                    else ui->ledGen2_Alarm->setChecked(false);
                if(wAdsWorker->ptrstStatus->byAlarms[4] ==1)ui->ledStrip2_Alarm->setChecked(true);
                    else ui->ledStrip2_Alarm->setChecked(false);
                iHMIStep = 2;
        break;
        case 2:
                //Values
                 ui->lcdLaminateSpeed->display(static_cast<int>(wAdsWorker->ptrstStatus->lrValue[0]));    // Laminate Speed
                 ui->lcdPower1->display(wAdsWorker->ptrstStatus->iPower[1]);            // Gen1 Power
                 ui->lcdTorque1->display(wAdsWorker->ptrstStatus->iTorque[1]);          // Strip 1
                 ui->lcdPower2->display(wAdsWorker->ptrstStatus->iPower[2]);            // Gen 2 Power
                 ui->lcdTorque2->display(wAdsWorker->ptrstStatus->iTorque[2]);          // Strip 2
                 iHMIStep = 3;
        break;
        case 3:
                //Values
                QString t = "T = ";
                t.append(QString::number(wAdsWorker->ptrstStatus->dwValue[0]));
                t.append(" °C");
                ui->labelTemperature->setText(t);
                 iHMIStep = 0;
        break;
    }

    //Charts
    updateCharts();

}
//======================================= Chrats Update =================
void MainWindow::updateCharts()
{

    if(boCharts)
    {
        boCharts = false;
        chart1->removeAllSeries();
        //====================== Generator 1 ================================
        QLineSeries *series1 = new QLineSeries();
        //series1->append(0, wAdsWorker->ptrstControl->lrParameters[lrParameters_minGen1]);
        series1->append(30, wAdsWorker->ptrstControl->lrParameters[lrParameters_minGen1]);
        series1->append(330,wAdsWorker->ptrstControl->lrParameters[lrParameters_maxGen1]);
        //series1->append(400,wAdsWorker->ptrstControl->lrParameters[lrParameters_maxGen1]);
        series1->setPen(QPen(Qt::darkGreen, 5.0, Qt::SolidLine));

        QScatterSeries *generator1 = new QScatterSeries();
        generator1->setMarkerShape(QScatterSeries::MarkerShapeCircle);
        generator1->setMarkerSize(32.0);
        generator1->setColor(Qt::red);
        generator1->setBrush(Qt::red);
        generator1->append(wAdsWorker->ptrstStatus->lrValue[0], static_cast<double>(wAdsWorker->ptrstStatus->iPower[1]));

        chart1->addSeries(series1);        
        chart1->addSeries(generator1);
        chart1->createDefaultAxes();
        chart1->axes(Qt::Vertical).first()->setTitleText(strPowerLabel + QString::number(wAdsWorker->ptrstStatus->iPower[1]));
        chart1->axes(Qt::Vertical).first()->setRange(20, 100);
        chart1->axes(Qt::Vertical).first()->setTitleFont(chartFont);
        chart1->axes(Qt::Vertical).first()->setTitleBrush(QBrush(Qt::red));
        chart1->axes(Qt::Horizontal).first()->setTitleText(strVelocityLabel + QString::number(wAdsWorker->ptrstStatus->lrValue[0], ',', 1));
        chart1->axes(Qt::Horizontal).first()->setRange(30, 330);
        chart1->axes(Qt::Horizontal).first()->setTitleFont(chartFont);
        chart1->axes(Qt::Horizontal).first()->setTitleBrush(QBrush(Qt::red));

    }
    else
    {
        boCharts = true;
        chart2->removeAllSeries();
        //====================== Generator 2 ================================
        QLineSeries *series2 = new QLineSeries();
        //series2->append(0,wAdsWorker->ptrstControl->lrParameters[lrParameters_minGen2]);
        series2->append(30, wAdsWorker->ptrstControl->lrParameters[lrParameters_minGen2]);
        series2->append(330,wAdsWorker->ptrstControl->lrParameters[lrParameters_maxGen2]);
        //series2->append(400,wAdsWorker->ptrstControl->lrParameters[lrParameters_maxGen2]);
        series2->setPen(QPen(Qt::darkGreen, 5.0, Qt::SolidLine));

        QScatterSeries *generator2 = new QScatterSeries();
        generator2->setMarkerShape(QScatterSeries::MarkerShapeCircle);        
        generator2->setMarkerSize(32.0);
        generator2->setColor(Qt::red);
        generator2->setBrush(Qt::red);
        generator2->append(wAdsWorker->ptrstStatus->lrValue[0], static_cast<double>(wAdsWorker->ptrstStatus->iPower[2]));

        chart2->addSeries(series2);
        chart2->addSeries(generator2);                
        chart2->createDefaultAxes();
        chart2->axes(Qt::Vertical).first()->setTitleText(strPowerLabel + QString::number(wAdsWorker->ptrstStatus->iPower[2]));
        chart2->axes(Qt::Vertical).first()->setRange(20, 100);
        chart2->axes(Qt::Vertical).first()->setTitleFont(chartFont);
        chart2->axes(Qt::Vertical).first()->setTitleBrush(QBrush(Qt::red));
        chart2->axes(Qt::Horizontal).first()->setTitleText(strVelocityLabel + QString::number(wAdsWorker->ptrstStatus->lrValue[0], ',', 1));
        chart2->axes(Qt::Horizontal).first()->setRange(30, 330);        
        chart2->axes(Qt::Horizontal).first()->setTitleFont(chartFont);
        chart2->axes(Qt::Horizontal).first()->setTitleBrush(QBrush(Qt::red));
    }

}

//======================================== Browse Templates ============================================
void MainWindow::BrowseFiles()
{
    bool boParameters = false;

    ui->tableWidget->clear();
    while(ui->tableWidget->rowCount()>0)
    {
        ui->tableWidget->removeRow(ui->tableWidget->rowCount()-1);        
    }
    QDir directory("\\Templates");
        QStringList list = directory.entryList( QDir::Files);
        for(int i=0; i< list.count(); i++)
        {
            ui->tableWidget->insertRow(ui->tableWidget->rowCount());
            if(list.at(i) == "Template.par") boParameters = true;
            ui->tableWidget->setItem(i, 0, new QTableWidgetItem(list.at(i)));
        }
        if(!boParameters)
        {
            if(QFile().exists("Template.par"))
            {               
               FileSave("\\Templates\\Template.par");
            }
        }        
}

//======================================== Files Operations ============================================
//File Save function
void MainWindow::FileSave(QString filepath)
{
    //name.append(ui->lblSelected->text());
    QFile file(filepath);
    if(file.open(QIODevice::WriteOnly))
    {
        QTextStream out(&file);
        for(int i=0; i<16; i++)
            out<<QString::number(i)<<"="<<QString::number(wAdsWorker->ptrstControl->byEnables[i])<<"\n";
        for(int i=0; i<16; i++)
            out<<QString::number(i+100)<<"="<<QString::number(wAdsWorker->ptrstControl->lrParameters[i])<<"\n";
        file.close();
    }
}

//File Read function
bool MainWindow::FileLoad(QString filepath)
{    
    QFile file(filepath);
    if(file.open(QIODevice::ReadWrite | QIODevice::Text))
    {
       QTextStream in(&file);
       QStringList list;
       QStringList templist;
       int num = 0;
       while(!in.atEnd())
                list.append(in.readLine());

       for(int i = 0; i<list.count(); i++)
       {
            templist = list.at(i).split("=");
            if(templist.count() == 2)
            {
                num = templist.at(0).toInt();                
                if(num < 16)
                        {
                            if(num >=0) wAdsWorker->ptrstControl->byEnables[num] = (quint8)templist.at(1).toUShort();
                }
                else if(num < 116)
                        {
                            if(num >=100) wAdsWorker->ptrstControl->lrParameters[num-100] = templist.at(1).toDouble();
                }
            }
            templist.clear();
       }
       file.close();

            //===================================
            if(wAdsWorker->ptrstControl->byEnables[byEnables_Gen1] == 1) ui->tbtEnableGen1->setChecked(true);
                else ui->tbtEnableGen1->setChecked(false);
            if(wAdsWorker->ptrstControl->byEnables[byEnables_Gen2] == 1)ui->tbtEnableGen2->setChecked(true);
                else ui->tbtEnableGen2->setChecked(false);
            if(wAdsWorker->ptrstControl->byEnables[byAutomatic_Gen1] == 1) ui->tbtEnablePower1->setChecked(true);
                else ui->tbtEnablePower1->setChecked(false);
            if(wAdsWorker->ptrstControl->byEnables[byAutomatic_Gen2] == 1)ui->tbtEnablePower2->setChecked(true);
                else ui->tbtEnablePower2->setChecked(false);
            if(wAdsWorker->ptrstControl->byEnables[byEnables_Servo1] == 1) ui->tbtEnableMotor1->setChecked(true);
                else ui->tbtEnableMotor1->setChecked(false);
            if(wAdsWorker->ptrstControl->byEnables[byEnables_Servo2] == 1)ui->tbtEnableMotor2->setChecked(true);
                else ui->tbtEnableMotor2->setChecked(false);

            ui->lcdEncoderDiameter->display(wAdsWorker->ptrstControl->lrParameters[lrParameters_EncRollDiam]);
            ui->lcdExtRollDiameter->display(wAdsWorker->ptrstControl->lrParameters[lrParameters_ExtRollDiam]);
            ui->lcdIntRollDiameter->display(wAdsWorker->ptrstControl->lrParameters[lrParameters_IntRollDiam]);
            ui->slideMinGen1->setValue(static_cast<int>(wAdsWorker->ptrstControl->lrParameters[lrParameters_minGen1]));
            ui->slideMaxGen1->setValue(static_cast<int>(wAdsWorker->ptrstControl->lrParameters[lrParameters_maxGen1]));
            ui->slideMinGen2->setValue(static_cast<int>(wAdsWorker->ptrstControl->lrParameters[lrParameters_minGen2]));
            ui->slideMaxGen2->setValue(static_cast<int>(wAdsWorker->ptrstControl->lrParameters[lrParameters_maxGen2]));
            ui->lcdLenghtCor1->display(wAdsWorker->ptrstControl->lrParameters[lrParameters_LenghtCor_1]);
            ui->lcdLenghtCor2->display(wAdsWorker->ptrstControl->lrParameters[lrParameters_LenghtCor_2]);
            ui->lcdPowerCor1->display(wAdsWorker->ptrstControl->lrParameters[lrParameters_PowerCor_1]);
            ui->lcdPowerCor2->display(wAdsWorker->ptrstControl->lrParameters[lrParameters_PowerCor_2]);                                               
            return true;

    }
    else
    {
        return false;
    }
}

//=========================================== Settings SLOTS ==================================
void MainWindow::settings_EnableGen1_Checked(bool flag)
{
    if(!boHMI_LOADED) return;
    if(flag)wAdsWorker->ptrstControl->byEnables[1] = 1;
    else wAdsWorker->ptrstControl->byEnables[1] = 0;
}
void MainWindow::settings_EnableGen2_Checked(bool flag)
{
    if(!boHMI_LOADED) return;
    if(flag)wAdsWorker->ptrstControl->byEnables[2] = 1;
    else wAdsWorker->ptrstControl->byEnables[2] = 0;
}
void MainWindow::settings_AutoPower1_Checked(bool flag)
{
    if(!boHMI_LOADED) return;
    if(flag)wAdsWorker->ptrstControl->byEnables[3] = 1;
    else wAdsWorker->ptrstControl->byEnables[3] = 0;
}
void MainWindow::settings_AutoPower2_Checked(bool flag)
{
    if(!boHMI_LOADED) return;
    if(flag)wAdsWorker->ptrstControl->byEnables[4] = 1;
    else wAdsWorker->ptrstControl->byEnables[4] = 0;
}

void MainWindow::settings_EnableServo1_Checked(bool flag)
{
    if(!boHMI_LOADED) return;
    if(flag)wAdsWorker->ptrstControl->byEnables[byEnables_Servo1] = 1;
    else wAdsWorker->ptrstControl->byEnables[byEnables_Servo1] = 0;
}
void MainWindow::settings_EnableServo2_Checked(bool flag)
{
    if(!boHMI_LOADED) return;
    if(flag)wAdsWorker->ptrstControl->byEnables[byEnables_Servo2] = 1;
    else wAdsWorker->ptrstControl->byEnables[byEnables_Servo2] = 0;
}

void MainWindow::settings_minGen1_Changed(int value)
{    
    ui->lcdMinGen1->display(value);
    wAdsWorker->ptrstControl->lrParameters[lrParameters_minGen1] = static_cast<double>(value);
}

void MainWindow::settings_maxGen1_Changed(int value)
{
    ui->lcdMaxGen1->display(value);
    wAdsWorker->ptrstControl->lrParameters[lrParameters_maxGen1] = static_cast<double>(value);
}
void MainWindow::settings_minGen2_Changed(int value)
{
    ui->lcdMinGen2->display(value);
    wAdsWorker->ptrstControl->lrParameters[lrParameters_minGen2] = static_cast<double>(value);
}

void MainWindow::settings_maxGen2_Changed(int value)
{
    ui->lcdMaxGen2->display(value);
    wAdsWorker->ptrstControl->lrParameters[lrParameters_maxGen2] = static_cast<double>(value);
}

void MainWindow::setEncoderDiameter(double value)
{
    if(!boHMI_LOADED) return;
    ui->lcdEncoderDiameter->display(value);
    wAdsWorker->ptrstControl->lrParameters[lrParameters_EncRollDiam] = value;
}

void MainWindow::setExternalDiameter(double value)
{
    if(!boHMI_LOADED) return;
    ui->lcdExtRollDiameter->display(value);
    wAdsWorker->ptrstControl->lrParameters[lrParameters_ExtRollDiam] = value;
}

void MainWindow::setInternalDiameter(double value)
{
    if(!boHMI_LOADED) return;
    ui->lcdIntRollDiameter->display(value);
    wAdsWorker->ptrstControl->lrParameters[lrParameters_IntRollDiam] = value;
}

void MainWindow::setLenghtCorr_1(double value)
{
        if(!boHMI_LOADED) return;
        ui->lcdLenghtCor1->display(value);
        wAdsWorker->ptrstControl->lrParameters[lrParameters_LenghtCor_1] = value;
}

void MainWindow::setPowerCorr_1(double value)
{
        if(!boHMI_LOADED) return;
        ui->lcdPowerCor1->display(value);
        wAdsWorker->ptrstControl->lrParameters[lrParameters_PowerCor_1] = value;
}

void MainWindow::setLenghtCorr_2(double value)
{
        if(!boHMI_LOADED) return;
        ui->lcdLenghtCor2->display(value);
        wAdsWorker->ptrstControl->lrParameters[lrParameters_LenghtCor_2] = value;
}

void MainWindow::setPowerCorr_2(double value)
{
        if(!boHMI_LOADED) return;
        ui->lcdPowerCor2->display(value);
        wAdsWorker->ptrstControl->lrParameters[lrParameters_PowerCor_2] = value;
}

void MainWindow::on_tbtTemplates_pressed()          // Templates
{
    if(!boHMI_LOADED || !accessControl->Access) return;
    if(ui->stackedWidget->currentIndex() == 0)
    {
        BrowseFiles();
        ui->stackedWidget->setCurrentIndex(2);
    }
    else
        ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pES_pressed()
{
    double value = ui->lcdExtRollDiameter->value() + 0.1;
    if(value < 95.0)value = 95.0;
    if(value > 105.0) value = 105.0;
    setExternalDiameter(value);
}

void MainWindow::on_nES_pressed()
{
    double value = ui->lcdExtRollDiameter->value() - 0.1;
    if(value < 95.0)value = 95.0;
    if(value > 105.0) value = 105.0;
    setExternalDiameter(value);
}

void MainWindow::on_pIS_pressed()
{
    double value = ui->lcdIntRollDiameter->value() + 0.1;
    if(value < 95.0)value = 95.0;
    if(value > 105.0) value = 105.0;
    setInternalDiameter(value);
}

void MainWindow::on_nIS_pressed()
{
    double value = ui->lcdIntRollDiameter->value() - 0.1;
    if(value < 95.0)value = 95.0;
    if(value > 105.0) value = 105.0;
    setInternalDiameter(value);
}


void MainWindow::on_tbtSettingsExt_toggled(bool checked)
{    
    if(checked)
    {
        if(!accessControl->Access || !boHMI_LOADED) ui->tbtSettingsExt->setChecked(false);
        else
        {
            ui->stackedWidget_2->setCurrentIndex(1);
            ui->tbtSettingsInt->setChecked(false);
        }
    }
    else
    {
        ui->stackedWidget_2->setCurrentIndex(0);
        QString strFileName = "\\Templates\\";
        strFileName.append(strLastTemplate);
        FileSave(strFileName);
    }
}

void MainWindow::on_tbtSettingsInt_toggled(bool checked)
{    
    if(checked)
    {
        if(!accessControl->Access || !boHMI_LOADED) ui->tbtSettingsInt->setChecked(false);
        else
        {
            ui->stackedWidget_1->setCurrentIndex(1);
            ui->tbtSettingsExt->setChecked(false);
        }
    }
    else
    {
        ui->stackedWidget_1->setCurrentIndex(0);
        QString strFileName = "\\Templates\\";
        strFileName.append(strLastTemplate);
        FileSave(strFileName);
    }
}
//LOCK / UNLOCK Parameters
void MainWindow::on_tbtLock_clicked()
{
     accessControl->show();
}
// SYSTEM RESET - TwinCat RESET
void MainWindow::on_tbtReset_clicked()
{
    if(!boHMI_LOADED) return;
    ui->lblStatus->setText(actStatus->arrStatus[0]);
    ui->lblInfo->setText(actStatus->arrMessages[0]);
    ui->lblStatus->setStyleSheet("color: black; background-color: white;");
    ui->lblInfo->setStyleSheet("color: black; background-color: white;");
    emit signal_TwinCat_Reset();
}
//****************************************************************************
//**************************************************************************** NEW TEMPLATE
void MainWindow::on_btnNEW_RECEIPT_clicked()
{
    saveas_widget->show();
}

void MainWindow::set_template_name(QString name)
{
    for(int i=0; i< ui->tableWidget->rowCount(); i++)
    {
        qDebug()<<ui->tableWidget->rowCount();
        if(ui->tableWidget->itemAt(i, 0)->text() == name)
        {
            top_message->display("ERROR: THIS TEMPLATE NAME EXIST IN THE TABLE!");
            return;
        }
    }
    QString filename = "\\Templates\\";
    filename.append(name);
    filename.append(".par");
    FileSave(filename);
    BrowseFiles();
}
//=================================================================================  DELETE TEMPLATE

void MainWindow::on_btnDEL_RECEIPT_clicked()
{
    if(ui->lblSELECTED->text().isEmpty())
    {
        top_message->display("ERROR: SELECT A TEMPLATE FIRST!");
        return;
    }
    if(ui->lblSELECTED->text().contains("Template"))
    {
        top_message->display("ERROR: TEMPLATES CAN NOT BE DELETED!");
        return;
    }
    if(ui->lblSELECTED->text() == ui->lblTemplateName->text())
    {
        top_message->display("ERROR: THIS TEMPLATE IS IN USE!");
        return;
    }
    QString filename = "\\Templates\\";
    filename.append(ui->lblSELECTED->text());
    if(QFile::exists(filename))
    {
        QFile file(filename);
        if(!file.remove())
        {
            top_message->display("ERROR: SELECTED FILE WAS NOT DELETED!");
            return;
        }
    }
    else
    {
        top_message->display("ERROR: FILE NOT EXIST ON PHISICAL LOCATION!");
        return;
    }
    BrowseFiles();
}
//================================================================================= FILE LOADING
void MainWindow::on_btnLOAD_RECEIPT_clicked()
{
    if(ui->lblSELECTED->text().isEmpty())
    {
        top_message->display("ERROR: SELECT A TEMPLATE FIRST!");
        return;
    }    
    QString filename = "\\Templates\\";
    filename.append(ui->lblSELECTED->text());
    if(FileLoad(filename))
    {
        strLastTemplate = ui->lblSELECTED->text();
        ui->lblTemplateName->setText(strLastTemplate);
        QFile file("lt");
        if(file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            QTextStream out(&file);
            out<<ui->lblSELECTED->text();
            out<<"\n";
            out<<"\r";
            file.close();
        }
    }
    else
    {
        top_message->display("ERROR: SELECTED TEMPLATE WAS NOT LOADED!");
        return;
    }
}
//================================================================================ SELECT TEMPLATE
void MainWindow::on_tableWidget_cellClicked(int row, int column)
{
    ui->lblSELECTED->setText(ui->tableWidget->item(row, column)->text());
}
