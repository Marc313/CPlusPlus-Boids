#include "CohesionBoidDecorator.h"
#include <numeric>

CohesionBoidDecorator::CohesionBoidDecorator(Boid* _boidPtr) : BoidDecorator::BoidDecorator(_boidPtr)
{
}

CohesionBoidDecorator::~CohesionBoidDecorator()
{
}

const Vector2 CohesionBoidDecorator::CalculateDirection(const std::vector<Boid>& _neighbourBoids) const
{
	Vector2 direction = BoidDecorator::CalculateDirection(_neighbourBoids);

	// Calculate the center of mass of neighbours excl self
	Vector2 totalPosition = std::accumulate(_neighbourBoids.begin(), _neighbourBoids.end(), Vector2(), Boid::AccumulateBoidPositions);
	Vector2 localCenterOfMass = totalPosition / _neighbourBoids.size();

	// Return direction to this center
	Vector2 cohesion = localCenterOfMass - position;
	return direction + localCenterOfMass * boidPtr->cScore;
}
