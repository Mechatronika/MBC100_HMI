/********************************************************************************
** Form generated from reading UI file 'loadingform.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOADINGFORM_H
#define UI_LOADINGFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoadingForm
{
public:
    QProgressBar *progressBar;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QWidget *LoadingForm)
    {
        if (LoadingForm->objectName().isEmpty())
            LoadingForm->setObjectName(QStringLiteral("LoadingForm"));
        LoadingForm->resize(1280, 800);
        LoadingForm->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));
        progressBar = new QProgressBar(LoadingForm);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(20, 15, 1236, 64));
        progressBar->setMinimumSize(QSize(0, 64));
        progressBar->setStyleSheet(QLatin1String("color: rgb(0, 170, 0);\n"
"background-color: rgb(85, 255, 127);"));
        progressBar->setValue(24);
        label = new QLabel(LoadingForm);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(60, 15, 1146, 701));
        label->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/Icones/Logo_Trans.png")));
        label->setScaledContents(false);
        label_2 = new QLabel(LoadingForm);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(140, 680, 981, 41));
        QFont font;
        font.setPointSize(18);
        label_2->setFont(font);
        label_2->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 0);"));
        label_2->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(LoadingForm);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(395, 720, 506, 51));
        label_3->setFont(font);
        label_3->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 0);"));
        label_3->setAlignment(Qt::AlignCenter);
        label->raise();
        progressBar->raise();
        label_2->raise();
        label_3->raise();

        retranslateUi(LoadingForm);

        QMetaObject::connectSlotsByName(LoadingForm);
    } // setupUi

    void retranslateUi(QWidget *LoadingForm)
    {
        LoadingForm->setWindowTitle(QApplication::translate("LoadingForm", "Form", nullptr));
        label->setText(QString());
        label_2->setText(QApplication::translate("LoadingForm", "Designed by: Krasimir Krastev - this is an open source software under GPL 3.0 license", nullptr));
        label_3->setText(QApplication::translate("LoadingForm", "e-mail: krasimir.krustev@yahoo.com", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoadingForm: public Ui_LoadingForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOADINGFORM_H
