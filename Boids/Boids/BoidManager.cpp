#include "BoidManager.h"
#include <iostream>

BoidManager::BoidManager()
{
	numOfBoids = 50;

	SpawnBoids();
}

BoidManager::~BoidManager()
{
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
		std::vector<Boid> neighbours = CalculateNeighbours(boid);
		boid.OnUpdate(_window, neighbours);
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
		Boid boid = Boid::makeBoid();
		boids.push_back(boid);
	}
}

std::vector<Boid> BoidManager::CalculateNeighbours(Boid& _boid)
{
	std::vector<Boid> neighbours;

	for (Boid& otherBoid : boids) 
	{
		float distance = Vector2::distance(_boid.position, otherBoid.position);
		if (distance < _boid.neighbourRange && &otherBoid != &_boid) 
		{
			neighbours.push_back(otherBoid);
		}
	}

	//neighbours.erase(std::find(neighbours.begin(), neighbours.end(), _boid));

	return neighbours;
}
