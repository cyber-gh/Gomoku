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
    QPushButton *btnSkipTurn;
    QPushButton *btnSwapMode;
    QPushButton *btnSwap2Mode;
    QPushButton *btnResetGame;
    QPushButton *drawButton;

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
        btnSkipTurn = new QPushButton(verticalLayoutWidget);
        btnSkipTurn->setObjectName(QString::fromUtf8("btnSkipTurn"));

        verticalLayout_2->addWidget(btnSkipTurn);

        btnSwapMode = new QPushButton(verticalLayoutWidget);
        btnSwapMode->setObjectName(QString::fromUtf8("btnSwapMode"));

        verticalLayout_2->addWidget(btnSwapMode);

        btnSwap2Mode = new QPushButton(verticalLayoutWidget);
        btnSwap2Mode->setObjectName(QString::fromUtf8("btnSwap2Mode"));

        verticalLayout_2->addWidget(btnSwap2Mode);

        btnResetGame = new QPushButton(verticalLayoutWidget);
        btnResetGame->setObjectName(QString::fromUtf8("btnResetGame"));

        verticalLayout_2->addWidget(btnResetGame);

        drawButton = new QPushButton(verticalLayoutWidget);
        drawButton->setObjectName(QString::fromUtf8("drawButton"));

        verticalLayout_2->addWidget(drawButton);


        retranslateUi(GomokuClass);

        QMetaObject::connectSlotsByName(GomokuClass);
    } // setupUi

    void retranslateUi(QWidget *GomokuClass)
    {
        GomokuClass->setWindowTitle(QApplication::translate("GomokuClass", "Gomoku", nullptr));
        btnSkipTurn->setText(QApplication::translate("GomokuClass", "Skip turn", nullptr));
        btnSwapMode->setText(QApplication::translate("GomokuClass", "Swap Mode", nullptr));
        btnSwap2Mode->setText(QApplication::translate("GomokuClass", "Swap2 mode", nullptr));
        btnResetGame->setText(QApplication::translate("GomokuClass", "Reset", nullptr));
        drawButton->setText(QApplication::translate("GomokuClass", "Set draw", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GomokuClass: public Ui_GomokuClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GOMOKU_H
