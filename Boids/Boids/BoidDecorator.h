#pragma once
#include "Boid.h"

class BoidDecorator : public Boid
{
public:
	BoidDecorator(Boid* _boidPtr);
	virtual ~BoidDecorator();
	virtual const Vector2 CalculateDirection(const std::vector<Boid>& _neighbourBoids) const;

protected:
	Boid* boidPtr;
};

