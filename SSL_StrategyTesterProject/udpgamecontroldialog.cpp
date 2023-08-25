#include "udpgamecontroldialog.h"
#include "ui_udpgamecontroldialog.h"

#define SET_TIMER_SENDER 1

UDPGameControlDialog::UDPGameControlDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UDPGameControlDialog)
{
    ui->setupUi(this);

    // SIMULATOR
    udpsocket_simulator = new QUdpSocket(this);
    //REFEREE
    udpsocket_referee = new QUdpSocket(this);
    /////////////////
    int timeInterval = 1;
    sending = false;


    //timer_receiver=new QTimer(this);
    //timer_receiver->setInterval(timeInterval);
    //connect(timer_receiver,SIGNAL(timeout()),this,SLOT(actionReceive()));

    if(SET_TIMER_SENDER){
        timer_sender= new QTimer(this);
        timer_sender->setInterval(timeInterval);
        connect(timer_sender,SIGNAL(timeout()),this,SLOT(actionSend()));
    }
}

void UDPGameControlDialog::actionConnect()
{
    QHostAddress* addr_simulator = new QHostAddress(ui->lineEdit->text());
    quint16 port_simulator = ui->lineEdit_2->text().toUShort();

    // PREDEFINED ADDRESS - SSL-VISION -- RECEIVER
    QHostAddress hostaddress("224.5.23.2");
    udpsocket_simulator->bind(10020, QUdpSocket::ShareAddress); //RECEIVER
    udpsocket_simulator->joinMulticastGroup(hostaddress);

    gameControl.initializeSimulatorControl(udpsocket_simulator, addr_simulator, port_simulator);
    ui->pushButton->setDisabled(true);

    connect(udpsocket_simulator, SIGNAL(readyRead()), this, SLOT(actionReceive()));
}

void UDPGameControlDialog::actionSend(){
    gameControl.plan_robotsPositioning();
}

void UDPGameControlDialog::actionEnablePlanning(){
    gameControl.enablePlanning();
}

void UDPGameControlDialog::actionStopAllAgents(){
    gameControl.stopAll();
}

void UDPGameControlDialog::actionReceive()
{
    QByteArray buffer;
    buffer.resize(udpsocket_simulator->pendingDatagramSize());
    QHostAddress sender;
    quint16 senderPort;
    udpsocket_simulator->readDatagram(buffer.data(), buffer.size(),
                &sender, &senderPort);
    /*
    qDebug() << "Message from: " << sender.toString();
    qDebug() << "Message port: " << senderPort;
    qDebug() << "Message: " << buffer;
    */

    gameControl.sense_fieldData(buffer, 0);
    if(SET_TIMER_SENDER){
        if(!sending){
            timer_sender->start();
            sending = true;
        }
    }
}

void UDPGameControlDialog::disconnectUDP(){
    disconnect(udpsocket_simulator, SIGNAL(readyRead()), this, SLOT(readyRead()));
    udpsocket_simulator->close();
    udpsocket_referee->close();
}

UDPGameControlDialog::~UDPGameControlDialog()
{
    delete ui;
}
