#include "Time.h"

float Time::deltaTime = 0.0f;
sf::Clock Time::clock = sf::Clock();

float Time::calculateDeltaTime()
{
	deltaTime = clock.restart().asSeconds();
	return deltaTime;
}

