#pragma once
#include "BoidDecorator.h"
class CohesionBoidDecorator : public BoidDecorator
{
public:
	CohesionBoidDecorator(Boid* _boidPtr);
	virtual ~CohesionBoidDecorator();
	const Vector2 CalculateDirection(const std::vector<Boid>& _neighbourBoids) const override;

};

