#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QDir>
#include <QFile>
#include <QFileDialog>
#include <QTimer>
#include <QDateTime>
#include <BeckhoffADS/AdsStructures.h>
#include <BeckhoffADS/adsworker.h>
#include <NumpadDialogue/dialog.h>
#include <QtCharts>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QScatterSeries>
#include <accesscontrol.h>
#include <saveas_widget.h>
#include <status.h>
#include <loadingform.h>
#include <topmessage.h>

#define byEnables_Gen1 1
#define byEnables_Gen2 2
#define byAutomatic_Gen1 3
#define byAutomatic_Gen2 4
#define byEnables_Servo1 5
#define byEnables_Servo2 6

#define lrParameters_EncRollDiam 1
#define lrParameters_ExtRollDiam 2
#define lrParameters_IntRollDiam 3
#define lrParameters_minGen1 6
#define lrParameters_maxGen1 7
#define lrParameters_minGen2 8
#define lrParameters_maxGen2 9
#define lrParameters_LenghtCor_1 10
#define lrParameters_PowerCor_1 11
#define lrParameters_LenghtCor_2 12
#define lrParameters_PowerCor_2 13

//******************************* File Writer ********************************

class filewriter : public QThread
{
    Q_OBJECT

public:
    QString time; QString sid; QString status; QString iid; QString info;
    filewriter(QString strFilePath)
    {
        strFileName = strFilePath;
    }
    ~filewriter()
    {
        this->disconnect(this, SIGNAL(finished()), this, SLOT(deleteLater()));
        this->deleteLater();
    }

private:
    QString strFileName = "\\LogFiles\\HistoryLog_Unknown";
    void run()
    {
        QFile file(strFileName);
        file.open(QIODevice::WriteOnly | QIODevice::Append);
        QTextStream out(&file);
        out << time     << QString::fromUtf8(" ; ")
            << sid      << QString::fromUtf8(" ; ")
            << status   << QString::fromUtf8(" ; ")
            << iid      << QString::fromUtf8(" ; ")
            << info     << QString::fromUtf8("\r\n");
        file.close();
    }
};
//*********************************************************************************************

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    virtual bool eventFilter(QObject *object, QEvent *ev);

private slots:
    void updateHMI();
    void tmrTimeout();    
    void lockSignal();
    void unlockSignal();
    void exit_toWindows();
    void settings_EnableGen1_Checked(bool flag);
    void settings_EnableGen2_Checked(bool flag);
    void settings_AutoPower1_Checked(bool flag);
    void settings_AutoPower2_Checked(bool flag);
    void settings_EnableServo1_Checked(bool flag);
    void settings_EnableServo2_Checked(bool flag);
    void settings_minGen1_Changed(int value);
    void settings_maxGen1_Changed(int value);
    void settings_minGen2_Changed(int value);
    void settings_maxGen2_Changed(int value);
    void setEncoderDiameter(double value);
    void setExternalDiameter(double value);
    void setInternalDiameter(double value);
    void setLenghtCorr_1(double value);
    void setPowerCorr_1(double value);
    void setLenghtCorr_2(double value);
    void setPowerCorr_2(double value);

    void on_tbtTemplates_pressed();

    void on_pES_pressed();

    void on_nES_pressed();

    void on_pIS_pressed();

    void on_nIS_pressed();

    void on_tbtSettingsExt_toggled(bool checked);

    void on_tbtSettingsInt_toggled(bool checked);

    void on_tbtLock_clicked();

    void on_tbtReset_clicked();

    void on_btnNEW_RECEIPT_clicked();

    void set_template_name(QString);

    void on_btnDEL_RECEIPT_clicked();

    void on_btnLOAD_RECEIPT_clicked();

    void on_tableWidget_cellClicked(int row, int column);

signals:
    void signal_TwinCat_Reset();

private:
    bool                boCharts;
    bool                boHMI_LOADED;
    int                 iHMIStep = 0;
    int                 iInitStep;
    int                 iNoTriesTwinCat;    
    QString             strFirstTime;
    Ui::MainWindow      *ui;
    AccessControl       *accessControl;
    SaveAs_Widget       *saveas_widget;
    ADSworker           *wAdsWorker;   
    Status              *actStatus;    
    LoadingForm         *loadingForm;
    TopMessage          *top_message;
    QTimer              *tmr;

    QChart              *chart1;
    QChart              *chart2;
    QChartView          *chartView1;
    QChartView          *chartView2;    
    QFont               chartFont;
    QString             strLastTemplate = "Parameters.par";
    QString             strPowerLabel = "Power [%]: ";
    QString             strVelocityLabel = "Velocity [mm/s]: ";
    QDate               date;                         //Actual Date
    QTime               time;                         //Actual Time
    filewriter *fw;
    QString strPath = "\\LogFiles\\History";
    void updateCharts();                            // Updating the Chart
    void BrowseFiles();                             // Browse for Template Files
    void FileSave(QString filepath);                                // Parameter File Save
    bool FileLoad(QString filepath);                // Parameter File Reading
};

#endif // MAINWINDOW_H
