#ifndef UDPGAMECONTROLDIALOG_H
#define UDPGAMECONTROLDIALOG_H

#include <QDialog>
#include <QUdpSocket>
#include <QTimer>

#include "GameControl.h"

namespace Ui {
class UDPGameControlDialog;
}

class UDPGameControlDialog : public QDialog
{
    Q_OBJECT
    
private:

    QUdpSocket *udpsocket_simulator;
    QUdpSocket *udpsocket_referee;

    GameControl gameControl;

    QTimer *timer_receiver;
    QTimer *timer_sender;

    bool sending;

public:

    explicit UDPGameControlDialog(QWidget *parent = 0);
    ~UDPGameControlDialog();
    
public slots:
    void actionConnect();
    void actionSend();
    void actionEnablePlanning();
    void actionStopAllAgents();

    void actionReceive();
    void disconnectUDP();
private:
    Ui::UDPGameControlDialog *ui;
};

#endif // UDPGAMECONTROLDIALOG_H
