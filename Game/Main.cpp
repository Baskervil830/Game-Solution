// Main.cpp 


#include <SFML/Graphics.hpp>


int main()
{
	sf::RenderWindow window (sf::VideoMode(640, 640), "MainWindow");


	while (window.isOpen())
	{

		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) window.close();
		}



		window.clear();
		//window.draw();
		window.display();
	};

	

	return 0;
}