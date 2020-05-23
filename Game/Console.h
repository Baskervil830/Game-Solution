


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


//
//
//void console(/*Map&  m*/)
//{
//
//
//
//	char temp[31];
//	string param[3];
//	int p = 0, ct = 0;
//
//	cin.getline(temp, 31);
//	while (p < 3)
//	{
//		if (temp[ct] == ' ') { ++p, ++ct; }
//		if ((temp[ct] == '\0') || p >= 3) break;
//		param[p] += temp[ct];
//		++ct;
//	}
//
//	int tp;
//	tp = atoi(param[1].c_str());
//	tp = atoi(param[0].c_str());
//
//
//	for (int i = 0; i < 3; ++i)
//		cout << param[i] << std::endl;
//}
