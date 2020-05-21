// Main.cpp 


#include <SFML/Graphics.hpp>
#include "Map.h"
#include <iostream>

void console(/*Map&*/);

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
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tilde)) console();
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

void console(/*Map&  m*/)
{
	using std::cout;
	using std::cin; 
	using std::string;


	char temp[31];
	string param[3];
	int p = 0, ct = 0;

	cin.getline (temp, 31);
	while (p < 3)
	{
		if (temp[ct] == ' ') { ++p, ++ct; }
		if ((temp[ct] == '\0') || p >= 3) break;
		param[p] += temp[ct];
		++ct;
	}
	for (int i = 0; i < 3; ++i)
		cout << param[i] << std::endl;
}

