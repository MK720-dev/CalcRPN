/********************************************************************************
** Form generated from reading UI file 'calculatorapp.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALCULATORAPP_H
#define UI_CALCULATORAPP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CalculatorApp
{
public:
    QWidget *centralwidget;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QPushButton *pushButton_11;
    QPushButton *pushButton_12;
    QPushButton *pushButton_13;
    QPushButton *pushButton_14;
    QPushButton *pushButton_15;
    QPushButton *pushButton_16;
    QPushButton *pushButton_17;
    QPushButton *pushButton_18;
    QPushButton *pushButton_19;
    QPushButton *pushButton_20;
    QPushButton *pushButton_21;
    QPushButton *pushButton_22;
    QPushButton *pushButton_23;
    QPushButton *pushButton_24;
    QPushButton *btnDelete;
    QPushButton *pushButton_26;
    QPushButton *pushButton_27;
    QPushButton *pushButton_28;
    QPushButton *pushButton_29;
    QLabel *outputTextBox;
    QPushButton *showQueueButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *CalculatorApp)
    {
        if (CalculatorApp->objectName().isEmpty())
            CalculatorApp->setObjectName("CalculatorApp");
        CalculatorApp->resize(800, 600);
        centralwidget = new QWidget(CalculatorApp);
        centralwidget->setObjectName("centralwidget");
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(20, 40, 241, 41));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(100, 170, 41, 31));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        pushButton->setPalette(palette);
        pushButton->setIconSize(QSize(40, 40));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(220, 170, 41, 31));
        pushButton_2->setIconSize(QSize(40, 40));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(220, 110, 41, 31));
        pushButton_3->setIconSize(QSize(40, 40));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(220, 140, 41, 31));
        pushButton_4->setIconSize(QSize(40, 40));
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(20, 80, 41, 31));
        pushButton_5->setIconSize(QSize(40, 40));
        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(60, 80, 41, 31));
        pushButton_6->setIconSize(QSize(40, 40));
        pushButton_7 = new QPushButton(centralwidget);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(140, 80, 41, 31));
        pushButton_7->setIconSize(QSize(40, 40));
        pushButton_8 = new QPushButton(centralwidget);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setGeometry(QRect(180, 80, 41, 31));
        pushButton_8->setIconSize(QSize(40, 40));
        pushButton_9 = new QPushButton(centralwidget);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setGeometry(QRect(220, 80, 41, 31));
        pushButton_9->setIconSize(QSize(40, 40));
        pushButton_10 = new QPushButton(centralwidget);
        pushButton_10->setObjectName("pushButton_10");
        pushButton_10->setGeometry(QRect(20, 110, 41, 31));
        pushButton_10->setIconSize(QSize(40, 40));
        pushButton_11 = new QPushButton(centralwidget);
        pushButton_11->setObjectName("pushButton_11");
        pushButton_11->setGeometry(QRect(20, 140, 41, 31));
        pushButton_11->setIconSize(QSize(40, 40));
        pushButton_12 = new QPushButton(centralwidget);
        pushButton_12->setObjectName("pushButton_12");
        pushButton_12->setGeometry(QRect(20, 170, 41, 31));
        pushButton_12->setIconSize(QSize(40, 40));
        pushButton_13 = new QPushButton(centralwidget);
        pushButton_13->setObjectName("pushButton_13");
        pushButton_13->setGeometry(QRect(60, 170, 41, 31));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        pushButton_13->setPalette(palette1);
        pushButton_13->setIconSize(QSize(40, 40));
        pushButton_14 = new QPushButton(centralwidget);
        pushButton_14->setObjectName("pushButton_14");
        pushButton_14->setGeometry(QRect(180, 140, 41, 31));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        pushButton_14->setPalette(palette2);
        pushButton_14->setIconSize(QSize(40, 40));
        pushButton_15 = new QPushButton(centralwidget);
        pushButton_15->setObjectName("pushButton_15");
        pushButton_15->setGeometry(QRect(140, 140, 41, 31));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        pushButton_15->setPalette(palette3);
        pushButton_15->setIconSize(QSize(40, 40));
        pushButton_16 = new QPushButton(centralwidget);
        pushButton_16->setObjectName("pushButton_16");
        pushButton_16->setGeometry(QRect(100, 140, 41, 31));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        pushButton_16->setPalette(palette4);
        pushButton_16->setIconSize(QSize(40, 40));
        pushButton_17 = new QPushButton(centralwidget);
        pushButton_17->setObjectName("pushButton_17");
        pushButton_17->setGeometry(QRect(60, 140, 41, 31));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        pushButton_17->setPalette(palette5);
        pushButton_17->setIconSize(QSize(40, 40));
        pushButton_18 = new QPushButton(centralwidget);
        pushButton_18->setObjectName("pushButton_18");
        pushButton_18->setGeometry(QRect(180, 110, 41, 31));
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        pushButton_18->setPalette(palette6);
        pushButton_18->setIconSize(QSize(40, 40));
        pushButton_19 = new QPushButton(centralwidget);
        pushButton_19->setObjectName("pushButton_19");
        pushButton_19->setGeometry(QRect(100, 110, 41, 31));
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        pushButton_19->setPalette(palette7);
        pushButton_19->setIconSize(QSize(40, 40));
        pushButton_20 = new QPushButton(centralwidget);
        pushButton_20->setObjectName("pushButton_20");
        pushButton_20->setGeometry(QRect(140, 110, 41, 31));
        QPalette palette8;
        palette8.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        pushButton_20->setPalette(palette8);
        pushButton_20->setIconSize(QSize(40, 40));
        pushButton_21 = new QPushButton(centralwidget);
        pushButton_21->setObjectName("pushButton_21");
        pushButton_21->setGeometry(QRect(60, 110, 41, 31));
        QPalette palette9;
        palette9.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette9.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        pushButton_21->setPalette(palette9);
        pushButton_21->setIconSize(QSize(40, 40));
        pushButton_22 = new QPushButton(centralwidget);
        pushButton_22->setObjectName("pushButton_22");
        pushButton_22->setGeometry(QRect(180, 170, 41, 31));
        pushButton_22->setIconSize(QSize(40, 40));
        pushButton_23 = new QPushButton(centralwidget);
        pushButton_23->setObjectName("pushButton_23");
        pushButton_23->setGeometry(QRect(140, 170, 41, 31));
        pushButton_23->setIconSize(QSize(40, 40));
        pushButton_24 = new QPushButton(centralwidget);
        pushButton_24->setObjectName("pushButton_24");
        pushButton_24->setGeometry(QRect(100, 80, 41, 31));
        pushButton_24->setIconSize(QSize(40, 40));
        btnDelete = new QPushButton(centralwidget);
        btnDelete->setObjectName("btnDelete");
        btnDelete->setGeometry(QRect(260, 80, 41, 31));
        btnDelete->setIconSize(QSize(40, 40));
        pushButton_26 = new QPushButton(centralwidget);
        pushButton_26->setObjectName("pushButton_26");
        pushButton_26->setGeometry(QRect(260, 40, 41, 41));
        pushButton_26->setIconSize(QSize(40, 40));
        pushButton_27 = new QPushButton(centralwidget);
        pushButton_27->setObjectName("pushButton_27");
        pushButton_27->setGeometry(QRect(260, 140, 41, 31));
        pushButton_27->setIconSize(QSize(40, 40));
        pushButton_28 = new QPushButton(centralwidget);
        pushButton_28->setObjectName("pushButton_28");
        pushButton_28->setGeometry(QRect(260, 110, 41, 31));
        pushButton_28->setIconSize(QSize(40, 40));
        pushButton_29 = new QPushButton(centralwidget);
        pushButton_29->setObjectName("pushButton_29");
        pushButton_29->setGeometry(QRect(260, 170, 41, 31));
        pushButton_29->setIconSize(QSize(40, 40));
        outputTextBox = new QLabel(centralwidget);
        outputTextBox->setObjectName("outputTextBox");
        outputTextBox->setGeometry(QRect(20, 10, 321, 31));
        showQueueButton = new QPushButton(centralwidget);
        showQueueButton->setObjectName("showQueueButton");
        showQueueButton->setGeometry(QRect(300, 40, 41, 41));
        showQueueButton->setIconSize(QSize(40, 40));
        CalculatorApp->setCentralWidget(centralwidget);
        menubar = new QMenuBar(CalculatorApp);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 26));
        CalculatorApp->setMenuBar(menubar);
        statusbar = new QStatusBar(CalculatorApp);
        statusbar->setObjectName("statusbar");
        CalculatorApp->setStatusBar(statusbar);

        retranslateUi(CalculatorApp);

        QMetaObject::connectSlotsByName(CalculatorApp);
    } // setupUi

    void retranslateUi(QMainWindow *CalculatorApp)
    {
        CalculatorApp->setWindowTitle(QCoreApplication::translate("CalculatorApp", "CalculatorApp", nullptr));
        lineEdit->setText(QString());
        pushButton->setText(QCoreApplication::translate("CalculatorApp", "9", nullptr));
        pushButton_2->setText(QCoreApplication::translate("CalculatorApp", "-", nullptr));
        pushButton_3->setText(QCoreApplication::translate("CalculatorApp", "*", nullptr));
        pushButton_4->setText(QCoreApplication::translate("CalculatorApp", "/", nullptr));
        pushButton_5->setText(QCoreApplication::translate("CalculatorApp", "cos", nullptr));
        pushButton_6->setText(QCoreApplication::translate("CalculatorApp", "sin", nullptr));
        pushButton_7->setText(QCoreApplication::translate("CalculatorApp", "exp", nullptr));
        pushButton_8->setText(QCoreApplication::translate("CalculatorApp", "log", nullptr));
        pushButton_9->setText(QCoreApplication::translate("CalculatorApp", "^", nullptr));
        pushButton_10->setText(QCoreApplication::translate("CalculatorApp", "tan", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_11->setToolTip(QCoreApplication::translate("CalculatorApp", "<html><head/><body><p><span style=\" font-weight:700;\">f(x,y,...,z) = x+y+...+z</span></p><p>Summation function that could take up to any number of variables. </p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_11->setText(QCoreApplication::translate("CalculatorApp", "f", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_12->setToolTip(QCoreApplication::translate("CalculatorApp", "<html><head/><body><p><span style=\" font-weight:700;\">g(x,y,...,z) = x*y*...*z</span></p><p>A product function that could take up any number of variables.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_12->setText(QCoreApplication::translate("CalculatorApp", "g", nullptr));
        pushButton_13->setText(QCoreApplication::translate("CalculatorApp", "8", nullptr));
        pushButton_14->setText(QCoreApplication::translate("CalculatorApp", "7", nullptr));
        pushButton_15->setText(QCoreApplication::translate("CalculatorApp", "6", nullptr));
        pushButton_16->setText(QCoreApplication::translate("CalculatorApp", "5", nullptr));
        pushButton_17->setText(QCoreApplication::translate("CalculatorApp", "4", nullptr));
        pushButton_18->setText(QCoreApplication::translate("CalculatorApp", "3", nullptr));
        pushButton_19->setText(QCoreApplication::translate("CalculatorApp", "1", nullptr));
        pushButton_20->setText(QCoreApplication::translate("CalculatorApp", "2", nullptr));
        pushButton_21->setText(QCoreApplication::translate("CalculatorApp", "0", nullptr));
        pushButton_22->setText(QCoreApplication::translate("CalculatorApp", "+", nullptr));
        pushButton_23->setText(QCoreApplication::translate("CalculatorApp", "=", nullptr));
        pushButton_24->setText(QCoreApplication::translate("CalculatorApp", "sqrt", nullptr));
        btnDelete->setText(QCoreApplication::translate("CalculatorApp", "del", nullptr));
        pushButton_26->setText(QCoreApplication::translate("CalculatorApp", "C", nullptr));
        pushButton_27->setText(QCoreApplication::translate("CalculatorApp", ")", nullptr));
        pushButton_28->setText(QCoreApplication::translate("CalculatorApp", "(", nullptr));
        pushButton_29->setText(QCoreApplication::translate("CalculatorApp", ",", nullptr));
        outputTextBox->setText(QString());
#if QT_CONFIG(tooltip)
        showQueueButton->setToolTip(QCoreApplication::translate("CalculatorApp", "<html><head/><body><p><span style=\" font-weight:700;\">Use this button if you would like to view the postfix notation for your mathematical expression after it has been evaluated. </span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        showQueueButton->setText(QCoreApplication::translate("CalculatorApp", "RPN", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CalculatorApp: public Ui_CalculatorApp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALCULATORAPP_H
