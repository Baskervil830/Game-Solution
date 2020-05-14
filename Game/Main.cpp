// Main.cpp 


#include <SFML/Graphics.hpp>
#include "Map.h"
#include <iostream>
#include "Manipulator.h"



int main()
{
	sf::RenderWindow window(sf::VideoMode(1000, 500), "MainWindow");

	Map map(10, 5);
	Tile t;
	t = map.getTile(sf::Vector2i(1, 1));
	//sf::Vector2f vec(200, 120);
	//t == vec ? std::cout << "True" : std::cout << "False" << std::endl;

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
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				Frame::createFrame(window);
			}




			window.clear();
			map.draw(&window);
			//window.draw(rectShape);
			window.display();
		}
	};

	return 0;
}

//class Frame 
