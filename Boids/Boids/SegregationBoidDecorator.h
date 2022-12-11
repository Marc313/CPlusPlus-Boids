#pragma once
#include "BoidDecorator.h"

class SegregationBoidDecorator : public BoidDecorator
{
public:
	SegregationBoidDecorator(Boid* _boidPtr);
	virtual ~SegregationBoidDecorator();
	Vector2 CalculateDirection(std::vector<Boid>& _neighbourBoids) override;
};

