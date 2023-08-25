#include "Position.h"


/////////////////////////

Position::Position()
{
    point.x = 0;
    point.y = 0;
    theta_=0;
    radius = 0.2;
}

Position::Position(float x,float y,float theta__)
{
    point.x = x;
    point.y = y;
    theta_=theta__;
    radius = 0.2;
}

float Position::x()
{
    return point.x;
}

float Position::y()
{
    return point.y;
}

float Position::theta()
{
    return theta_;
}

void Position::setValues(float x, float y, float theta__)
{
    point.x = x;
    point.y = y;
    theta_=theta__;
}

void Position::copyFrom(Position * p)
{
    this->setValues(p->x(),y(),p->theta());
}


