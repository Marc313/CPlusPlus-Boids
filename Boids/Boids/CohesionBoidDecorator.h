#pragma once
#include "BoidDecorator.h"
class CohesionBoidDecorator : public BoidDecorator
{
public:
	CohesionBoidDecorator(Boid* _boidPtr);
	virtual ~CohesionBoidDecorator();
	Vector2 CalculateDirection(std::vector<Boid>& _neighbourBoids) override;

};

