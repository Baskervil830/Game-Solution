


#ifndef CONSOLE_H
#define CONSOLE_H

#include <SFML/Graphics.hpp>
#include "Map.h"
#include <iostream>

using std::cout;
using std::cin;
using std::string;


class Console
{
	static Console* ptr_console;
	Console() {};
	Console(Console&) {};
	Console& operator= (Console& c) {};


	string command;
	string str_param[2];
	int i_param[2];
	int nm_param;

	enum Command {SET_TEXTURE = 0};


	void run(Map&, RenderWindow& win);
public:

	static Console* getConsole()
	{
		{
			if (!ptr_console)
				ptr_console = new Console;
			return ptr_console;
		}
	}

	void start(Map&, RenderWindow& win);

	bool active = false;
};






#endif // !CONSOLE_H
