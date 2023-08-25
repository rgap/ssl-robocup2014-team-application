#include "RobotsPositioning.h"

RobotsPositioning::RobotsPositioning(){
}

RobotsPositioning::RobotsPositioning(float toleranceRadio_, float toleranceTheta_, int numRobots_){
    toleranceRadio = toleranceRadio_;
    toleranceTheta = toleranceTheta_;
    numRobots = numRobots_;
    robotPosition = new Position[numRobots];
    int i,j;
    for(i = 0; i < numRobots;i++){
        robotPosition[i].setValues(0,0,0);
    }
}

Position* RobotsPositioning::getRobot(int robotID){
    return &robotPosition[robotID];
}

Point* RobotsPositioning::getRobotPoint(int robotID){
    return &robotPosition[robotID].point;
}

float RobotsPositioning::getDistanceTo(int robotID, Position* position){
    return robotPosition[robotID].point.distTo(position->point);
}

float RobotsPositioning::getDistanceTo(int robotID, Point& point){
    return robotPosition[robotID].point.nonEucdistTo(point);
}

bool RobotsPositioning::verifyPosition(int robotID, float x, float y, float theta){
    Geometry2d::Point p(robotPosition[robotID].x(), robotPosition[robotID].y());
    //(robotPosition[robotID].theta() <= (theta + toleranceTheta) && robotPosition[robotID].theta() >= (theta - toleranceTheta));
    //robotPosition[robotID].point.nearPoint(p, toleranceRadio) &&
    return false;
}

bool RobotsPositioning::verifyPosition(int robotID, Position* position, float toleranceRadio_){
    float radio;
    if(toleranceRadio_ == -1){
        radio = toleranceRadio;
    }
    else{
        radio = toleranceRadio_;
    }
    return ((robotPosition[robotID].theta() <= (position->theta() + toleranceTheta)) && (robotPosition[robotID].theta() >= (position->theta() - toleranceTheta))
            && robotPosition[robotID].point.nearPoint(position->point, radio));
}

bool RobotsPositioning::verifyCoordinate(int robotID, float x, float y){
    Geometry2d::Point p(robotPosition[robotID].x(), robotPosition[robotID].y());
    return false;
    //robotPosition[robotID].point.nearPoint(p, toleranceRadio) &&
}

bool RobotsPositioning::verifyCoordinate(int robotID, Position* position, float toleranceRadio_){
    float radio;
    if(toleranceRadio_ == -1){
        radio = toleranceRadio;
    }
    else{
        radio = toleranceRadio_;
    }
    return robotPosition[robotID].point.nearPoint(position->point, radio);
}

bool RobotsPositioning::verifyRotation(int robotID, float theta){
    return (robotPosition[robotID].theta() <= (theta + toleranceTheta) && robotPosition[robotID].theta() >= (theta - toleranceTheta));
}

bool RobotsPositioning::verifyRotation(int robotID, Position* position){
    //cout<<robotPosition[robotID].theta()<<endl;
    return (robotPosition[robotID].theta() <= (position->theta() + toleranceTheta) && robotPosition[robotID].theta() >= (position->theta() - toleranceTheta));
}

void RobotsPositioning::saveTarget(int robotID, float x, float y, float theta){
    robotPosition[robotID].setValues(x,y,theta);
}

void RobotsPositioning::saveTarget(int robotID, Point &p, float theta){
    robotPosition[robotID].setValues(p.x,p.y,theta);
}
