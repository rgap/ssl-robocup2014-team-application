#include "GameControl.h"

using namespace std;

GameControl::GameControl(){
    memset(flagControl, 1, sizeof(flagControl));
    globalControl = 1;
}

void GameControl::initializeSimulatorControl(QUdpSocket* socket, QHostAddress* addr_simulator, quint16 port_simulator){

    #if ENABLE_SIMULATOR == 1
        motionPlanner = new SimulatorMotionPlanner();
        motionPlanner->initializePacketSender(socket, addr_simulator, port_simulator);
    #else
        motionPlanner = new SerialMotionPlanner();
        motionPlanner->initializePacketSender();
    #endif

    packet = NULL;

    packetFrame = new SSL_DetectionFrame();
    packetField = new SSL_GeometryFieldSize();
    packetGeo = new SSL_GeometryData();
    actualPositioning = new RobotsPositioning(TOLERANCE_RADIO, TOLERANCE_ORIENTATION, NUMBER_ROBOTS);
    fieldData = new FieldData();
}

void GameControl::sense_fieldData(QByteArray& buffer, int teamNumber){
    string message = string(buffer.data(), buffer.size());

    packet = new SSL_WrapperPacket();
    mode = packet->ParseFromString(message);
    *packetFrame = packet->detection();
    *packetGeo = packet->geometry(); //not used
    *packetField = packetGeo->field(); //not used

    // SENSE DATA
    float x,y,theta;
    for(int i = 0; i< NUMBER_ROBOTS; ++i){
        if(!teamNumber){
            x = packetFrame->robots_blue(i).x() / 1000.0;
            y = packetFrame->robots_blue(i).y() / 1000.0;
            theta = packetFrame->robots_blue(i).orientation();
            theta = theta >= 0 ? theta : 2.0*M_PI+theta;
        }
        else{
            x = packetFrame->robots_yellow(i).x() / 1000.0;
            y = packetFrame->robots_yellow(i).y() / 1000.0;
            theta = packetFrame->robots_blue(i).orientation();
            theta = theta >= 0 ? theta : 2.0*M_PI+theta;
        }
        actualPositioning->saveTarget(i, x, y, theta);

    }

    fieldData->setBallPosition(packetFrame->balls(0).x(), packetFrame->balls(0).y());

    motionPlanner->setTeamNumber(teamNumber);
    motionPlanner->setActualPositioning(actualPositioning);
    motionPlanner->setFieldData(fieldData);


    /*
    printf("\nParse status: %d",mode);
    printf("\nNumber of b: %d",packetFrame->balls_size());
    printf("\nNumber of yellow: %d",packetFrame->robots_yellow_size());
    printf("\nNumber of blue: %d",packetFrame->robots_blue_size());
    printf("\nField length: %d",packetField->field_length());
    printf("\nField width: %d",packetField->field_width());
    printf("\nTimestamp: %f\n",packetFrame->t_sent());
    */
}

void GameControl::plan_robotsPositioning(){

    if(!globalControl){ return; }

    // VIDEO 1
    {
        motionPlanner->planFollowBall(0, 50);
    }

    // VIDEO 2
    /*
    {
        motionPlanner->planPlayerKickBall(0);
    }
    */

    // VIDEO 3
    /*
    {
        if(flagControl[0]){
            flagControl[0] = motionPlanner->planPlayerFollowKickBall(0);
        }
    }
    */


    // VIDEO 4
    /*
    {
        motionPlanner->planGoalKeeper(0);
        motionPlanner->planPlayerGoalKick(1, 0); //planPlayerAvoidBall
    }
    */

    // VIDEO 5
    /*
    {
        int keeper = 0, i = 1;
        motionPlanner->planGoalKeeper(keeper);
        if(flagControl[0]) flagControl[0] = motionPlanner->planPlayerAvoidBall(i, keeper), cout<<"AVOID BALL"<<endl;
        else{
            if(flagControl[1]) flagControl[1] = motionPlanner->planRotationToGoal(i, keeper), cout<<"ROTATION TO GOAL"<<endl;
            else{
                if(flagControl[2]) flagControl[2] = motionPlanner->planPlayerGoalKick(i, keeper), cout<<"Goal Kick Position"<<endl;
                else{
                    globalControl = motionPlanner->planPlayerFollowKickBall(i), cout<<"FOLLOW BALL AND KICK"<<endl;
                    if(!globalControl) stopAll();
                }
            }
        }
    }
    */

    // VIDEO 6
    /*
    {
        int keeper=0, p1=1, p2=2;
        motionPlanner->planGoalKeeper(keeper);

        if(flagControl[0]) flagControl[0] = motionPlanner->planMovingToGoalByPassing(p1);
        else{
            flagControl[1] = motionPlanner->planRotationToGoal(p1, keeper);
        }

        if(flagControl[2]) flagControl[2] = motionPlanner->planMovingToPassingToGoal(p2);
        else{
           if(flagControl[3]) flagControl[3] = motionPlanner->planPlayerRotationToPass(p2, p1);
           else{
               if(!flagControl[1]){
                   motionPlanner->planDumbKick(p2);
               }
           }
        }

        globalControl = motionPlanner->planSenseGoalOrOut();
        if(!globalControl) stopAll();
    }
    */

    // VIDEO 7
    /*
    {
        if(flagControl[0]) flagControl[0] = motionPlanner->planMovingToPositions(0, 0);
        else{
            if(flagControl[1]) flagControl[1] = motionPlanner->planMovingToPositions(0, 1);
            else{
                if(flagControl[2]) flagControl[2] = motionPlanner->planMovingToPositions(0, 2);
                else{
                    if(flagControl[3]) flagControl[3] = motionPlanner->planMovingToPositions(0, 3);
                    else{
                        globalControl = motionPlanner->planMovingToPositions(0, 4);
                        if(!globalControl) stopAll();
                    }
                }
            }

        }


        if(!flagControl[1] && flagControl[2])
        if(!flagControl[2] && flagControl[3]) flagControl[3] = motionPlanner->planMovingToPositions(0, 3);
        if(!flagControl[3]) globalControl = motionPlanner->planMovingToPositions(0, 4);
        if(!globalControl) stopAll();
    }
    */
    //motionPlanner->planActions();
    //motionPlanner->planRotation();
}

void GameControl::enablePlanning(){
    memset(flagControl, 1, sizeof(flagControl));
    globalControl = 1;
}

void GameControl::stopAll(){
    globalControl = 0;
    motionPlanner->stopAll();
}
