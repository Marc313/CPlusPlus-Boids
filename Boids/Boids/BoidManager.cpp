#include "BoidManager.h"
#include <iostream>

BoidManager::BoidManager()
{
	numOfBoids = 50;

	SpawnBoids();
}

BoidManager::BoidManager(int _numOfBoids)
{
	numOfBoids = _numOfBoids;

	SpawnBoids();
}

void BoidManager::OnUpdate(sf::RenderWindow& _window)
{
	for (Boid& boid : boids)
	{
		boid.OnUpdate(_window);
	}
}

void BoidManager::Print()
{
	std::cout << "Manager Found\n";
}

void BoidManager::SpawnBoids()
{
	for (size_t i = 0; i < numOfBoids; i++)
	{
		Boid boid = Boid(this);
		boids.push_back(boid);
	}
}
