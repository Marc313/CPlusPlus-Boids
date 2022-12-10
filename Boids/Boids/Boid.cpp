#include "Boid.h"
#include "Time.h"
#include <algorithm>
#include <functional>
#include <numeric>
#include <iostream>

Boid::Boid()
{
	InitializeDefaultVariables();
}

//Boid::Boid(BoidManager* _manager)
//{
//	manager = _manager;
//	InitializeDefaultVariables();
//}

Boid::~Boid()
{
}

void Boid::OnUpdate(sf::RenderWindow& _window, std::vector<Boid>& _neighbourBoids)
{
	Vector2 cohesionDirection = CalculateCohesion(_neighbourBoids);
	Vector2 segregationDirection;
	Vector2 allignmentDirection;

	direction = cohesionDirection + segregationDirection + allignmentDirection;

	direction = direction.normalized();

	Move();
	Draw(_window);
}

Vector2 Boid::GetPosition() 
{
	return position;
}

void Boid::SetPosition(Vector2 _newPos)
{
	position = _newPos;
	shape.setPosition(_newPos.ToSFMLVector2f());
}

void Boid::InitializeDefaultVariables()
{
	//manager->Print();
	speed = 30;
	neighbourRange = 800;
	shape = sf::CircleShape(10);
	SetPosition(GetRandomPos());
	direction = GetRandomDirection();
}

void Boid::Move()
{
	Vector2 newPosition = position + direction * speed * Time::deltaTime;
	SetPosition(newPosition);
}

void Boid::Draw(sf::RenderWindow& _window)
{
	_window.draw(shape);
}

Vector2 AccumulateBoidPositions(Vector2 _acc, Boid _boid)
{
	return _acc + _boid.GetPosition();
}

Vector2 Boid::CalculateCohesion(std::vector<Boid>& _neighbourBoids)
{
	// Calculate the center of mass of neighbours excl self
	// Return direction to this center
	Vector2 totalPosition = std::accumulate(_neighbourBoids.begin(), _neighbourBoids.end(), Vector2(), AccumulateBoidPositions );
	Vector2 localCenterOfMass = totalPosition / _neighbourBoids.size();

	std::cout << localCenterOfMass << std::endl;

	return localCenterOfMass - position;
}

Vector2 Boid::CalculateSegregation()
{


	return Vector2();
}

Vector2 Boid::CalculateAllignment()
{
	// Calculate the average allignment of neighbours


	return Vector2();
}

Vector2 Boid::GetRandomPos()
{
	int x = rand() % 800;
	int y = rand() % 800;

	return Vector2(x, y);
}

Vector2 Boid::GetRandomDirection()
{
	// Generate between -50 and 50, so negative and positive direction are as likely.
	// We use a large number since rand() returns an int
	float x = rand() % 100 - 50;
	float y = rand() % 100 - 50;

	return Vector2(x, y).normalized();
}