#include "Vector2.h"
#include <iostream>
#include <math.h>
#include <stdlib.h>

Vector2::Vector2() {
	x = 0;
	y = 0;
}

Vector2::Vector2(float x, float y) {
	this->x = x;
	this->y = y;
}

Vector2& Vector2::operator=(const Vector2& v)
{
	x = v.x;
	y = v.y;
	return *this;
}

Vector2 Vector2::operator+(const Vector2 otherVector) const
{
	return Vector2(x + otherVector.x, y + otherVector.y);
}

Vector2 Vector2::operator-(const Vector2 otherVector) const
{
	return Vector2(x - otherVector.x, y - otherVector.y);
}

Vector2 Vector2::operator*(const float scalar) const
{
	return Vector2(x * scalar, y * scalar);
}

Vector2 Vector2::operator/(const float scalar) const
{
	if (scalar == 0)
	{
		std::cout << "Dividing by 0 not allowed, operation ignored" << std::endl;
		return Vector2(x, y);
	}
	else
	{
		return Vector2(x / scalar, y / scalar);
	}
}

std::ostream& operator<<(std::ostream& stream, const Vector2 vector)
{
	return stream << vector.to_string();
}

// Public Methods //

float Vector2::magnitude()
{
	return std::sqrt(x * x + y * y);
}

Vector2 Vector2::normalized()
{
	Vector2 result = Vector2(x, y) / Vector2(x, y).magnitude();
	return result;
}

sf::Vector2f Vector2::ToSFMLVector2f() const
{
	return sf::Vector2f(x, y);
}

sf::Vector2i Vector2::ToSFMLVector2i() const
{
	return sf::Vector2i(x, y);
}

std::string Vector2::to_string() const {
	return "x: " + std::to_string(x) + " y: " + std::to_string(y);
}

float Vector2::distance(const Vector2& v1, const Vector2& v2)
{
	return std::sqrt(pow(abs(v1.x - v2.x), 2) + pow(abs(v1.y - v2.y), 2));
}
