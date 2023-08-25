#ifndef MAINDIALOG_H
#define MAINDIALOG_H

#include <QDialog>
#include <QTimer>
#include "GameControl.h"

namespace Ui {
class MainDialog;
}

class MainDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit MainDialog(QWidget *parent = 0);
    ~MainDialog();

public slots:
    void actionConnect();
    void actionSend();
    void actionSendCycle();
    void disconnectUDP();

private:
    bool sending, reseting;
    Ui::MainDialog *ui;

    GameControl gameControl;
    QUdpSocket udpsocket;
    QTimer* timer;

};

#endif // MAINDIALOG_H
