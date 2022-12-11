#include "BoidDecorator.h"

BoidDecorator::BoidDecorator(Boid* _boidPtr)
{
	boidPtr = _boidPtr;
}

BoidDecorator::~BoidDecorator()
{
}

Vector2 BoidDecorator::CalculateDirection(std::vector<Boid>& _neighbourBoids)
{
	return boidPtr->CalculateDirection(_neighbourBoids);
}
