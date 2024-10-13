/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *refreshBut;
    QComboBox *comboBox_baudRate;
    QLabel *label;
    QComboBox *comboBox_Ports;
    QPushButton *setPortsBut;
    QLabel *label_2;
    QPlainTextEdit *plainTextEdit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        refreshBut = new QPushButton(centralwidget);
        refreshBut->setObjectName("refreshBut");
        refreshBut->setGeometry(QRect(50, 190, 80, 24));
        comboBox_baudRate = new QComboBox(centralwidget);
        comboBox_baudRate->addItem(QString());
        comboBox_baudRate->setObjectName("comboBox_baudRate");
        comboBox_baudRate->setGeometry(QRect(50, 130, 72, 21));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(140, 130, 49, 16));
        comboBox_Ports = new QComboBox(centralwidget);
        comboBox_Ports->setObjectName("comboBox_Ports");
        comboBox_Ports->setGeometry(QRect(50, 160, 72, 21));
        setPortsBut = new QPushButton(centralwidget);
        setPortsBut->setObjectName("setPortsBut");
        setPortsBut->setGeometry(QRect(50, 220, 80, 24));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(140, 160, 71, 20));
        plainTextEdit = new QPlainTextEdit(centralwidget);
        plainTextEdit->setObjectName("plainTextEdit");
        plainTextEdit->setGeometry(QRect(240, 20, 291, 521));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        refreshBut->setText(QCoreApplication::translate("MainWindow", "Refresh", nullptr));
        comboBox_baudRate->setItemText(0, QCoreApplication::translate("MainWindow", "115200", nullptr));

        label->setText(QCoreApplication::translate("MainWindow", "Baudrate", nullptr));
        setPortsBut->setText(QCoreApplication::translate("MainWindow", "Set Port", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Avaible Ports", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
