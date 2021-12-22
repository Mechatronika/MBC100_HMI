/********************************************************************************
** Form generated from reading UI file 'accesscontrol.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACCESSCONTROL_H
#define UI_ACCESSCONTROL_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AccessControl
{
public:
    QGridLayout *gridLayout;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QVBoxLayout *verticalLayout;
    QPushButton *btnLock;
    QPushButton *btnUnlock;
    QPushButton *btnExitToWindows;
    QPushButton *btnSettings;
    QPushButton *btnClose;
    QWidget *page_2;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout_2;
    QToolButton *btn5;
    QToolButton *btn4;
    QToolButton *btn2;
    QToolButton *btn6;
    QToolButton *btnClear;
    QToolButton *btn1;
    QToolButton *btnEnter;
    QToolButton *btn3;
    QToolButton *btn7;
    QToolButton *btn9;
    QToolButton *btn8;
    QToolButton *btn0;
    QHBoxLayout *horizontalLayout;
    QToolButton *btnBack;
    QLineEdit *linePassword;
    QLabel *label_3;
    QWidget *page_3;
    QGridLayout *gridLayout_4;
    QVBoxLayout *verticalLayout_6;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *btnBack_2;
    QLineEdit *lineOldPassword;
    QToolButton *btn5_2;
    QToolButton *btnClear_2;
    QToolButton *btn6_2;
    QToolButton *btn2_2;
    QToolButton *btn4_2;
    QToolButton *btn3_2;
    QToolButton *btn0_2;
    QToolButton *btn1_2;
    QToolButton *btn7_2;
    QToolButton *btnEnter_2;
    QToolButton *btn9_2;
    QToolButton *btn8_2;
    QLabel *label;
    QWidget *page_6;
    QGridLayout *gridLayout_6;
    QVBoxLayout *verticalLayout_7;
    QGridLayout *gridLayout_5;
    QHBoxLayout *horizontalLayout_3;
    QToolButton *btnBack_3;
    QLineEdit *lineNewPassword;
    QToolButton *btn5_3;
    QToolButton *btnClear_3;
    QToolButton *btn6_3;
    QToolButton *btn2_3;
    QToolButton *btn4_3;
    QToolButton *btn3_3;
    QToolButton *btn0_3;
    QToolButton *btn1_3;
    QToolButton *btn7_3;
    QToolButton *btnEnter_3;
    QToolButton *btn9_3;
    QToolButton *btn8_3;
    QLabel *label_2;

    void setupUi(QDialog *AccessControl)
    {
        if (AccessControl->objectName().isEmpty())
            AccessControl->setObjectName(QStringLiteral("AccessControl"));
        AccessControl->resize(480, 480);
        gridLayout = new QGridLayout(AccessControl);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(1, 1, 1, 1);
        stackedWidget = new QStackedWidget(AccessControl);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setFrameShape(QFrame::Box);
        stackedWidget->setFrameShadow(QFrame::Raised);
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        verticalLayout = new QVBoxLayout(page);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        btnLock = new QPushButton(page);
        btnLock->setObjectName(QStringLiteral("btnLock"));
        btnLock->setEnabled(true);
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        btnLock->setFont(font);
        btnLock->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/prefix1/Icones/Lock_128.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnLock->setIcon(icon);
        btnLock->setIconSize(QSize(128, 64));

        verticalLayout->addWidget(btnLock);

        btnUnlock = new QPushButton(page);
        btnUnlock->setObjectName(QStringLiteral("btnUnlock"));
        btnUnlock->setFont(font);
        btnUnlock->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/new/prefix1/Icones/Unlock_128.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnUnlock->setIcon(icon1);
        btnUnlock->setIconSize(QSize(128, 64));

        verticalLayout->addWidget(btnUnlock);

        btnExitToWindows = new QPushButton(page);
        btnExitToWindows->setObjectName(QStringLiteral("btnExitToWindows"));
        btnExitToWindows->setFont(font);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/new/prefix1/Icones/Exit_256.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnExitToWindows->setIcon(icon2);
        btnExitToWindows->setIconSize(QSize(128, 64));

        verticalLayout->addWidget(btnExitToWindows);

        btnSettings = new QPushButton(page);
        btnSettings->setObjectName(QStringLiteral("btnSettings"));
        btnSettings->setFont(font);
        btnSettings->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/new/prefix1/Icones/Setup3_256_128.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnSettings->setIcon(icon3);
        btnSettings->setIconSize(QSize(128, 64));

        verticalLayout->addWidget(btnSettings);

        btnClose = new QPushButton(page);
        btnClose->setObjectName(QStringLiteral("btnClose"));
        btnClose->setFont(font);
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/new/prefix1/Icones/Close_256.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnClose->setIcon(icon4);
        btnClose->setIconSize(QSize(128, 64));

        verticalLayout->addWidget(btnClose);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        verticalLayout_3 = new QVBoxLayout(page_2);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        btn5 = new QToolButton(page_2);
        btn5->setObjectName(QStringLiteral("btn5"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btn5->sizePolicy().hasHeightForWidth());
        btn5->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setPointSize(12);
        btn5->setFont(font1);
        btn5->setIconSize(QSize(32, 32));

        gridLayout_2->addWidget(btn5, 3, 1, 1, 1);

        btn4 = new QToolButton(page_2);
        btn4->setObjectName(QStringLiteral("btn4"));
        sizePolicy.setHeightForWidth(btn4->sizePolicy().hasHeightForWidth());
        btn4->setSizePolicy(sizePolicy);
        btn4->setFont(font1);
        btn4->setIconSize(QSize(32, 32));

        gridLayout_2->addWidget(btn4, 3, 0, 1, 1);

        btn2 = new QToolButton(page_2);
        btn2->setObjectName(QStringLiteral("btn2"));
        sizePolicy.setHeightForWidth(btn2->sizePolicy().hasHeightForWidth());
        btn2->setSizePolicy(sizePolicy);
        btn2->setFont(font1);
        btn2->setIconSize(QSize(32, 32));

        gridLayout_2->addWidget(btn2, 4, 1, 1, 1);

        btn6 = new QToolButton(page_2);
        btn6->setObjectName(QStringLiteral("btn6"));
        sizePolicy.setHeightForWidth(btn6->sizePolicy().hasHeightForWidth());
        btn6->setSizePolicy(sizePolicy);
        btn6->setFont(font1);
        btn6->setIconSize(QSize(32, 32));

        gridLayout_2->addWidget(btn6, 3, 2, 1, 1);

        btnClear = new QToolButton(page_2);
        btnClear->setObjectName(QStringLiteral("btnClear"));
        sizePolicy.setHeightForWidth(btnClear->sizePolicy().hasHeightForWidth());
        btnClear->setSizePolicy(sizePolicy);
        btnClear->setFont(font1);
        btnClear->setIconSize(QSize(32, 32));

        gridLayout_2->addWidget(btnClear, 5, 1, 1, 1);

        btn1 = new QToolButton(page_2);
        btn1->setObjectName(QStringLiteral("btn1"));
        sizePolicy.setHeightForWidth(btn1->sizePolicy().hasHeightForWidth());
        btn1->setSizePolicy(sizePolicy);
        btn1->setFont(font1);
        btn1->setIconSize(QSize(32, 32));

        gridLayout_2->addWidget(btn1, 4, 0, 1, 1);

        btnEnter = new QToolButton(page_2);
        btnEnter->setObjectName(QStringLiteral("btnEnter"));
        sizePolicy.setHeightForWidth(btnEnter->sizePolicy().hasHeightForWidth());
        btnEnter->setSizePolicy(sizePolicy);
        btnEnter->setFont(font1);
        btnEnter->setIconSize(QSize(32, 32));

        gridLayout_2->addWidget(btnEnter, 5, 2, 1, 1);

        btn3 = new QToolButton(page_2);
        btn3->setObjectName(QStringLiteral("btn3"));
        sizePolicy.setHeightForWidth(btn3->sizePolicy().hasHeightForWidth());
        btn3->setSizePolicy(sizePolicy);
        btn3->setFont(font1);
        btn3->setIconSize(QSize(32, 32));

        gridLayout_2->addWidget(btn3, 4, 2, 1, 1);

        btn7 = new QToolButton(page_2);
        btn7->setObjectName(QStringLiteral("btn7"));
        sizePolicy.setHeightForWidth(btn7->sizePolicy().hasHeightForWidth());
        btn7->setSizePolicy(sizePolicy);
        btn7->setFont(font1);
        btn7->setIconSize(QSize(32, 32));

        gridLayout_2->addWidget(btn7, 2, 0, 1, 1);

        btn9 = new QToolButton(page_2);
        btn9->setObjectName(QStringLiteral("btn9"));
        sizePolicy.setHeightForWidth(btn9->sizePolicy().hasHeightForWidth());
        btn9->setSizePolicy(sizePolicy);
        btn9->setFont(font1);
        btn9->setIconSize(QSize(32, 32));

        gridLayout_2->addWidget(btn9, 2, 2, 1, 1);

        btn8 = new QToolButton(page_2);
        btn8->setObjectName(QStringLiteral("btn8"));
        sizePolicy.setHeightForWidth(btn8->sizePolicy().hasHeightForWidth());
        btn8->setSizePolicy(sizePolicy);
        btn8->setFont(font1);
        btn8->setIconSize(QSize(32, 32));

        gridLayout_2->addWidget(btn8, 2, 1, 1, 1);

        btn0 = new QToolButton(page_2);
        btn0->setObjectName(QStringLiteral("btn0"));
        sizePolicy.setHeightForWidth(btn0->sizePolicy().hasHeightForWidth());
        btn0->setSizePolicy(sizePolicy);
        btn0->setFont(font1);
        btn0->setIconSize(QSize(32, 32));

        gridLayout_2->addWidget(btn0, 5, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        btnBack = new QToolButton(page_2);
        btnBack->setObjectName(QStringLiteral("btnBack"));
        btnBack->setIconSize(QSize(32, 56));
        btnBack->setArrowType(Qt::LeftArrow);

        horizontalLayout->addWidget(btnBack);

        linePassword = new QLineEdit(page_2);
        linePassword->setObjectName(QStringLiteral("linePassword"));
        linePassword->setEnabled(false);
        sizePolicy.setHeightForWidth(linePassword->sizePolicy().hasHeightForWidth());
        linePassword->setSizePolicy(sizePolicy);
        QFont font2;
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setWeight(75);
        linePassword->setFont(font2);
        linePassword->setEchoMode(QLineEdit::Password);
        linePassword->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(linePassword);


        gridLayout_2->addLayout(horizontalLayout, 1, 0, 1, 3);

        label_3 = new QLabel(page_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy1);
        label_3->setFont(font1);

        gridLayout_2->addWidget(label_3, 0, 1, 1, 2);


        verticalLayout_2->addLayout(gridLayout_2);


        verticalLayout_3->addLayout(verticalLayout_2);

        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        gridLayout_4 = new QGridLayout(page_3);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        btnBack_2 = new QToolButton(page_3);
        btnBack_2->setObjectName(QStringLiteral("btnBack_2"));
        btnBack_2->setIconSize(QSize(32, 56));
        btnBack_2->setArrowType(Qt::LeftArrow);

        horizontalLayout_2->addWidget(btnBack_2);

        lineOldPassword = new QLineEdit(page_3);
        lineOldPassword->setObjectName(QStringLiteral("lineOldPassword"));
        lineOldPassword->setEnabled(false);
        sizePolicy.setHeightForWidth(lineOldPassword->sizePolicy().hasHeightForWidth());
        lineOldPassword->setSizePolicy(sizePolicy);
        lineOldPassword->setFont(font2);
        lineOldPassword->setEchoMode(QLineEdit::Password);
        lineOldPassword->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(lineOldPassword);


        gridLayout_3->addLayout(horizontalLayout_2, 1, 0, 1, 3);

        btn5_2 = new QToolButton(page_3);
        btn5_2->setObjectName(QStringLiteral("btn5_2"));
        sizePolicy.setHeightForWidth(btn5_2->sizePolicy().hasHeightForWidth());
        btn5_2->setSizePolicy(sizePolicy);
        btn5_2->setFont(font1);
        btn5_2->setIconSize(QSize(32, 32));

        gridLayout_3->addWidget(btn5_2, 3, 1, 1, 1);

        btnClear_2 = new QToolButton(page_3);
        btnClear_2->setObjectName(QStringLiteral("btnClear_2"));
        sizePolicy.setHeightForWidth(btnClear_2->sizePolicy().hasHeightForWidth());
        btnClear_2->setSizePolicy(sizePolicy);
        btnClear_2->setFont(font1);
        btnClear_2->setIconSize(QSize(32, 32));

        gridLayout_3->addWidget(btnClear_2, 5, 1, 1, 1);

        btn6_2 = new QToolButton(page_3);
        btn6_2->setObjectName(QStringLiteral("btn6_2"));
        sizePolicy.setHeightForWidth(btn6_2->sizePolicy().hasHeightForWidth());
        btn6_2->setSizePolicy(sizePolicy);
        btn6_2->setFont(font1);
        btn6_2->setIconSize(QSize(32, 32));

        gridLayout_3->addWidget(btn6_2, 3, 2, 1, 1);

        btn2_2 = new QToolButton(page_3);
        btn2_2->setObjectName(QStringLiteral("btn2_2"));
        sizePolicy.setHeightForWidth(btn2_2->sizePolicy().hasHeightForWidth());
        btn2_2->setSizePolicy(sizePolicy);
        btn2_2->setFont(font1);
        btn2_2->setIconSize(QSize(32, 32));

        gridLayout_3->addWidget(btn2_2, 4, 1, 1, 1);

        btn4_2 = new QToolButton(page_3);
        btn4_2->setObjectName(QStringLiteral("btn4_2"));
        sizePolicy.setHeightForWidth(btn4_2->sizePolicy().hasHeightForWidth());
        btn4_2->setSizePolicy(sizePolicy);
        btn4_2->setFont(font1);
        btn4_2->setIconSize(QSize(32, 32));

        gridLayout_3->addWidget(btn4_2, 3, 0, 1, 1);

        btn3_2 = new QToolButton(page_3);
        btn3_2->setObjectName(QStringLiteral("btn3_2"));
        sizePolicy.setHeightForWidth(btn3_2->sizePolicy().hasHeightForWidth());
        btn3_2->setSizePolicy(sizePolicy);
        btn3_2->setFont(font1);
        btn3_2->setIconSize(QSize(32, 32));

        gridLayout_3->addWidget(btn3_2, 4, 2, 1, 1);

        btn0_2 = new QToolButton(page_3);
        btn0_2->setObjectName(QStringLiteral("btn0_2"));
        sizePolicy.setHeightForWidth(btn0_2->sizePolicy().hasHeightForWidth());
        btn0_2->setSizePolicy(sizePolicy);
        btn0_2->setFont(font1);
        btn0_2->setIconSize(QSize(32, 32));

        gridLayout_3->addWidget(btn0_2, 5, 0, 1, 1);

        btn1_2 = new QToolButton(page_3);
        btn1_2->setObjectName(QStringLiteral("btn1_2"));
        sizePolicy.setHeightForWidth(btn1_2->sizePolicy().hasHeightForWidth());
        btn1_2->setSizePolicy(sizePolicy);
        btn1_2->setFont(font1);
        btn1_2->setIconSize(QSize(32, 32));

        gridLayout_3->addWidget(btn1_2, 4, 0, 1, 1);

        btn7_2 = new QToolButton(page_3);
        btn7_2->setObjectName(QStringLiteral("btn7_2"));
        sizePolicy.setHeightForWidth(btn7_2->sizePolicy().hasHeightForWidth());
        btn7_2->setSizePolicy(sizePolicy);
        btn7_2->setFont(font1);
        btn7_2->setIconSize(QSize(32, 32));

        gridLayout_3->addWidget(btn7_2, 2, 0, 1, 1);

        btnEnter_2 = new QToolButton(page_3);
        btnEnter_2->setObjectName(QStringLiteral("btnEnter_2"));
        sizePolicy.setHeightForWidth(btnEnter_2->sizePolicy().hasHeightForWidth());
        btnEnter_2->setSizePolicy(sizePolicy);
        btnEnter_2->setFont(font1);
        btnEnter_2->setIconSize(QSize(32, 32));

        gridLayout_3->addWidget(btnEnter_2, 5, 2, 1, 1);

        btn9_2 = new QToolButton(page_3);
        btn9_2->setObjectName(QStringLiteral("btn9_2"));
        sizePolicy.setHeightForWidth(btn9_2->sizePolicy().hasHeightForWidth());
        btn9_2->setSizePolicy(sizePolicy);
        btn9_2->setFont(font1);
        btn9_2->setIconSize(QSize(32, 32));

        gridLayout_3->addWidget(btn9_2, 2, 2, 1, 1);

        btn8_2 = new QToolButton(page_3);
        btn8_2->setObjectName(QStringLiteral("btn8_2"));
        sizePolicy.setHeightForWidth(btn8_2->sizePolicy().hasHeightForWidth());
        btn8_2->setSizePolicy(sizePolicy);
        btn8_2->setFont(font1);
        btn8_2->setIconSize(QSize(32, 32));

        gridLayout_3->addWidget(btn8_2, 2, 1, 1, 1);

        label = new QLabel(page_3);
        label->setObjectName(QStringLiteral("label"));
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setFont(font1);

        gridLayout_3->addWidget(label, 0, 1, 1, 2);


        verticalLayout_6->addLayout(gridLayout_3);


        gridLayout_4->addLayout(verticalLayout_6, 0, 0, 1, 1);

        stackedWidget->addWidget(page_3);
        page_6 = new QWidget();
        page_6->setObjectName(QStringLiteral("page_6"));
        gridLayout_6 = new QGridLayout(page_6);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        btnBack_3 = new QToolButton(page_6);
        btnBack_3->setObjectName(QStringLiteral("btnBack_3"));
        btnBack_3->setIconSize(QSize(32, 56));
        btnBack_3->setArrowType(Qt::LeftArrow);

        horizontalLayout_3->addWidget(btnBack_3);

        lineNewPassword = new QLineEdit(page_6);
        lineNewPassword->setObjectName(QStringLiteral("lineNewPassword"));
        lineNewPassword->setEnabled(false);
        sizePolicy.setHeightForWidth(lineNewPassword->sizePolicy().hasHeightForWidth());
        lineNewPassword->setSizePolicy(sizePolicy);
        lineNewPassword->setFont(font2);
        lineNewPassword->setEchoMode(QLineEdit::Password);
        lineNewPassword->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(lineNewPassword);


        gridLayout_5->addLayout(horizontalLayout_3, 1, 0, 1, 3);

        btn5_3 = new QToolButton(page_6);
        btn5_3->setObjectName(QStringLiteral("btn5_3"));
        sizePolicy.setHeightForWidth(btn5_3->sizePolicy().hasHeightForWidth());
        btn5_3->setSizePolicy(sizePolicy);
        btn5_3->setFont(font1);
        btn5_3->setIconSize(QSize(32, 32));

        gridLayout_5->addWidget(btn5_3, 3, 1, 1, 1);

        btnClear_3 = new QToolButton(page_6);
        btnClear_3->setObjectName(QStringLiteral("btnClear_3"));
        sizePolicy.setHeightForWidth(btnClear_3->sizePolicy().hasHeightForWidth());
        btnClear_3->setSizePolicy(sizePolicy);
        btnClear_3->setFont(font1);
        btnClear_3->setIconSize(QSize(32, 32));

        gridLayout_5->addWidget(btnClear_3, 5, 1, 1, 1);

        btn6_3 = new QToolButton(page_6);
        btn6_3->setObjectName(QStringLiteral("btn6_3"));
        sizePolicy.setHeightForWidth(btn6_3->sizePolicy().hasHeightForWidth());
        btn6_3->setSizePolicy(sizePolicy);
        btn6_3->setFont(font1);
        btn6_3->setIconSize(QSize(32, 32));

        gridLayout_5->addWidget(btn6_3, 3, 2, 1, 1);

        btn2_3 = new QToolButton(page_6);
        btn2_3->setObjectName(QStringLiteral("btn2_3"));
        sizePolicy.setHeightForWidth(btn2_3->sizePolicy().hasHeightForWidth());
        btn2_3->setSizePolicy(sizePolicy);
        btn2_3->setFont(font1);
        btn2_3->setIconSize(QSize(32, 32));

        gridLayout_5->addWidget(btn2_3, 4, 1, 1, 1);

        btn4_3 = new QToolButton(page_6);
        btn4_3->setObjectName(QStringLiteral("btn4_3"));
        sizePolicy.setHeightForWidth(btn4_3->sizePolicy().hasHeightForWidth());
        btn4_3->setSizePolicy(sizePolicy);
        btn4_3->setFont(font1);
        btn4_3->setIconSize(QSize(32, 32));

        gridLayout_5->addWidget(btn4_3, 3, 0, 1, 1);

        btn3_3 = new QToolButton(page_6);
        btn3_3->setObjectName(QStringLiteral("btn3_3"));
        sizePolicy.setHeightForWidth(btn3_3->sizePolicy().hasHeightForWidth());
        btn3_3->setSizePolicy(sizePolicy);
        btn3_3->setFont(font1);
        btn3_3->setIconSize(QSize(32, 32));

        gridLayout_5->addWidget(btn3_3, 4, 2, 1, 1);

        btn0_3 = new QToolButton(page_6);
        btn0_3->setObjectName(QStringLiteral("btn0_3"));
        sizePolicy.setHeightForWidth(btn0_3->sizePolicy().hasHeightForWidth());
        btn0_3->setSizePolicy(sizePolicy);
        btn0_3->setFont(font1);
        btn0_3->setIconSize(QSize(32, 32));

        gridLayout_5->addWidget(btn0_3, 5, 0, 1, 1);

        btn1_3 = new QToolButton(page_6);
        btn1_3->setObjectName(QStringLiteral("btn1_3"));
        sizePolicy.setHeightForWidth(btn1_3->sizePolicy().hasHeightForWidth());
        btn1_3->setSizePolicy(sizePolicy);
        btn1_3->setFont(font1);
        btn1_3->setIconSize(QSize(32, 32));

        gridLayout_5->addWidget(btn1_3, 4, 0, 1, 1);

        btn7_3 = new QToolButton(page_6);
        btn7_3->setObjectName(QStringLiteral("btn7_3"));
        sizePolicy.setHeightForWidth(btn7_3->sizePolicy().hasHeightForWidth());
        btn7_3->setSizePolicy(sizePolicy);
        btn7_3->setFont(font1);
        btn7_3->setIconSize(QSize(32, 32));

        gridLayout_5->addWidget(btn7_3, 2, 0, 1, 1);

        btnEnter_3 = new QToolButton(page_6);
        btnEnter_3->setObjectName(QStringLiteral("btnEnter_3"));
        sizePolicy.setHeightForWidth(btnEnter_3->sizePolicy().hasHeightForWidth());
        btnEnter_3->setSizePolicy(sizePolicy);
        btnEnter_3->setFont(font1);
        btnEnter_3->setIconSize(QSize(32, 32));

        gridLayout_5->addWidget(btnEnter_3, 5, 2, 1, 1);

        btn9_3 = new QToolButton(page_6);
        btn9_3->setObjectName(QStringLiteral("btn9_3"));
        sizePolicy.setHeightForWidth(btn9_3->sizePolicy().hasHeightForWidth());
        btn9_3->setSizePolicy(sizePolicy);
        btn9_3->setFont(font1);
        btn9_3->setIconSize(QSize(32, 32));

        gridLayout_5->addWidget(btn9_3, 2, 2, 1, 1);

        btn8_3 = new QToolButton(page_6);
        btn8_3->setObjectName(QStringLiteral("btn8_3"));
        sizePolicy.setHeightForWidth(btn8_3->sizePolicy().hasHeightForWidth());
        btn8_3->setSizePolicy(sizePolicy);
        btn8_3->setFont(font1);
        btn8_3->setIconSize(QSize(32, 32));

        gridLayout_5->addWidget(btn8_3, 2, 1, 1, 1);

        label_2 = new QLabel(page_6);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);
        label_2->setFont(font1);

        gridLayout_5->addWidget(label_2, 0, 1, 1, 2);


        verticalLayout_7->addLayout(gridLayout_5);


        gridLayout_6->addLayout(verticalLayout_7, 0, 0, 1, 1);

        stackedWidget->addWidget(page_6);

        gridLayout->addWidget(stackedWidget, 0, 0, 1, 1);


        retranslateUi(AccessControl);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(AccessControl);
    } // setupUi

    void retranslateUi(QDialog *AccessControl)
    {
        AccessControl->setWindowTitle(QApplication::translate("AccessControl", "Dialog", nullptr));
        btnLock->setText(QApplication::translate("AccessControl", "Lock    Settings   ", nullptr));
        btnUnlock->setText(QApplication::translate("AccessControl", "Unlock  Settings  ", nullptr));
        btnExitToWindows->setText(QApplication::translate("AccessControl", "Exit to Windows  ", nullptr));
        btnSettings->setText(QApplication::translate("AccessControl", "Change Password", nullptr));
        btnClose->setText(QApplication::translate("AccessControl", "Close                     ", nullptr));
        btn5->setText(QApplication::translate("AccessControl", "5", nullptr));
        btn4->setText(QApplication::translate("AccessControl", "4", nullptr));
        btn2->setText(QApplication::translate("AccessControl", "2", nullptr));
        btn6->setText(QApplication::translate("AccessControl", "6", nullptr));
        btnClear->setText(QApplication::translate("AccessControl", "Clear", nullptr));
        btn1->setText(QApplication::translate("AccessControl", "1", nullptr));
        btnEnter->setText(QApplication::translate("AccessControl", "Enter", nullptr));
        btn3->setText(QApplication::translate("AccessControl", "3", nullptr));
        btn7->setText(QApplication::translate("AccessControl", "7", nullptr));
        btn9->setText(QApplication::translate("AccessControl", "9", nullptr));
        btn8->setText(QApplication::translate("AccessControl", "8", nullptr));
        btn0->setText(QApplication::translate("AccessControl", "0", nullptr));
        btnBack->setText(QString());
        label_3->setText(QApplication::translate("AccessControl", "PASSWORD:", nullptr));
        btnBack_2->setText(QString());
        btn5_2->setText(QApplication::translate("AccessControl", "5", nullptr));
        btnClear_2->setText(QApplication::translate("AccessControl", "Clear", nullptr));
        btn6_2->setText(QApplication::translate("AccessControl", "6", nullptr));
        btn2_2->setText(QApplication::translate("AccessControl", "2", nullptr));
        btn4_2->setText(QApplication::translate("AccessControl", "4", nullptr));
        btn3_2->setText(QApplication::translate("AccessControl", "3", nullptr));
        btn0_2->setText(QApplication::translate("AccessControl", "0", nullptr));
        btn1_2->setText(QApplication::translate("AccessControl", "1", nullptr));
        btn7_2->setText(QApplication::translate("AccessControl", "7", nullptr));
        btnEnter_2->setText(QApplication::translate("AccessControl", "Enter", nullptr));
        btn9_2->setText(QApplication::translate("AccessControl", "9", nullptr));
        btn8_2->setText(QApplication::translate("AccessControl", "8", nullptr));
        label->setText(QApplication::translate("AccessControl", "OLD PASSWORD:", nullptr));
        btnBack_3->setText(QString());
        btn5_3->setText(QApplication::translate("AccessControl", "5", nullptr));
        btnClear_3->setText(QApplication::translate("AccessControl", "Clear", nullptr));
        btn6_3->setText(QApplication::translate("AccessControl", "6", nullptr));
        btn2_3->setText(QApplication::translate("AccessControl", "2", nullptr));
        btn4_3->setText(QApplication::translate("AccessControl", "4", nullptr));
        btn3_3->setText(QApplication::translate("AccessControl", "3", nullptr));
        btn0_3->setText(QApplication::translate("AccessControl", "0", nullptr));
        btn1_3->setText(QApplication::translate("AccessControl", "1", nullptr));
        btn7_3->setText(QApplication::translate("AccessControl", "7", nullptr));
        btnEnter_3->setText(QApplication::translate("AccessControl", "Enter", nullptr));
        btn9_3->setText(QApplication::translate("AccessControl", "9", nullptr));
        btn8_3->setText(QApplication::translate("AccessControl", "8", nullptr));
        label_2->setText(QApplication::translate("AccessControl", "NEW PASSWORD:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AccessControl: public Ui_AccessControl {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACCESSCONTROL_H
