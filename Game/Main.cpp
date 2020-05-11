// Main.cpp 


#include <SFML/Graphics.hpp>
#include "Map.h"


int main()
{
	sf::RenderWindow window (sf::VideoMode(1000, 500), "MainWindow");

	Map map(10, 5);

	while (window.isOpen())
	{

		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) window.close();
		}



		window.clear();
		map.draw(&window);
		//window.draw();
		window.display();
	};

	

	return 0;
}