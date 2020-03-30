#include "Vector2.h"

Vector2::Vector2(float X, float Y)
{
	x = X;
	y = Y;
}

Vector2& Vector2::Equals(const Vector2& p)
{
	x = p.x;
	y = p.y;

	return *this;
}

Vector2& Vector2::Add(const Vector2& p)
{
	x += p.x;
	y += p.y;

	return *this;
}

Vector2& Vector2::Subtract(const Vector2& p)
{
	x -= p.x;
	y -= p.y;

	return *this;
}

Vector2& Vector2::Multiply(float value)
{
	x *= value;
	y *= value;

	return *this;
}

Vector2& Vector2::Divide(float value)
{
	x /= value;
	y /= value;

	return *this;
}

Vector2& Vector2::operator=(const Vector2& p)
{
	return this->Equals(p);
}

Vector2& Vector2::operator+(const Vector2& p)
{
	return this->Add(p);
}

Vector2& Vector2::operator+=(const Vector2& p)
{
	return this->Add(p);
}

Vector2& Vector2::operator-(const Vector2& p)
{
	return this->Subtract(p);
}

Vector2& Vector2::operator-=(const Vector2& p)
{
	return this->Subtract(p);
}

Vector2& Vector2::operator*(float multiplier)
{
	return this->Multiply(multiplier);
}

Vector2& Vector2::operator*=(float multiplier)
{
	return this->Multiply(multiplier);
}

Vector2& Vector2::operator/(float multiplier)
{
	return this->Divide(multiplier);
}

Vector2& Vector2::operator/=(float multiplier)
{
	return this->Divide(multiplier);
}

Vector2& Vector2::Zero()
{
	return this->Multiply(0);
}

ostream& operator<<(ostream& stream, Vector2& p)
{
	stream << p.x << + " " << p.y;
	return stream;
}
