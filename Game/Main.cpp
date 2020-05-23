// Main.cpp 


#include <SFML/Graphics.hpp>
#include "Map.h"
#include "Console.h"
#include <iostream>

extern Console& console;
//void console(/*Map&  m*/);

int main()
{
	sf::RenderWindow window(sf::VideoMode(500, 500), "MainWindow");

	Map map(5, 5);
	sf::Clock clock;


	while (window.isOpen())
	{

		sf::Event event;
		//
		//float time = clock.getElapsedTime().asMicroseconds();
		//clock.restart();
		//time /= 800;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) window.close();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tilde) || console.active) { console.start(map, window); break; };
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				//map.selectTile(sf::Mouse::getPosition(window));
				brd.setBorder(window);
			}
			else
			{
				map.selectGroupTile();
				brd.setBorder(window);
			}

		}


		window.clear();
		map.draw(window);
		//window.draw(rectShape);
		window.display();
	};

	return 0;
}