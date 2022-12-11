#pragma once
#include <SFML/Graphics.hpp>
#include "Vector2.h"

class Boid
{
	public:
		// Public Fields
		Vector2 position;
		Vector2 direction;

		float neighbourRange;
		float cScore;
		float sScore;
		float aScore;

		// Public Functions
		Boid();
		virtual ~Boid();
		Boid& operator=(const Boid& v);
		void OnUpdate(sf::RenderWindow& _window, std::vector<Boid>& _neighbourBoids);
		virtual Vector2 CalculateDirection(std::vector<Boid>& _neighbourBoids);

		Vector2 GetPosition() const;
		void SetPosition(const Vector2& _newPos);

		static Boid makeBoid();

	protected:
		static Vector2 AccumulateBoidPositions(const Vector2& _acc, const Boid& _boid);
		static Vector2 AccumulateBoidDirection(const Vector2& _acc, const Boid& _boid);

	private:	
		// Private fields
		float speed;
		sf::CircleShape shape;

		// Private Functions
		void InitializeDefaultVariables();
		void Move();
		void Draw(sf::RenderWindow& _window);

		Vector2 CalculateCohesion(std::vector<Boid>& _neighbourBoids);
		Vector2 CalculateSegregation(std::vector<Boid>& _neighbourBoids);
		Vector2 CalculateAllignment(std::vector<Boid>& _neighbourBoids);

		Vector2 const GetRandomPos() const;
		Vector2 const GetRandomDirection() const;
};

