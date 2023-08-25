#ifndef FIELDDATA_H
#define FIELDDATA_H

#include "geometry2d/Point.hpp"

using namespace Geometry2d;

class FieldData
{

public:
    Point ball;
    float ballRadio;

    FieldData();
    void setBallPosition(int x, int y);
};

#endif // FIELDDATA_H
