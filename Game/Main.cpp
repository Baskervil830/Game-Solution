// Main.cpp 


#include <SFML/Graphics.hpp>
#include "Map.h"
#include <iostream>


int main()
{
	sf::RenderWindow window(sf::VideoMode(500, 500), "MainWindow");

	Map map(5, 5);
	sf::Clock clock;
	//map.selectTile(Vector2i(50, 50));
	//map.selectTile(Vector2i(100, 50));
	//map.selectTile(Vector2i(50, 100));
	//map.selectTile(Vector2i(100, 100));

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
		map.draw(&window);
		//window.draw(rectShape);
		window.display();
	};

	return 0;
}

//class Frame 
