#pragma once
#include <SFML/Graphics.hpp>
#include "Vector2.h"

class Boid
{
	public:
		float neighbourRange;

		Boid();
		//Boid(class BoidManager* _manager);
		virtual ~Boid();
		//void OnUpdate(sf::RenderWindow& _window);
		void OnUpdate(sf::RenderWindow& _window, std::vector<Boid>& _neighbourBoids);
		Vector2 GetPosition();
		void SetPosition(Vector2 _newPos);
		Vector2 position;

	private:	
		// Private fields
		float speed;
		Vector2 direction;
		std::vector<Boid> neighbourBoids;

		sf::CircleShape shape;
		//class BoidManager* manager;

		// Private Functions
		void InitializeDefaultVariables();
		void Move();
		void Draw(sf::RenderWindow& _window);

		Vector2 CalculateCohesion(std::vector<Boid>& _neighbourBoids);
		Vector2 CalculateSegregation();
		Vector2 CalculateAllignment();

		Vector2 GetRandomPos();
		Vector2 GetRandomDirection();
};

