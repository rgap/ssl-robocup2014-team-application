#pragma once

#include <math.h>

#define DEG2RAD(deg) (deg * M_PI / 180.0)
#define RAD2DEG(rad) (rad * 180.0 / M_PI)

const float DegreesToRadians = M_PI / 180.0;
const float RadiansToDegrees = 180.0 / M_PI;

template<typename T>
static inline T sign(T f)
{
	if (f < 0)
	{
		return -1;
	} else if (f > 0)
	{
		return 1;
	} else {
		return 0;
	}
}
