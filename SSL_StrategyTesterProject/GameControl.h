#ifndef GAMECONTROL_H
#define GAMECONTROL_H

#include "3rdparty/sslvision/messages_robocup_ssl_wrapper.pb.h"
#include "3rdparty/sslvision/messages_robocup_ssl_detection.pb.h"
#include "3rdparty/sslvision/messages_robocup_ssl_geometry.pb.h"

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

#include "simulator/SimulatorMotionPlanner.h"
#include "serial/SerialMotionPlanner.h"

#define ENABLE_SIMULATOR 1

using namespace std;

class GameControl
{
private:

    #if ENABLE_SIMULATOR == 1
        SimulatorMotionPlanner* motionPlanner;
    #else
        SerialMotionPlanner* motionPlanner;
    #endif

    int mode;
    SSL_WrapperPacket* packet;
    SSL_GeometryFieldSize* packetField;
    SSL_GeometryData* packetGeo;
    SSL_DetectionFrame* packetFrame;

    RobotsPositioning *actualPositioning;
    FieldData *fieldData;

    // TEMPORAL
    int flagControl[6];
    int globalControl;

public:

    GameControl();
    void initializeSimulatorControl(QUdpSocket* socket, QHostAddress* addr_simulator, quint16 port_simulator);

    // Hierarchical/Deliberative Paradigm
    void sense_fieldData(QByteArray&buffer, int teamNumber); // SENSE
    void plan_robotsPositioning(); // PLAN & ACT
    void enablePlanning();
    void stopAll();
};

#endif // GAMECONTROL_H
