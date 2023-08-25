#ifndef POSITION_H
#define POSITION_H

#include "geometry2d/Point.hpp"
#include "geometry2d/Circle.hpp"

using namespace Geometry2d;

class Position
{
public:
    Position();
    Position(float x,float y,float theta_);
    Position(Point *point_);
    float x();
    float y();
    float theta();
    void setValues(float x, float y, float theta_);
    void copyFrom(Position * position);
    Point point;

    float radius;

private:
    float theta_; //  orientation
};

#endif // POSITION_H
