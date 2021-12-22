#ifndef ACCESSCONTROL_H
#define ACCESSCONTROL_H

#include <QDialog>
#include <QFile>
#include <QTextStream>
#include <NumpadDialogue/dialog.h>

namespace Ui {
class AccessControl;
}

class AccessControl : public QDialog
{
    Q_OBJECT

public:
    explicit AccessControl( QWidget *parent = nullptr);
    ~AccessControl();
    bool Access;

signals:
    void lockSignal();
    void unlockSignal();
    void exit_toWindows();

private slots:
    void on_btnBack_pressed();

    void on_btnClear_pressed();

    void on_btn0_pressed();

    void on_btn1_pressed();

    void on_btn2_pressed();

    void on_btn3_pressed();

    void on_btn4_pressed();

    void on_btn5_pressed();

    void on_btn6_pressed();

    void on_btn7_pressed();

    void on_btn8_pressed();

    void on_btn9_pressed();

    void on_btnLock_pressed();

    void on_btnUnlock_pressed();

    void on_btnEnter_pressed();

    void on_btnBack_2_pressed();

    void on_btnBack_3_pressed();

    void on_btnEnter_2_pressed();

    void on_btnClear_3_pressed();

    void on_btnClear_2_pressed();

    void on_btn0_2_pressed();

    void on_btn1_2_pressed();

    void on_btn2_2_pressed();

    void on_btn3_2_pressed();

    void on_btn4_2_pressed();

    void on_btn5_2_pressed();

    void on_btn6_2_pressed();

    void on_btn7_2_pressed();

    void on_btn8_2_pressed();

    void on_btn9_2_pressed();

    void on_btn0_3_pressed();

    void on_btn1_3_pressed();

    void on_btn2_3_pressed();

    void on_btn3_3_pressed();

    void on_btn4_3_pressed();

    void on_btn5_3_pressed();

    void on_btn6_3_pressed();

    void on_btn7_3_pressed();

    void on_btn8_3_pressed();

    void on_btn9_3_pressed();

    void on_btnSettings_pressed();

    void on_btnEnter_3_pressed();

    void on_btnClose_pressed();

    void on_btnExitToWindows_clicked();

private:
    Ui::AccessControl *ui;
    QString strPassword;
    QString strOldPassword;
    QString strNewPassword;
    QString strAccessPassword;
};

#endif // ACCESSCONTROL_H
