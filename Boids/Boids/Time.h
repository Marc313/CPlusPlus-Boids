#pragma once
#include <SFML/System/Clock.hpp>

class Time
{
public:
	static float deltaTime;
	static const float calculateDeltaTime();

private:
	static sf::Clock clock;
};
