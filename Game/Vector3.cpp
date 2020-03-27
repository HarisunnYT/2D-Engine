#include "Vector3.h"

Vector3::Vector3(float X, float Y, float Z) : Point(X, Y, Z)
{

}

Vector3 Vector3::operator=(const Vector3& p)
{
	Vector3 vect;
	vect.x = x = p.x;
	vect.y = y = p.y;
	vect.z = z = p.z;

	return vect;
}

Vector3 Vector3::operator+(const Vector3 &p)
{
	Vector3 vect;
	vect.x = x + p.x;
	vect.y = y + p.y;
	vect.z = z + p.z;

	return vect;
}

Vector3 Vector3::operator+=(const Vector3& p)
{
	Vector3 vect;
	vect.x = x + p.x;
	vect.y = y + p.y;
	vect.z = z + p.z;

	return vect;
}

Vector3 Vector3::operator-(const Vector3& p)
{
	Vector3 vect;
	vect.x = x - p.x;
	vect.y = y - p.y;
	vect.z = z - p.z;

	return vect;
}

Vector3 Vector3::operator-=(const Vector3& p)
{
	Vector3 vect;
	vect.x = x - p.x;
	vect.y = y - p.y;
	vect.z = z - p.z;

	return vect;
}

Vector3 Vector3::operator*(float multiplier)
{
	Vector3 vect;
	vect.x = x * multiplier;
	vect.y = y * multiplier;
	vect.z = z * multiplier;

	return vect;
}

Vector3 Vector3::operator*=(float multiplier)
{
	Vector3 vect;
	vect.x = x * multiplier;
	vect.y = y * multiplier;
	vect.z = z * multiplier;

	return vect;
}

Vector3 Vector3::operator/(float multiplier)
{
	Vector3 vect;
	vect.x = x / multiplier;
	vect.y = y / multiplier;
	vect.z = z / multiplier;

	return vect;
}

Vector3 Vector3::operator/=(float multiplier)
{
	Vector3 vect;
	vect.x = x / multiplier;
	vect.y = y / multiplier;
	vect.z = z / multiplier;

	return vect;
}