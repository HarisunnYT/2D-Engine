#ifndef VECTOR2_H
#define VECTOR2_H

#include "Point.h"

#include <iostream>

class Vector2
{
public:

	float x;
	float y;

	Vector2(float X = 0, float Y = 0);

	Vector2& Equals(const Vector2& p);
	Vector2& Add(const Vector2& p);
	Vector2& Subtract(const Vector2& p);
	Vector2& Multiply(float value);
	Vector2& Divide(float value);

	Vector2& operator =(const Vector2& p);

	Vector2& operator +(const Vector2& p);
	Vector2& operator +=(const Vector2& p);

	Vector2& operator -(const Vector2& p);
	Vector2& operator -=(const Vector2& p);

	Vector2& operator *(float multiplier);
	Vector2& operator *=(float multiplier);

	Vector2& operator /(float multiplier);
	Vector2& operator /=(float multiplier);
};

ostream& operator <<(ostream& stream, Vector2& p);

#endif