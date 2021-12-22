/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QLabel *labelMINMAX;
    QLineEdit *lineEdit;
    QPushButton *B_4;
    QPushButton *B_3;
    QPushButton *B_6;
    QPushButton *B_9;
    QPushButton *B_8;
    QPushButton *B_7;
    QPushButton *B_5;
    QPushButton *B_1;
    QPushButton *B_2;
    QPushButton *B_tire;
    QPushButton *B_dot;
    QPushButton *B_0;
    QPushButton *ENTER;
    QPushButton *CLEAR;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(480, 640);
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setUnderline(true);
        font.setWeight(75);
        Dialog->setFont(font);
        Dialog->setWindowTitle(QStringLiteral("Dialog"));
        Dialog->setStyleSheet(QLatin1String("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(141, 141, 141, 255));\n"
"color: rgb(0, 170, 255);"));
        Dialog->setWindowFilePath(QStringLiteral(""));
        gridLayout = new QGridLayout(Dialog);
        gridLayout->setSpacing(1);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(1, 1, 1, 1);
        pushButton = new QPushButton(Dialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setFamily(QStringLiteral("Arial Black"));
        font1.setPointSize(28);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        pushButton->setFont(font1);
        pushButton->setStyleSheet(QStringLiteral(""));
        pushButton->setText(QStringLiteral("X"));
        pushButton->setFlat(false);

        gridLayout->addWidget(pushButton, 7, 1, 1, 1);

        labelMINMAX = new QLabel(Dialog);
        labelMINMAX->setObjectName(QStringLiteral("labelMINMAX"));
        QFont font2;
        font2.setFamily(QStringLiteral("MS Shell Dlg 2"));
        font2.setPointSize(12);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(50);
        labelMINMAX->setFont(font2);
        labelMINMAX->setStyleSheet(QLatin1String("color: rgb(0, 170, 255);\n"
"font: 12pt \"MS Shell Dlg 2\";"));
        labelMINMAX->setText(QStringLiteral(""));

        gridLayout->addWidget(labelMINMAX, 1, 0, 1, 3);

        lineEdit = new QLineEdit(Dialog);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy1);
        QFont font3;
        font3.setFamily(QStringLiteral("Arial Black"));
        font3.setPointSize(36);
        font3.setBold(false);
        font3.setItalic(false);
        font3.setWeight(10);
        lineEdit->setFont(font3);
        lineEdit->setMouseTracking(false);
        lineEdit->setFocusPolicy(Qt::StrongFocus);
        lineEdit->setStyleSheet(QLatin1String("background-color: rgb(0, 0, 0);\n"
"color: rgb(255, 255, 255);\n"
"font: 87 36pt \"Arial Black\";"));
        lineEdit->setInputMask(QStringLiteral(""));
        lineEdit->setText(QStringLiteral(""));
        lineEdit->setFrame(false);
        lineEdit->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEdit, 0, 0, 1, 4);

        B_4 = new QPushButton(Dialog);
        B_4->setObjectName(QStringLiteral("B_4"));
        sizePolicy.setHeightForWidth(B_4->sizePolicy().hasHeightForWidth());
        B_4->setSizePolicy(sizePolicy);
        B_4->setFont(font3);
        B_4->setStyleSheet(QStringLiteral("font: 87 36pt \"Arial Black\";"));
        B_4->setText(QStringLiteral("4"));
        B_4->setFlat(false);

        gridLayout->addWidget(B_4, 3, 0, 1, 1);

        B_3 = new QPushButton(Dialog);
        B_3->setObjectName(QStringLiteral("B_3"));
        sizePolicy.setHeightForWidth(B_3->sizePolicy().hasHeightForWidth());
        B_3->setSizePolicy(sizePolicy);
        B_3->setFont(font3);
        B_3->setStyleSheet(QStringLiteral("font: 87 36pt \"Arial Black\";"));
        B_3->setText(QStringLiteral("3"));
        B_3->setFlat(false);

        gridLayout->addWidget(B_3, 4, 2, 1, 1);

        B_6 = new QPushButton(Dialog);
        B_6->setObjectName(QStringLiteral("B_6"));
        sizePolicy.setHeightForWidth(B_6->sizePolicy().hasHeightForWidth());
        B_6->setSizePolicy(sizePolicy);
        B_6->setFont(font3);
        B_6->setStyleSheet(QStringLiteral("font: 87 36pt \"Arial Black\";"));
        B_6->setText(QStringLiteral("6"));
        B_6->setFlat(false);

        gridLayout->addWidget(B_6, 3, 2, 1, 1);

        B_9 = new QPushButton(Dialog);
        B_9->setObjectName(QStringLiteral("B_9"));
        sizePolicy.setHeightForWidth(B_9->sizePolicy().hasHeightForWidth());
        B_9->setSizePolicy(sizePolicy);
        B_9->setFont(font3);
        B_9->setStyleSheet(QStringLiteral("font: 87 36pt \"Arial Black\";"));
        B_9->setText(QStringLiteral("9"));
        B_9->setFlat(false);

        gridLayout->addWidget(B_9, 2, 2, 1, 1);

        B_8 = new QPushButton(Dialog);
        B_8->setObjectName(QStringLiteral("B_8"));
        sizePolicy.setHeightForWidth(B_8->sizePolicy().hasHeightForWidth());
        B_8->setSizePolicy(sizePolicy);
        B_8->setFont(font3);
        B_8->setStyleSheet(QStringLiteral("font: 87 36pt \"Arial Black\";"));
        B_8->setText(QStringLiteral("8"));
        B_8->setFlat(false);

        gridLayout->addWidget(B_8, 2, 1, 1, 1);

        B_7 = new QPushButton(Dialog);
        B_7->setObjectName(QStringLiteral("B_7"));
        sizePolicy.setHeightForWidth(B_7->sizePolicy().hasHeightForWidth());
        B_7->setSizePolicy(sizePolicy);
        B_7->setFont(font3);
        B_7->setStyleSheet(QStringLiteral("font: 87 36pt \"Arial Black\";"));
        B_7->setText(QStringLiteral("7"));
        B_7->setFlat(false);

        gridLayout->addWidget(B_7, 2, 0, 1, 1);

        B_5 = new QPushButton(Dialog);
        B_5->setObjectName(QStringLiteral("B_5"));
        sizePolicy.setHeightForWidth(B_5->sizePolicy().hasHeightForWidth());
        B_5->setSizePolicy(sizePolicy);
        B_5->setFont(font3);
        B_5->setStyleSheet(QStringLiteral("font: 87 36pt \"Arial Black\";"));
        B_5->setText(QStringLiteral("5"));
        B_5->setFlat(false);

        gridLayout->addWidget(B_5, 3, 1, 1, 1);

        B_1 = new QPushButton(Dialog);
        B_1->setObjectName(QStringLiteral("B_1"));
        sizePolicy.setHeightForWidth(B_1->sizePolicy().hasHeightForWidth());
        B_1->setSizePolicy(sizePolicy);
        B_1->setFont(font3);
        B_1->setStyleSheet(QStringLiteral("font: 87 36pt \"Arial Black\";"));
        B_1->setText(QStringLiteral("1"));
        B_1->setFlat(false);

        gridLayout->addWidget(B_1, 4, 0, 1, 1);

        B_2 = new QPushButton(Dialog);
        B_2->setObjectName(QStringLiteral("B_2"));
        sizePolicy.setHeightForWidth(B_2->sizePolicy().hasHeightForWidth());
        B_2->setSizePolicy(sizePolicy);
        B_2->setFont(font3);
        B_2->setStyleSheet(QStringLiteral("font: 87 36pt \"Arial Black\";"));
        B_2->setText(QStringLiteral("2"));
        B_2->setFlat(false);

        gridLayout->addWidget(B_2, 4, 1, 1, 1);

        B_tire = new QPushButton(Dialog);
        B_tire->setObjectName(QStringLiteral("B_tire"));
        sizePolicy.setHeightForWidth(B_tire->sizePolicy().hasHeightForWidth());
        B_tire->setSizePolicy(sizePolicy);
        B_tire->setFont(font3);
        B_tire->setStyleSheet(QStringLiteral("font: 87 36pt \"Arial Black\";"));
        B_tire->setText(QStringLiteral("-"));
        B_tire->setFlat(false);

        gridLayout->addWidget(B_tire, 6, 0, 1, 1);

        B_dot = new QPushButton(Dialog);
        B_dot->setObjectName(QStringLiteral("B_dot"));
        sizePolicy.setHeightForWidth(B_dot->sizePolicy().hasHeightForWidth());
        B_dot->setSizePolicy(sizePolicy);
        B_dot->setFont(font3);
        B_dot->setStyleSheet(QStringLiteral("font: 87 36pt \"Arial Black\";"));
        B_dot->setText(QStringLiteral("."));
        B_dot->setFlat(false);

        gridLayout->addWidget(B_dot, 6, 2, 1, 1);

        B_0 = new QPushButton(Dialog);
        B_0->setObjectName(QStringLiteral("B_0"));
        sizePolicy.setHeightForWidth(B_0->sizePolicy().hasHeightForWidth());
        B_0->setSizePolicy(sizePolicy);
        B_0->setFont(font3);
        B_0->setStyleSheet(QLatin1String("font: 75 28pt \"MS Shell Dlg 2\";\n"
"font: 87 36pt \"Arial Black\";"));
        B_0->setText(QStringLiteral("0"));
        B_0->setFlat(false);

        gridLayout->addWidget(B_0, 6, 1, 1, 1);

        ENTER = new QPushButton(Dialog);
        ENTER->setObjectName(QStringLiteral("ENTER"));
        sizePolicy.setHeightForWidth(ENTER->sizePolicy().hasHeightForWidth());
        ENTER->setSizePolicy(sizePolicy);
        ENTER->setMinimumSize(QSize(0, 0));
        QFont font4;
        font4.setFamily(QStringLiteral("Arial Black"));
        font4.setPointSize(20);
        font4.setBold(false);
        font4.setItalic(false);
        font4.setWeight(10);
        ENTER->setFont(font4);
        ENTER->setStyleSheet(QStringLiteral(""));
        ENTER->setText(QStringLiteral("ENTER >"));
        ENTER->setFlat(false);

        gridLayout->addWidget(ENTER, 7, 2, 1, 1);

        CLEAR = new QPushButton(Dialog);
        CLEAR->setObjectName(QStringLiteral("CLEAR"));
        sizePolicy.setHeightForWidth(CLEAR->sizePolicy().hasHeightForWidth());
        CLEAR->setSizePolicy(sizePolicy);
        CLEAR->setFont(font1);
        CLEAR->setStyleSheet(QStringLiteral(""));
        CLEAR->setText(QStringLiteral("CL"));
        CLEAR->setFlat(false);

        gridLayout->addWidget(CLEAR, 7, 0, 1, 1);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Q_UNUSED(Dialog);
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
