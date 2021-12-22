#include "saveas_widget.h"
#include "ui_saveas_widget.h"

SaveAs_Widget::SaveAs_Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SaveAs_Widget)
{
    ui->setupUi(this);    
    char abc_chars[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ_";   
    QFrame *key_frame = new QFrame;
    QGridLayout *abc_layout = new QGridLayout;
    int i_size = sizeof(abc_chars) - 1;
    int row, col;
    row = col = 0;   
    // ABC keyboard Init
    for(int i=0; i<i_size; i++)
    {
        abc_list.append(new KeypadButton(abc_chars[i], this));
        abc_list.at(i)->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        connect(abc_list.at(i), SIGNAL(key_pressed(char)), this, SLOT(key_pressed(char)));
        abc_layout->addWidget(abc_list.at(i), row, col, 1, 1);
        col++;
        if(col>9)
        {
            row++;
            col = 0;
        }
    }   
    abc_layout->setSpacing(1);
    key_frame->setLayout(abc_layout);
    this->layout()->addWidget(key_frame);
    ui->text_field->setStyleSheet("color: black; background-color: white");
}

SaveAs_Widget::~SaveAs_Widget()
{
    delete ui;
}

void SaveAs_Widget::key_pressed(char symbol)
{
    ui->text_field->setText(ui->text_field->text().append(symbol));
}

void SaveAs_Widget::on_btnClose_clicked()
{
    ui->text_field->clear();
    this->close();
}

void SaveAs_Widget::on_btnCLEAR_clicked()
{
    ui->text_field->clear();
}

void SaveAs_Widget::on_btnSAVE_clicked()
{
    emit set_template_name(ui->text_field->text());
    this->hide();
}

void SaveAs_Widget::on_text_field_returnPressed()
{
    emit set_template_name(ui->text_field->text());
    this->hide();
}
