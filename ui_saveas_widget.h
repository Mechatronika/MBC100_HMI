/********************************************************************************
** Form generated from reading UI file 'saveas_widget.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SAVEAS_WIDGET_H
#define UI_SAVEAS_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SaveAs_Widget
{
public:
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *text_field;
    QVBoxLayout *verticalLayout;
    QPushButton *btnClose;
    QPushButton *btnCLEAR;
    QPushButton *btnSAVE;

    void setupUi(QWidget *SaveAs_Widget)
    {
        if (SaveAs_Widget->objectName().isEmpty())
            SaveAs_Widget->setObjectName(QStringLiteral("SaveAs_Widget"));
        SaveAs_Widget->resize(800, 600);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SaveAs_Widget->sizePolicy().hasHeightForWidth());
        SaveAs_Widget->setSizePolicy(sizePolicy);
        SaveAs_Widget->setStyleSheet(QStringLiteral("background-color: rgb(222, 222, 222);"));
        verticalLayout_3 = new QVBoxLayout(SaveAs_Widget);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        text_field = new QLineEdit(SaveAs_Widget);
        text_field->setObjectName(QStringLiteral("text_field"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(text_field->sizePolicy().hasHeightForWidth());
        text_field->setSizePolicy(sizePolicy1);
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        text_field->setFont(font);
        text_field->setStyleSheet(QLatin1String("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);"));
        text_field->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(text_field);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        btnClose = new QPushButton(SaveAs_Widget);
        btnClose->setObjectName(QStringLiteral("btnClose"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(btnClose->sizePolicy().hasHeightForWidth());
        btnClose->setSizePolicy(sizePolicy2);
        QFont font1;
        font1.setPointSize(24);
        font1.setBold(true);
        font1.setWeight(75);
        btnClose->setFont(font1);
        btnClose->setStyleSheet(QStringLiteral("background-color: rgb(255, 0, 0);"));

        verticalLayout->addWidget(btnClose);

        btnCLEAR = new QPushButton(SaveAs_Widget);
        btnCLEAR->setObjectName(QStringLiteral("btnCLEAR"));
        sizePolicy2.setHeightForWidth(btnCLEAR->sizePolicy().hasHeightForWidth());
        btnCLEAR->setSizePolicy(sizePolicy2);
        btnCLEAR->setFont(font1);
        btnCLEAR->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 255);"));

        verticalLayout->addWidget(btnCLEAR);

        btnSAVE = new QPushButton(SaveAs_Widget);
        btnSAVE->setObjectName(QStringLiteral("btnSAVE"));
        sizePolicy2.setHeightForWidth(btnSAVE->sizePolicy().hasHeightForWidth());
        btnSAVE->setSizePolicy(sizePolicy2);
        btnSAVE->setFont(font1);
        btnSAVE->setStyleSheet(QStringLiteral("background-color: rgb(0, 255, 127);"));

        verticalLayout->addWidget(btnSAVE);


        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_3->addLayout(horizontalLayout);


        retranslateUi(SaveAs_Widget);

        QMetaObject::connectSlotsByName(SaveAs_Widget);
    } // setupUi

    void retranslateUi(QWidget *SaveAs_Widget)
    {
        SaveAs_Widget->setWindowTitle(QApplication::translate("SaveAs_Widget", "Form", nullptr));
        btnClose->setText(QApplication::translate("SaveAs_Widget", " CLOSE ", nullptr));
        btnCLEAR->setText(QApplication::translate("SaveAs_Widget", " CLEAR ", nullptr));
        btnSAVE->setText(QApplication::translate("SaveAs_Widget", " SAVE ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SaveAs_Widget: public Ui_SaveAs_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SAVEAS_WIDGET_H
