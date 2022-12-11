#include "Time.h"

float Time::deltaTime = 0.0f;
sf::Clock Time::clock = sf::Clock();

const float Time::calculateDeltaTime()
{
	deltaTime = clock.restart().asSeconds();
	return deltaTime;
}

