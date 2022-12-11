#pragma once
#include "Boid.h"

class BoidDecorator : public Boid
{
public:
	BoidDecorator(Boid* _boidPtr);
	virtual ~BoidDecorator();
	Vector2 CalculateDirection(std::vector<Boid>& _neighbourBoids);

protected:
	Boid* boidPtr;
};

