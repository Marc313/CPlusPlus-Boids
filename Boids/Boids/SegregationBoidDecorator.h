#pragma once
#include "BoidDecorator.h"

class SegregationBoidDecorator : public BoidDecorator
{
public:
	SegregationBoidDecorator(Boid* _boidPtr);
	virtual ~SegregationBoidDecorator();
	const Vector2 CalculateDirection(const std::vector<Boid>& _neighbourBoids) const override;
};

