#include "accesscontrol.h"
#include "ui_accesscontrol.h"

AccessControl::AccessControl(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AccessControl)
{
    ui->setupUi(this);
    Access = false;
    strPassword = "";
    strNewPassword = "";
    strOldPassword = "";
    strAccessPassword = "";

    ui->lineNewPassword->clear();
    ui->lineOldPassword->clear();
    ui->linePassword->clear();
    ui->lineNewPassword->setStyleSheet("background-color: white");
    ui->lineOldPassword->setStyleSheet("background-color: white");
    ui->linePassword->setStyleSheet("background-color: white");

    ui->btnExitToWindows->hide();
    ui->stackedWidget->setCurrentIndex(0);

    if(QFile::exists("pw"))
    {
        QFile file("pw");
        if(file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QTextStream in(&file);
            strAccessPassword = in.readLine();
            strAccessPassword.remove("\n");            
            strAccessPassword.remove("\r");
                    //write(ui->lineNewPassword->text().toUtf8(), sizeof(ui->lineNewPassword->text().toUtf8()));
            file.close();
        }
        else
        {            
            strAccessPassword = "1";
        }
    }
    else
    {
        strAccessPassword = "1";
    }

}

AccessControl::~AccessControl()
{
    delete ui;
}

void AccessControl::on_btnBack_pressed()
{
    strPassword = "";
    ui->linePassword->setStyleSheet("background-color: white");
    ui->linePassword->clear();
    ui->stackedWidget->setCurrentIndex(0);
}

void AccessControl::on_btnClear_pressed()
{
    strPassword = "";
    ui->linePassword->setStyleSheet("background-color: white");
    ui->linePassword->clear();
}

void AccessControl::on_btn0_pressed()
{
    strPassword.append("0");
    ui->linePassword->setText(strPassword);
}

void AccessControl::on_btn1_pressed()
{
    strPassword.append("1");
    ui->linePassword->setText(strPassword);
}

void AccessControl::on_btn2_pressed()
{
    strPassword.append("2");
    ui->linePassword->setText(strPassword);
}

void AccessControl::on_btn3_pressed()
{
    strPassword.append("3");
    ui->linePassword->setText(strPassword);
}

void AccessControl::on_btn4_pressed()
{
    strPassword.append("4");
    ui->linePassword->setText(strPassword);
}

void AccessControl::on_btn5_pressed()
{
    strPassword.append("5");
    ui->linePassword->setText(strPassword);
}

void AccessControl::on_btn6_pressed()
{
    strPassword.append("6");
    ui->linePassword->setText(strPassword);
}

void AccessControl::on_btn7_pressed()
{
    strPassword.append("7");
    ui->linePassword->setText(strPassword);
}

void AccessControl::on_btn8_pressed()
{
    strPassword.append("8");
    ui->linePassword->setText(strPassword);
}

void AccessControl::on_btn9_pressed()
{
    strPassword.append("9");
    ui->linePassword->setText(strPassword);
}

void AccessControl::on_btnLock_pressed()
{
    strPassword = "";
    Access = false;
    ui->btnExitToWindows->hide();
    emit lockSignal();
    this->hide();
}

void AccessControl::on_btnUnlock_pressed()
{    
    strPassword = "";
    ui->linePassword->setText("");
    ui->linePassword->setStyleSheet("background-color: white");
    ui->stackedWidget->setCurrentIndex(1);
}

void AccessControl::on_btnEnter_pressed()
{
    if(strPassword == strAccessPassword)
    {
        strPassword = "";
        ui->linePassword->setText("");
        ui->linePassword->setStyleSheet("background-color: white");
        ui->stackedWidget->setCurrentIndex(0);
        ui->btnExitToWindows->show();
        Access = true;
        emit unlockSignal();
        this->hide();
    }
    else
    {
        ui->linePassword->setStyleSheet("background-color: red");
    }
}

void AccessControl::on_btnBack_2_pressed()
{
    strOldPassword = "";
    ui->lineOldPassword->clear();
    ui->lineOldPassword->setStyleSheet("background-color: white");
     ui->stackedWidget->setCurrentIndex(0);
}

void AccessControl::on_btnBack_3_pressed()
{
    strNewPassword = "";
    ui->lineNewPassword->clear();
    ui->lineNewPassword->setStyleSheet("background-color: white");
    ui->stackedWidget->setCurrentIndex(0);
}

void AccessControl::on_btnEnter_2_pressed()
{
    if(ui->lineOldPassword->text() == strAccessPassword)
    {
        ui->lineOldPassword->setText("");
        ui->lineOldPassword->setStyleSheet("background-color: white");
        ui->stackedWidget->setCurrentIndex(3);
    }
    else
    {
        ui->lineOldPassword->setStyleSheet("background-color: red");
    }
}

void AccessControl::on_btnClear_3_pressed()
{
   strNewPassword = "";
   ui->lineNewPassword->clear();
   ui->lineNewPassword->setStyleSheet("background-color: white");
}

void AccessControl::on_btnClear_2_pressed()
{
    strOldPassword = "";
    ui->lineOldPassword->clear();
    ui->lineOldPassword->setStyleSheet("background-color: white");
}

void AccessControl::on_btn0_2_pressed()
{
    strOldPassword.append("0");
    ui->lineOldPassword->setText(strOldPassword);
}

void AccessControl::on_btn1_2_pressed()
{
    strOldPassword.append("1");
    ui->lineOldPassword->setText(strOldPassword);
}

void AccessControl::on_btn2_2_pressed()
{
    strOldPassword.append("2");
    ui->lineOldPassword->setText(strOldPassword);
}

void AccessControl::on_btn3_2_pressed()
{
    strOldPassword.append("3");
    ui->lineOldPassword->setText(strOldPassword);
}

void AccessControl::on_btn4_2_pressed()
{
    strOldPassword.append("4");
    ui->lineOldPassword->setText(strOldPassword);
}

void AccessControl::on_btn5_2_pressed()
{
    strOldPassword.append("5");
    ui->lineOldPassword->setText(strOldPassword);
}

void AccessControl::on_btn6_2_pressed()
{
    strOldPassword.append("6");
    ui->lineOldPassword->setText(strOldPassword);
}

void AccessControl::on_btn7_2_pressed()
{
    strOldPassword.append("7");
    ui->lineOldPassword->setText(strOldPassword);
}

void AccessControl::on_btn8_2_pressed()
{
    strOldPassword.append("8");
    ui->lineOldPassword->setText(strOldPassword);
}

void AccessControl::on_btn9_2_pressed()
{
    strOldPassword.append("9");
    ui->lineOldPassword->setText(strOldPassword);
}

void AccessControl::on_btn0_3_pressed()
{
    strNewPassword.append("0");
    ui->lineNewPassword->setText(strNewPassword);
}

void AccessControl::on_btn1_3_pressed()
{
    strNewPassword.append("1");
    ui->lineNewPassword->setText(strNewPassword);
}

void AccessControl::on_btn2_3_pressed()
{
    strNewPassword.append("2");
    ui->lineNewPassword->setText(strNewPassword);
}

void AccessControl::on_btn3_3_pressed()
{
    strNewPassword.append("3");
    ui->lineNewPassword->setText(strNewPassword);
}

void AccessControl::on_btn4_3_pressed()
{
    strNewPassword.append("4");
    ui->lineNewPassword->setText(strNewPassword);
}

void AccessControl::on_btn5_3_pressed()
{
    strNewPassword.append("5");
    ui->lineNewPassword->setText(strNewPassword);
}

void AccessControl::on_btn6_3_pressed()
{
    strNewPassword.append("6");
    ui->lineNewPassword->setText(strNewPassword);
}

void AccessControl::on_btn7_3_pressed()
{
    strNewPassword.append("7");
    ui->lineNewPassword->setText(strNewPassword);
}

void AccessControl::on_btn8_3_pressed()
{
    strNewPassword.append("8");
    ui->lineNewPassword->setText(strNewPassword);
}

void AccessControl::on_btn9_3_pressed()
{
    strNewPassword.append("9");
    ui->lineNewPassword->setText(strNewPassword);
}

void AccessControl::on_btnSettings_pressed()
{
    strOldPassword = "";
    ui->lineOldPassword->clear();
    ui->lineOldPassword->setStyleSheet("background-color: white");
    strNewPassword = "";
    ui->lineNewPassword->clear();
    ui->lineNewPassword->setStyleSheet("background-color: white");
    ui->stackedWidget->setCurrentIndex(2);
}

void AccessControl::on_btnEnter_3_pressed()
{
    QFile file("pw");
    if(file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream out(&file);
        out<<ui->lineNewPassword->text();
        out<<"\n";
        file.close();
    }
    strAccessPassword = ui->lineNewPassword->text();
    ui->stackedWidget->setCurrentIndex(0);
    this->hide();
}

void AccessControl::on_btnClose_pressed()
{    
    this->hide();
}

void AccessControl::on_btnExitToWindows_clicked()
{
    Access = false;
    emit exit_toWindows();
}
