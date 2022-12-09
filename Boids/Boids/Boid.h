#pragma once
#include <SFML/Graphics.hpp>
#include "Vector2.h"

class Boid
{
	public:
		Boid();
		Boid(class BoidManager* _manager);
		virtual ~Boid();
		void OnUpdate(sf::RenderWindow& _window);
		void SetPosition(Vector2 _newPos);

	private:	
		// Private fields
		float speed;
		Vector2 direction;
		Vector2 position;
		sf::CircleShape shape;
		class BoidManager* manager;
		

		// Private Functions
		void InitializeDefaultVariables();
		void Move();
		void Draw(sf::RenderWindow& _window);

		Vector2 CalculateCohesion;
		Vector2 CalculateSegregation;
		Vector2 CalculateAllignment;

		Vector2 GetRandomPos();
		Vector2 GetRandomDirection();
};

