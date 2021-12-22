/********************************************************************************
** Form generated from reading UI file 'topmessage.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOPMESSAGE_H
#define UI_TOPMESSAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TopMessage
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label;

    void setupUi(QWidget *TopMessage)
    {
        if (TopMessage->objectName().isEmpty())
            TopMessage->setObjectName(QStringLiteral("TopMessage"));
        TopMessage->resize(600, 400);
        gridLayout = new QGridLayout(TopMessage);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalSpacer = new QSpacerItem(233, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        pushButton = new QPushButton(TopMessage);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        QFont font;
        font.setPointSize(18);
        font.setBold(true);
        font.setWeight(75);
        pushButton->setFont(font);
        pushButton->setStyleSheet(QLatin1String("background-color: rgb(217, 217, 217);\n"
"color: rgb(0, 0, 0);"));

        gridLayout->addWidget(pushButton, 1, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(232, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        label = new QLabel(TopMessage);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setFont(font);
        label->setStyleSheet(QLatin1String("color: rgb(255, 0, 0);\n"
"background-color: rgb(255, 255, 255);"));
        label->setAlignment(Qt::AlignCenter);
        label->setWordWrap(true);

        gridLayout->addWidget(label, 0, 0, 1, 3);


        retranslateUi(TopMessage);

        QMetaObject::connectSlotsByName(TopMessage);
    } // setupUi

    void retranslateUi(QWidget *TopMessage)
    {
        TopMessage->setWindowTitle(QApplication::translate("TopMessage", "Form", nullptr));
        pushButton->setText(QApplication::translate("TopMessage", "OK", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class TopMessage: public Ui_TopMessage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOPMESSAGE_H
