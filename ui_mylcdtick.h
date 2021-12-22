/********************************************************************************
** Form generated from reading UI file 'mylcdtick.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYLCDTICK_H
#define UI_MYLCDTICK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_myLCDtick
{
public:
    QGridLayout *gridLayout;
    QFrame *frame;
    QGridLayout *gridLayout_2;
    QLCDNumber *lcdNumber;
    QToolButton *plusButton;
    QToolButton *minusButton;

    void setupUi(QWidget *myLCDtick)
    {
        if (myLCDtick->objectName().isEmpty())
            myLCDtick->setObjectName(QStringLiteral("myLCDtick"));
        myLCDtick->resize(254, 50);
        myLCDtick->setWindowTitle(QStringLiteral("Form"));
        gridLayout = new QGridLayout(myLCDtick);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        frame = new QFrame(myLCDtick);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        lcdNumber = new QLCDNumber(frame);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lcdNumber->sizePolicy().hasHeightForWidth());
        lcdNumber->setSizePolicy(sizePolicy);
        lcdNumber->setStyleSheet(QLatin1String("background-color: rgb(0, 0, 0);\n"
"color: rgb(255, 255, 255);"));
        lcdNumber->setFrameShape(QFrame::Box);
        lcdNumber->setDigitCount(7);

        gridLayout_2->addWidget(lcdNumber, 0, 1, 1, 1);

        plusButton = new QToolButton(frame);
        plusButton->setObjectName(QStringLiteral("plusButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(plusButton->sizePolicy().hasHeightForWidth());
        plusButton->setSizePolicy(sizePolicy1);
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        plusButton->setFont(font);
        plusButton->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 0);"));
        plusButton->setText(QStringLiteral(""));
        plusButton->setIconSize(QSize(40, 30));
        plusButton->setToolButtonStyle(Qt::ToolButtonIconOnly);
        plusButton->setAutoRaise(true);
        plusButton->setArrowType(Qt::RightArrow);

        gridLayout_2->addWidget(plusButton, 0, 2, 1, 1);

        minusButton = new QToolButton(frame);
        minusButton->setObjectName(QStringLiteral("minusButton"));
        sizePolicy1.setHeightForWidth(minusButton->sizePolicy().hasHeightForWidth());
        minusButton->setSizePolicy(sizePolicy1);
        minusButton->setFont(font);
        minusButton->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 0);"));
        minusButton->setText(QStringLiteral(""));
        minusButton->setIconSize(QSize(40, 30));
        minusButton->setToolButtonStyle(Qt::ToolButtonIconOnly);
        minusButton->setAutoRaise(true);
        minusButton->setArrowType(Qt::LeftArrow);

        gridLayout_2->addWidget(minusButton, 0, 0, 1, 1);


        gridLayout->addWidget(frame, 0, 0, 1, 1);


        retranslateUi(myLCDtick);

        QMetaObject::connectSlotsByName(myLCDtick);
    } // setupUi

    void retranslateUi(QWidget *myLCDtick)
    {
        Q_UNUSED(myLCDtick);
    } // retranslateUi

};

namespace Ui {
    class myLCDtick: public Ui_myLCDtick {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYLCDTICK_H
