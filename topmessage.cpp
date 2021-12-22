#include "topmessage.h"
#include "ui_topmessage.h"

TopMessage::TopMessage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TopMessage)
{
    ui->setupUi(this);
}

TopMessage::~TopMessage()
{
    delete ui;
}

void TopMessage::on_pushButton_clicked()
{
    ui->label->clear();
    this->hide();
}

void TopMessage::display(QString message)
{
    ui->label->setText(message);
    this->show();
}
