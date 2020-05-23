#include "Console.h"
#include "Map"


Console*  Console::ptr_console = 0;
Console& console = *Console::getConsole();




void Console::start(Map& map, RenderWindow& win)
{

	nm_param = -1;
	for (int i = 0; i < 2; ++i)
	{
		str_param[i].clear();
		i_param[i] = 0;
	}

	if (!active)
	{
		system("cls");
		active = true;
		cout << "Console active" << std::endl;
	}
	cin >> command;

	char temp[50];
	cin.getline(temp, 50);
	int ct = 0;
	while (nm_param < 2)
	{
		if (temp[ct] == ' ') { ++nm_param, ++ct; }
		if ((temp[ct] == '\0') || nm_param >= 2) { ++nm_param;  break; }
		str_param[nm_param] += temp[ct];
		++ct;
	}
	i_param[0] = atoi(str_param[0].c_str());
	i_param[1] = atoi(str_param[1].c_str());
	cout << command << " " << str_param[0] << " " << str_param[1] << std::endl	// Отладочная 
		<< "\t" << i_param[0] << " " << i_param[1] << std::endl;				// информация

	run(map, win);
}

void Console::run(Map& m, RenderWindow& win) 
{

	if (command == string("set_texture")) m.setTexture(str_param[0]);
	if (command == string("set_resolution")) win.create(sf::VideoMode(i_param[0], i_param[1]), "MainWindow");
	if (command == string("create_map")) {; m.create(i_param[0], i_param[1]); }

	if (command == string("exit")) { cout << "Console deactive\n"; active = false; }
	if (command == string("close")) win.close();

};

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