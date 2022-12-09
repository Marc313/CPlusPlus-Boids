#include "Boid.h"
#include "Time.h"

Boid::Boid()
{
	InitializeDefaultVariables();
}

Boid::Boid(BoidManager* _manager)
{
	manager = _manager;
	InitializeDefaultVariables();
}

Boid::~Boid()
{
}

void Boid::OnUpdate(sf::RenderWindow& _window)
{
	Vector2 cohesionDirection;
	Vector2 segregationDirection;
	Vector2 allignmentDirection;

	direction = cohesionDirection + segregationDirection + allignmentDirection;

	Move();
	Draw(_window);
}

void Boid::SetPosition(Vector2 _newPos)
{
	position = _newPos;
	shape.setPosition(_newPos.ToSFMLVector2f());
}

void Boid::InitializeDefaultVariables()
{
	//manager->Print();
	speed = 10;
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

Vector2 Boid::CalculateCohesion()
{
	return Vector2();
}

Vector2 Boid::CalculateSegregation()
{
	return Vector2();
}

Vector2 Boid::CalculateAllignment()
{
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