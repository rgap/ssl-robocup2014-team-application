#ifndef ROBOTSPOSITIONING_H
#define ROBOTSPOSITIONING_H

#include <string.h>
#include "Position.h"

#define NUMBER_ROBOTS 6
#define TOLERANCE_RADIO 0.01
#define TOLERANCE_ORIENTATION DEG2RAD(1)
#define DISTANCEWHEEL 1

class RobotsPositioning
{
private:
    float toleranceRadio;
    float toleranceTheta;
    int numRobots;
public:
    Position *robotPosition; // x, y, orientation
    RobotsPositioning();
    RobotsPositioning(float toleranceRadio_, float toleranceTheta_, int numRobots_);

    Position* getRobot(int robotID);
    Point* getRobotPoint(int robotID);

    float getDistanceTo(int robotID, Position* position);
    float getDistanceTo(int robotID, Point& point);

    bool verifyPosition(int robotID, float x, float y, float theta);
    bool verifyCoordinate(int robotID, float x, float y);
    bool verifyRotation(int robotID, float theta);

    bool verifyPosition(int robotID, Position* position, float toleranceRadio_ = -1);
    bool verifyCoordinate(int robotID, Position* position, float toleranceRadio_ = -1);
    bool verifyRotation(int robotID, Position* position);

    void saveTarget(int robotID, float x, float y, float theta);
    void saveTarget(int robotID, Point &p, float theta);
};

#endif // ROBOTSPOSITIONING_H
