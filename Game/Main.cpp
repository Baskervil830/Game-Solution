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

//void console(/*Map&  m*/)
//{


	//using std::cout;
	//using std::cin;
	//using std::string;


	//char temp[31];
	//string param[3];
	//int p = 0, ct = 0;

	//cin.getline(temp, 31);
	//while (p < 3)
	//{
	//	if (temp[ct] == ' ') { ++p, ++ct; }
	//	if ((temp[ct] == '\0') || p >= 3) break;
	//	param[p] += temp[ct];
	//	++ct;
	//}

	//int tp1, tp2;
	//	tp1 = atoi(param[1].c_str());
	//	tp2 = atoi(param[0].c_str());

	//for (int i = 0; i < 3; ++i)
	//	cout << param[i] << std::endl;

///////////////////////////////////////////////////////////////

	//std::string command;
	//std::string str_param[2];
	//int i_param[2];
	//int nm_param;
	//nm_param = 0;
	//for (int i = 0; i < 2; ++i)
	//{
	//	str_param[i].clear();
	//	i_param[i] = 0;
	//}


	//system("cls");
	//std::cout << "Console active" << std::endl;
	//std::cin >> command;
	//while (nm_param < 2)
	//{
	//	std::cin >> str_param[nm_param];
	//	i_param[nm_param] = atoi(str_param[nm_param].c_str());
	//	if (!str_param[nm_param].empty()) ++nm_param; else break;
	//}

	//std::cout << command << " " << str_param[0] << " " << str_param[1] << std::endl
	//	<< "\t" << i_param[0] << " " << i_param[1] << std::endl;
//}
