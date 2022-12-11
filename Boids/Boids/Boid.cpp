#include "Boid.h"
#include "Time.h"
#include <iostream>
#include <numeric>
#include "AllignmentBoidDecorator.h"
#include "CohesionBoidDecorator.h"
#include "SegregationBoidDecorator.h"

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

Boid& Boid::operator=(const Boid& v)
{
	speed = v.speed;
	position = v.position;
	direction = v.direction;

	neighbourRange = v.neighbourRange;
	cScore = v.cScore;
	sScore = v.sScore;
	aScore = v.aScore;

	shape = v.shape;

	return *this;
}

void Boid::OnUpdate(sf::RenderWindow& _window, std::vector<Boid>& _neighbourBoids)
{
	Vector2 cohesionDirection = CalculateCohesion(_neighbourBoids);
	Vector2 segregationDirection = CalculateSegregation(_neighbourBoids);
	Vector2 allignmentDirection = CalculateAllignment(_neighbourBoids);

	Vector2 newDirection = cohesionDirection * cScore + segregationDirection * sScore + allignmentDirection * aScore;

	// If the decorator would have worked I would do this instead of the lines above
	// Vector2 newDirection = CalculateDirection(_neighbourBoids);

	if (newDirection.magnitude() > 0.1f) 
	{
		direction = newDirection.normalized();
	}

	Move();
	Draw(_window);
}

Vector2 Boid::CalculateDirection(std::vector<Boid>& _neighbourBoids)
{
	return Vector2();
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

Boid Boid::makeBoid()
{
	Boid boid = Boid();

	boid = CohesionBoidDecorator(&boid);
	boid = SegregationBoidDecorator(&boid);
	boid = AllignmentBoidDecorator(&boid);

	return boid;
}

void Boid::InitializeDefaultVariables()
{
	speed = 30;
	neighbourRange = 700;
	cScore = 1;
	sScore = 100.0f;
	aScore = 1;
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

Vector2 Boid::AccumulateBoidPositions(Vector2 _acc, Boid _boid)
{
	return _acc + _boid.GetPosition();
}

Vector2 Boid::AccumulateBoidDirection(Vector2 _acc, Boid _boid)
{
	return _acc + _boid.direction;
}

Vector2 Boid::CalculateCohesion(std::vector<Boid>& _neighbourBoids)
{
	// Calculate the center of mass of neighbours excl self
	// Return direction to this center
	Vector2 totalPosition = std::accumulate(_neighbourBoids.begin(), _neighbourBoids.end(), Vector2(), AccumulateBoidPositions );
	Vector2 localCenterOfMass = totalPosition / _neighbourBoids.size();

	return localCenterOfMass - position;
}

Vector2 Boid::CalculateSegregation(std::vector<Boid>& _neighbourBoids)
{
	Vector2 avoidanceDirection{};
	std::for_each(_neighbourBoids.begin(), _neighbourBoids.end(), [&](Boid& _boid) -> void
		{
			float distance = Vector2::distance(_boid.position, position);
			avoidanceDirection = avoidanceDirection - (_boid.position - position)/distance;
	});

	return avoidanceDirection/_neighbourBoids.size();
}

Vector2 Boid::CalculateAllignment(std::vector<Boid>& _neighbourBoids)
{
	// Calculate the average allignment of neighbours
	Vector2 totalAllignment = std::accumulate(_neighbourBoids.begin(), _neighbourBoids.end(), Vector2(), AccumulateBoidPositions);
	Vector2 averageAllignment = totalAllignment / _neighbourBoids.size();

	return averageAllignment.normalized();
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