#include "Vector3.h"

Vector3::Vector3(float X, float Y, float Z) : Point(X, Y, Z)
{
	
}

Vector3& Vector3::Equals(const Vector3& p)
{
	x = p.x;
	y = p.y;
	z = p.z;

	return *this;
}

Vector3& Vector3::Add(const Vector3& p)
{
	x += p.x;
	y += p.y;
	z += p.z;

	return *this;
}

Vector3& Vector3::Subtract(const Vector3& p)
{
	x -= p.x;
	y -= p.y;
	z -= p.z;

	return *this;
}

Vector3& Vector3::Multiply(float value)
{
	x *= value;
	y *= value;
	z *= value;

	return *this;
}

Vector3& Vector3::Divide(float value)
{
	x /= value;
	y /= value;
	z /= value;

	return *this;
}

Vector3& Vector3::operator=(const Vector3& p)
{
	return this->Equals(p);
}

Vector3& Vector3::operator+(const Vector3 &p)
{
	return this->Add(p);
}

Vector3& Vector3::operator+=(const Vector3& p)
{
	return this->Add(p);
}

Vector3& Vector3::operator-(const Vector3& p)
{
	return this->Subtract(p);
}

Vector3& Vector3::operator-=(const Vector3& p)
{
	return this->Subtract(p);
}

Vector3& Vector3::operator*(float multiplier)
{
	return this->Multiply(multiplier);
}

Vector3& Vector3::operator*=(float multiplier)
{
	return this->Multiply(multiplier);
}

Vector3& Vector3::operator/(float multiplier)
{
	return this->Divide(multiplier);
}

Vector3& Vector3::operator/=(float multiplier)
{
	return this->Divide(multiplier);
}

Vector3& Vector3::Zero()
{
	return this->Multiply(0);
}
