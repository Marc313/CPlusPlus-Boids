#pragma once

#include <SFML/Graphics.hpp>

class Vector2
{
public:
	// Public Variables //
	float x;
	float y;

	// Constructors //
	Vector2();
	Vector2(float x, float y);

	// Operators //
	Vector2& operator=(const Vector2& v);
	Vector2 operator+(Vector2 otherVector);
	Vector2 operator-(Vector2 otherVector);
	Vector2 operator*(float scalar);
	Vector2 operator/(float scalar);
	friend std::ostream& operator<<(std::ostream& stream, const Vector2 vector);

	// Public Methods //
	float magnitude();
	Vector2 normalized();
	sf::Vector2f ToSFMLVector2f();
	sf::Vector2i ToSFMLVector2i();
	std::string to_string() const;

	// Static Methods
	static float distance(const Vector2 v1, const Vector2 v2);
};
