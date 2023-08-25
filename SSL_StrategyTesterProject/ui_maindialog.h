/********************************************************************************
** Form generated from reading UI file 'maindialog.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINDIALOG_H
#define UI_MAINDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_MainDialog
{
public:
    QLabel *label;
    QLabel *label_3;
    QPushButton *pushButton;
    QLineEdit *lineEdit_3;
    QLabel *label_2;
    QPushButton *pushButton_2;
    QLabel *label_6;
    QLineEdit *lineEdit_4;
    QLabel *label_4;
    QLineEdit *lineEdit_2;
    QLabel *label_5;
    QLineEdit *lineEdit;

    void setupUi(QDialog *MainDialog)
    {
        if (MainDialog->objectName().isEmpty())
            MainDialog->setObjectName(QString::fromUtf8("MainDialog"));
        MainDialog->resize(383, 167);
        label = new QLabel(MainDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 91, 21));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label_3 = new QLabel(MainDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 40, 51, 31));
        pushButton = new QPushButton(MainDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(10, 120, 191, 27));
        lineEdit_3 = new QLineEdit(MainDialog);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(60, 70, 113, 31));
        label_2 = new QLabel(MainDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(210, 10, 91, 21));
        label_2->setFont(font);
        pushButton_2 = new QPushButton(MainDialog);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(210, 120, 161, 27));
        label_6 = new QLabel(MainDialog);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(210, 40, 51, 31));
        lineEdit_4 = new QLineEdit(MainDialog);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(260, 70, 113, 31));
        label_4 = new QLabel(MainDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 70, 51, 31));
        lineEdit_2 = new QLineEdit(MainDialog);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(260, 40, 113, 31));
        label_5 = new QLabel(MainDialog);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(210, 70, 51, 31));
        lineEdit = new QLineEdit(MainDialog);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(60, 40, 113, 31));

        retranslateUi(MainDialog);
        QObject::connect(pushButton, SIGNAL(clicked()), MainDialog, SLOT(actionConnect()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), MainDialog, SLOT(actionSend()));

        QMetaObject::connectSlotsByName(MainDialog);
    } // setupUi

    void retranslateUi(QDialog *MainDialog)
    {
        MainDialog->setWindowTitle(QApplication::translate("MainDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainDialog", "Simulator", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainDialog", "IP", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MainDialog", "Connect", 0, QApplication::UnicodeUTF8));
        lineEdit_3->setText(QApplication::translate("MainDialog", "20011", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainDialog", "Referee", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("MainDialog", "Send", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainDialog", "IP", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainDialog", "Port", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainDialog", "Port", 0, QApplication::UnicodeUTF8));
        lineEdit->setText(QApplication::translate("MainDialog", "127.0.0.1", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainDialog: public Ui_MainDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINDIALOG_H
