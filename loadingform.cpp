#include "loadingform.h"
#include "ui_loadingform.h"

LoadingForm::LoadingForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoadingForm)
{
    ui->setupUi(this);
    ui->progressBar->setValue(0);
}

LoadingForm::~LoadingForm()
{
    delete ui;
}

void LoadingForm::putProgress(int value)
{
    ui->progressBar->setValue(value);
}
