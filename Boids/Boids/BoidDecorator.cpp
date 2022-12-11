#include "BoidDecorator.h"

BoidDecorator::BoidDecorator(Boid* _boidPtr)
{
	boidPtr = _boidPtr;
}

BoidDecorator::~BoidDecorator()
{
}

Vector2 const BoidDecorator::CalculateDirection(const std::vector<Boid>& _neighbourBoids) const
{
	return boidPtr->CalculateDirection(_neighbourBoids);
}
