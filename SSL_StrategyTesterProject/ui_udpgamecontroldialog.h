/********************************************************************************
** Form generated from reading UI file 'udpgamecontroldialog.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UDPGAMECONTROLDIALOG_H
#define UI_UDPGAMECONTROLDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_UDPGameControlDialog
{
public:
    QLabel *label_4;
    QLabel *label_3;
    QLabel *label;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QPushButton *pushButton_2;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *lineEdit_3;
    QPushButton *pushButton_3;
    QLabel *label_7;
    QPushButton *pushButton_4;
    QFrame *line;

    void setupUi(QDialog *UDPGameControlDialog)
    {
        if (UDPGameControlDialog->objectName().isEmpty())
            UDPGameControlDialog->setObjectName(QString::fromUtf8("UDPGameControlDialog"));
        UDPGameControlDialog->resize(400, 301);
        label_4 = new QLabel(UDPGameControlDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 80, 51, 31));
        label_3 = new QLabel(UDPGameControlDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 50, 51, 31));
        label = new QLabel(UDPGameControlDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 20, 91, 21));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        lineEdit_4 = new QLineEdit(UDPGameControlDialog);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(270, 80, 113, 31));
        lineEdit_2 = new QLineEdit(UDPGameControlDialog);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(70, 80, 113, 31));
        pushButton = new QPushButton(UDPGameControlDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(20, 130, 161, 31));
        label_2 = new QLabel(UDPGameControlDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(220, 20, 91, 21));
        label_2->setFont(font);
        lineEdit = new QLineEdit(UDPGameControlDialog);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(70, 50, 113, 31));
        pushButton_2 = new QPushButton(UDPGameControlDialog);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(20, 210, 161, 31));
        label_5 = new QLabel(UDPGameControlDialog);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(220, 80, 51, 31));
        label_6 = new QLabel(UDPGameControlDialog);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(220, 50, 51, 31));
        lineEdit_3 = new QLineEdit(UDPGameControlDialog);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(270, 50, 113, 31));
        pushButton_3 = new QPushButton(UDPGameControlDialog);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(200, 210, 161, 31));
        label_7 = new QLabel(UDPGameControlDialog);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(20, 180, 111, 21));
        label_7->setFont(font);
        pushButton_4 = new QPushButton(UDPGameControlDialog);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(200, 250, 161, 31));
        line = new QFrame(UDPGameControlDialog);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(0, 170, 401, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        retranslateUi(UDPGameControlDialog);
        QObject::connect(pushButton, SIGNAL(clicked()), UDPGameControlDialog, SLOT(actionConnect()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), UDPGameControlDialog, SLOT(actionSend()));
        QObject::connect(pushButton_3, SIGNAL(clicked()), UDPGameControlDialog, SLOT(actionEnablePlanning()));
        QObject::connect(pushButton_4, SIGNAL(clicked()), UDPGameControlDialog, SLOT(actionStopAllAgents()));

        QMetaObject::connectSlotsByName(UDPGameControlDialog);
    } // setupUi

    void retranslateUi(QDialog *UDPGameControlDialog)
    {
        UDPGameControlDialog->setWindowTitle(QApplication::translate("UDPGameControlDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("UDPGameControlDialog", "Port", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("UDPGameControlDialog", "IP", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("UDPGameControlDialog", "Simulator", 0, QApplication::UnicodeUTF8));
        lineEdit_2->setText(QApplication::translate("UDPGameControlDialog", "20011", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("UDPGameControlDialog", "Connect", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("UDPGameControlDialog", "Referee", 0, QApplication::UnicodeUTF8));
        lineEdit->setText(QApplication::translate("UDPGameControlDialog", "127.0.0.1", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("UDPGameControlDialog", "Send", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("UDPGameControlDialog", "Port", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("UDPGameControlDialog", "IP", 0, QApplication::UnicodeUTF8));
        lineEdit_3->setText(QString());
        pushButton_3->setText(QApplication::translate("UDPGameControlDialog", "Enable Planning", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("UDPGameControlDialog", "Game Control", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("UDPGameControlDialog", "Stop All Agents", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class UDPGameControlDialog: public Ui_UDPGameControlDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UDPGAMECONTROLDIALOG_H
