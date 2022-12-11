#include "AllignmentBoidDecorator.h"
#include <numeric>

AllignmentBoidDecorator::AllignmentBoidDecorator(Boid* _boidPtr) : BoidDecorator::BoidDecorator(_boidPtr)
{
}

AllignmentBoidDecorator::~AllignmentBoidDecorator()
{
}

const Vector2 AllignmentBoidDecorator::CalculateDirection(const std::vector<Boid>& _neighbourBoids) const
{
	Vector2 direction = BoidDecorator::CalculateDirection(_neighbourBoids);

	// Calculate the average allignment of neighbours
	Vector2 totalAllignment = std::accumulate(_neighbourBoids.begin(), _neighbourBoids.end(), Vector2(), Boid::AccumulateBoidPositions);
	Vector2 averageAllignment = totalAllignment / _neighbourBoids.size();

	return direction + averageAllignment.normalized() * boidPtr->aScore;
}
