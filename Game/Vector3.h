#ifndef VECTOR3_H
#define VECTOR3_H

#include "Point.h"

class Vector3 : public Point
{
public:

	Vector3(float X = 0, float Y = 0, float Z = 0);

	Vector3 operator =(const Vector3& p);

	Vector3 operator +(const Vector3 &p);
	Vector3 operator +=(const Vector3& p);

	Vector3 operator -(const Vector3& p);
	Vector3 operator -=(const Vector3& p);

	Vector3 operator *(float multiplier);
	Vector3 operator *=(float multiplier);

	Vector3 operator /(float multiplier);
	Vector3 operator /=(float multiplier);
};

#endif