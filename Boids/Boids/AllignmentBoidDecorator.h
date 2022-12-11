#pragma once
#include "BoidDecorator.h"

class AllignmentBoidDecorator : public BoidDecorator
{
public:
	AllignmentBoidDecorator(Boid* _boidPtr);
	virtual ~AllignmentBoidDecorator();
	const Vector2 CalculateDirection(const std::vector<Boid>& _neighbourBoids) const override;
};

