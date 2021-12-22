#ifndef DIALOG_H
#define DIALOG_H

#include "ui_dialog.h"

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    explicit Dialog(double Min=0, double Max=1, int iMode = 0, QWidget *parent = 0);
signals:
    void Entered(QString atribute);
    void dEntered(double dvalue);
    void iEntered(int ivalue);
protected:
    void changeEvent(QEvent *e);

private slots:
    void on_CLEAR_pressed();

    void on_B_tire_pressed();

    void on_ENTER_pressed();

    void on_pushButton_pressed();

    void on_B_dot_pressed();

    void on_B_1_pressed();

    void on_B_2_pressed();

    void on_B_3_pressed();

    void on_B_4_pressed();

    void on_B_5_pressed();

    void on_B_6_pressed();

    void on_B_7_pressed();

    void on_B_8_pressed();

    void on_B_9_pressed();

    void on_B_0_pressed();

    void on_lineEdit_returnPressed();

private:
    int iValMode = 0;
    double ValMin = -999999;
    double ValMax =  999999;
    Ui::Dialog ui;
};

#endif // DIALOG_H
