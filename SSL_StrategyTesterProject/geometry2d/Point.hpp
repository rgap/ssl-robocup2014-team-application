#pragma once

#include <math.h>
#include <boost/optional.hpp>
#include <QPointF>
#include <iostream>
#include "util.h"

using namespace std;

namespace Geometry2d
{
	/**
	Simple class to represent a point in 2d space. Uses floating point coordinates
	*/
	class Point
	{
		public:
			typedef boost::optional<Point> Optional;

			/**
			default constrctor.
			initializes point to (0,0)
			usage as Point p = Point();
			*/
			Point()
			{
				x = y = 0;
			}

			/**
			overloaded constructor.
			sets the point to x,y
			usage as Point p = Point(x,y);
			@param x the x coordinate
			@param y the y coordinate
			*/
			Point(float x, float y)
			{
				this->x = x;
				this->y = y;
                this->cost = 0;
			}
			
            /*
			template<class T>
			Point(const T &other)
			{
                x = other.x();
                y = other.y();
			}
            */
			/**
			 * to draw stuff and interface with QT
			 */
			QPointF toQPointF() const
			{
				return QPointF(x, y);
			}
			
			/**
			 * does vector addition
			 * adds the + operator, shorthand
			 */
			Point operator+(Point other) const
			{
				return Point(x + other.x, y + other.y);
			}
			/**
			 * see operator+
			 * does vector subtraction, note the operator
			 * without parameter, it is the negative
			 */
			Point operator-(Point other) const
			{
				return Point(x - other.x, y - other.y);
			}

			/**
			 * multiplies the point by a -1 vector
			 */
			Point operator-() const
			{
				return Point(-x, -y);
			}

			/**
			 * see operator+
			 * this modifies the value instead of returning a new value
			 */
			Point &operator+=(Point other)
			{
				x += other.x;
				y += other.y;

				return *this;
			}

			/**
			 * see operator-
			 * this modifies the value instead of returning a new value
			 */
			Point &operator-=(Point other)
			{
				x -= other.x;
				y -= other.y;

				return *this;
			}

			/**
			 * see operator*
			 * this modifies the value instead of returning a new value
			 */
			Point &operator*=(float s)
			{
				x *= s;
				y *= s;

				return *this;
			}

			/**
			 * see operator/
			 * this modifies the value instead of returning a new value
			 */
			Point &operator/=(float s)
			{
				x /= s;
				y /= s;

				return *this;
			}

			/**
			 * adds the / operator for vectors
			 *  scalar division
			 */
			Point operator/(float s) const
			{
				return Point(x / s, y / s);
			}
			/**
			 * adds the * operator for vectors
			 * scalar multiplication
			 */
			Point operator*(float s) const
			{
				return Point(x * s, y * s);
			}

			/**
			 * compares two points to see if both x and y are the same
			 * adds the == operator
             *
             * << REVIEW >>
			 */
            /*
			bool operator==(Point other) const
			{
				return x == other.x && y == other.y;
			}
            */
			
			/**
			 * this is the negation of operator operator !=
			 */
			bool operator!=(Point other) const
			{
				return x != other.x || y != other.y;
            }
			
			/**
			computes the dot product of this point and another.
			behaves as if the points were 2d vectors
			@param p the second point
			@return the dot product of the two
			*/
			float dot(Point p) const
			{
				return x * p.x + y * p.y;
			}
			
			/**
			find out of the point is 0,0
			@return true if the point is (0,0)
			*/
			bool isZero() const
			{
				return x == 0 && y == 0;
			}
			
			/**
			computes the magnitude of the point, as if it were a vector
			@return the magnitude of the point
			*/
			float mag() const
			{
				return sqrtf(x * x + y * y);
			}
			
			/**
			computes magnitude squared
			this is faster than mag()
			@return the magnitude squared
			*/
			float magsq() const
			{
				return x * x + y * y;
			}
			
			/**
			rotates the point around another point by specified angle in the CCW direction
			@param origin the point to rotate around
			@param angle the angle in degrees
			*/
			void rotate(const Point &origin, float angle)
			{
				*this -= origin;
				rotate(angle);
				*this += origin;
			}
			
			/**
			* rotates the point around the origin
			*/
			void rotate(float angle)
			{
				float newX = x * cos(angle * DegreesToRadians) - y * sin(angle * DegreesToRadians);
				float newY = y * cos(angle * DegreesToRadians) + x * sin(angle * DegreesToRadians);
				x = newX;
				y = newY;
			}
			
			/**
			 * Like rotate(), but returns a new point instead of changing *this
			 */
			Point rotated(float angle) const
			{
				float newX = x * cos(angle * DegreesToRadians) - y * sin(angle * DegreesToRadians);
				float newY = y * cos(angle * DegreesToRadians) + x * sin(angle * DegreesToRadians);
				return Point(newX, newY);
			}

			/**
			* static function to use rotate
			*/
			static Point rotate(const Point& pt, const Point& origin, float angle)
			{
				Point newPt = pt;
				newPt.rotate(origin, angle);
				return newPt;
			}

			/**
			computes the distance from the current point to another
			@param other the point to find the distance to
			@return the distance between the points
			*/
			float distTo(const Point &other) const
			{
				Point delta = other - *this;
				return delta.mag();
			}

            float nonEucdistTo(const Point &other) const
            {
                return (other.y - this->y)*(other.y - this->y) + (other.x - this->x)*(other.x - this->x);
            }

            float angleVal(const Point &other) const
            {
                float theta;
                float dif_y = other.y-y, dif_x = other.x-x;
                if(dif_x == 0.0){
                    theta = (dif_y > 0.0) ? M_PI/2 : - M_PI/2;
                } else if(dif_y == 0.0){
                    theta = (dif_x > 0.0) ? 0 :  M_PI;
                } else{
                    theta = atan2(dif_y, dif_x);
                }

                if(theta < 0.0){
                    theta = 2*M_PI + theta;
                }
                return theta;
            }
			
			/**
			* Returns a vector with the same direction as this vector but with magnitude one,
			* unless this vector is zero.
			*/
			Point normalized() const
			{
				float m = mag();
				if (m == 0)
				{
					return Point(0, 0);
				}
				
				return Point(x / m , y / m);
			}
			
			/**
			* Returns true if this point is within the given distance (threshold) of (pt)
			*/
			bool nearPoint(const Point &other, float threshold) const
			{
				return (*this - other).magsq() <= (threshold * threshold);
            }
			
			/**
			* Returns the angle of this point in radians CCW from +X.
			*/
			float angle() const
			{
				return atan2(y, x);
			}
			
			/**
			* Returns a unit vector in the given direction (in radians)
			*/
			static Point direction(float theta)
			{
				return Point(cos(theta), sin(theta));
			}
			
			/** returns the perpendicular to the point, Clockwise */
			Point perpCW() const
			{
				return Point(y, -x);
			}
			
			/** returns the perpendicular to the point, Counter Clockwise */
			Point perpCCW() const
			{
				return Point(-y, x);
			}
			
			/** saturates the magnitude of a vector */
			static Geometry2d::Point saturate(Geometry2d::Point value, float max) {
				float mag = value.mag();
				if (mag > fabs(max))
				{
					return value.normalized() * fabs(max);
				}
				return value;
			}

            /** method1 = returns the angle between the two points (radians) */
			float angleTo(const Point& other) const
			{
				return acos(normalized().dot(other.normalized()));
			}

            float angleTo(const Point* other) const
            {
                return acos(normalized().dot(other->normalized()));
            }

            /** method2 = returns the angle between the two points (radians) */
            float getSlope(const Point& other) const
            {
                return (other.y - y)/(other.x - x);
            }

            float getSlope(const Point* other) const
            {
                return (other->y - y)/(other->x - x);
            }
			
			float cross(const Point &other) const
			{
				return x * other.y - y * other.x;
			}
			
			/** the x coordinate */
			float x;
			
			/** the y coordinate */
			float y;

            double cost; // << REVIEW >>

	}; // \class Point

	// global operations

	/**
	 * adds the * operator for vectors
	 * scalar multiplication
	 */
	inline Point operator*(const float& s, const Point& pt)
	{
		return Point(pt.x * s, pt.y * s);
	}


    /**
      << REVIEW >>
    */
    inline bool operator< (const Point& point1, const Point &point2)
    {
        return point1.cost > point2.cost;
    }

    inline bool operator> (const Point& point1, const Point &point2)
    {
        return point1.cost < point2.cost;
    }

    inline bool operator== (const Point& point1, const Point &point2)
    {
        return (point1.x == point2.x) && (point1.y == point2.y);
    }
}
