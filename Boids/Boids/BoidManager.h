#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "Vector2.h"
#include "Boid.h"

class BoidManager
{
	public:
		// Constructors
		BoidManager();
		BoidManager(int _numOfBoids);

		void OnUpdate(sf::RenderWindow& _window);
		void Print();

	private:
		// Private fields
		int numOfBoids;
		std::vector<Boid> boids;

		// Private Functions

		void SpawnBoids();
};

