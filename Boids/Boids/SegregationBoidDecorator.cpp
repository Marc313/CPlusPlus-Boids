#include "SegregationBoidDecorator.h"

SegregationBoidDecorator::SegregationBoidDecorator(Boid* _boidPtr) : BoidDecorator::BoidDecorator(_boidPtr)
{
}

SegregationBoidDecorator::~SegregationBoidDecorator()
{
}

const Vector2 SegregationBoidDecorator::CalculateDirection(const std::vector<Boid>& _neighbourBoids) const
{
	Vector2 direction = BoidDecorator::CalculateDirection(_neighbourBoids);

	Vector2 avoidanceDirection{};
	std::for_each(_neighbourBoids.begin(), _neighbourBoids.end(), [&](const Boid& _boid) -> void
		{
			// Divide direction away from other boid by the distance to this boid, 
			// so the vectors from boids close by weigh more 
			float distance = Vector2::distance(_boid.position, position);
			avoidanceDirection = avoidanceDirection - (_boid.position - position) / distance;
		});

	Vector2 segregation = avoidanceDirection / _neighbourBoids.size();
	return direction + segregation * boidPtr->sScore;
}
