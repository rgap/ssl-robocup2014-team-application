#include "FieldData.h"

FieldData::FieldData()
{
    ballRadio = 0.3;
}

void FieldData::setBallPosition(int x, int y){
    ball.x = x / 1000.0;
    ball.y = y / 1000.0;
}

