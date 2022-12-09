#include "Vector2.h"
#include <iostream>

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

Vector2 Vector2::operator+(Vector2 otherVector)
{
	return Vector2(x + otherVector.x, y + otherVector.y);
}

Vector2 Vector2::operator-(Vector2 otherVector)
{
	return Vector2(x - otherVector.x, y - otherVector.y);
}

Vector2 Vector2::operator*(float scalar)
{
	return Vector2(x * scalar, y * scalar);
}

Vector2 Vector2::operator/(float scalar)
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

// Public Methods //

float Vector2::magnitude()
{
	return std::sqrt(x * x + y * y);
}

Vector2 Vector2::normalized()
{
	Vector2 result = Vector2(x, y) / Vector2(x, y).magnitude();
	std::cout << result.magnitude();
	return result;
}

sf::Vector2f Vector2::ToSFMLVector2f()
{
	return sf::Vector2f(x, y);
}

sf::Vector2i Vector2::ToSFMLVector2i()
{
	return sf::Vector2i(x, y);
}

std::string Vector2::to_string() {
	return "x: " + std::to_string(x) + " y: " + std::to_string(y);
}

