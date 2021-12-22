#ifndef SAVEAS_WIDGET_H
#define SAVEAS_WIDGET_H

#include <QWidget>
#include <QList>
#include <QFrame>
#include <QPushButton>
#include <QGridLayout>

//********************************** KeyPad Button
class KeypadButton : public QPushButton
    {
        Q_OBJECT
    public:
        KeypadButton(char symbol, QWidget *parent): QPushButton(parent)
        {
            button_symbol = symbol;
            setText(QString(button_symbol));
            connect(this, SIGNAL(pressed()), this, SLOT(is_pressed()));
        }

    signals:
        void key_pressed(char);

    private slots:
        void is_pressed()
        {
             emit key_pressed(button_symbol);
        }

    private:
        char button_symbol;
    };

//*************************************************
namespace Ui {
class SaveAs_Widget;
}

class SaveAs_Widget : public QWidget
{
    Q_OBJECT

public:
    explicit SaveAs_Widget(QWidget *parent = nullptr);
    ~SaveAs_Widget();        

public slots:
    void key_pressed(char);

private slots:
    void on_btnClose_clicked();

    void on_btnCLEAR_clicked();

    void on_btnSAVE_clicked();

    void on_text_field_returnPressed();

signals:
    void set_template_name(QString);

private:
    Ui::SaveAs_Widget *ui;
    QList<QPushButton*> abc_list;



};

#endif // SAVEAS_WIDGET_H
