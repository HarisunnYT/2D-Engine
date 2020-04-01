#include "Vector2.h"
#include <vector>

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

std::string Vector2::ToString()
{
	std::string strX = std::to_string(x);
	std::string strY = std::to_string(y);	

	std::string str = '(' + strX + ',' + strY + ')';
	return str;
}

Vector2 Vector2::FromString(std::string str)
{
	Vector2 vec;
	
	vector<std::string> values;
	std::string currentVal;

	for (char& c : str) 
	{
		if (c != '(')
		{
			if (c == ',' || c == ')')
			{
				values.push_back(currentVal);
				currentVal.clear();
			}
			else
			{
				currentVal.push_back(c);
			}
		}
	}

	vec.x = std::stof(values[0]);
	vec.y = std::stof(values[1]);

	return vec;
}

ostream& operator<<(ostream& stream, Vector2& p)
{
	stream << p.x << + " " << p.y;
	return stream;
}
