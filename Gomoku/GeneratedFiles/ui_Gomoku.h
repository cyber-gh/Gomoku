/********************************************************************************
** Form generated from reading UI file 'Gomoku.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GOMOKU_H
#define UI_GOMOKU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GomokuClass
{
public:
    QWidget *widget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButton_2;
    QPushButton *pushButton;

    void setupUi(QWidget *GomokuClass)
    {
        if (GomokuClass->objectName().isEmpty())
            GomokuClass->setObjectName(QString::fromUtf8("GomokuClass"));
        GomokuClass->resize(1049, 764);
        widget = new QWidget(GomokuClass);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 0, 891, 631));
        verticalLayoutWidget = new QWidget(GomokuClass);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(890, 0, 160, 401));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton_2 = new QPushButton(verticalLayoutWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        verticalLayout_2->addWidget(pushButton_2);

        pushButton = new QPushButton(verticalLayoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout_2->addWidget(pushButton);


        retranslateUi(GomokuClass);

        QMetaObject::connectSlotsByName(GomokuClass);
    } // setupUi

    void retranslateUi(QWidget *GomokuClass)
    {
        GomokuClass->setWindowTitle(QApplication::translate("GomokuClass", "Gomoku", nullptr));
        pushButton_2->setText(QApplication::translate("GomokuClass", "Play game", nullptr));
        pushButton->setText(QApplication::translate("GomokuClass", "Reset", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GomokuClass: public Ui_GomokuClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GOMOKU_H
