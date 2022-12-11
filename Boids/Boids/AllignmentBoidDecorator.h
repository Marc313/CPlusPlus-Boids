#pragma once
#include "BoidDecorator.h"

class AllignmentBoidDecorator : public BoidDecorator
{
public:
	AllignmentBoidDecorator(Boid* _boidPtr);
	virtual ~AllignmentBoidDecorator();
	Vector2 CalculateDirection(std::vector<Boid>& _neighbourBoids) override;
};

