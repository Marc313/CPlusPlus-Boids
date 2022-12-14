#include <SFML/Graphics.hpp>
#include "BoidManager.h"
#include "Time.h"
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "Boids");
    BoidManager manager(20);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        Time::calculateDeltaTime();
        manager.OnUpdate(window);

        window.display();
    }

    return 0;
}

