#include "MotionStorage.h"

MotionStorage::MotionStorage(){
}

void GameControl::sendRobotPosition(int robotID, bool isYellow, double x, double y, double orientation, double vel, double kickVel){
    vectorActions.saveTarget(robotID, isYellow, x, y, orientation);
    vectorActions.saveTarget(robotID, isYellow, x, y, orientation);

    SSL_DetectionRobot robot =  packetFrame.robots_blue(robotID);

    grSim_Packet packet;
    setRobotParameters(packet, robotID, isYellow,false,velT,velN,0,kickVel,0,false);
    sendPacket(packet);
}

void GameControl::sendRobotStop(int robotID, bool isYellow){
    printf("sendRobotStop\n");
    grSim_Packet packet;
    setRobotParameters(packet, robotID, isYellow, false, 0,0,0,0,0,false);
    sendPacket(packet);
}
