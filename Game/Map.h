// Map.h
//Класс представляет игровую карту



#ifndef MAP_H
#define MAP_H


#include "Tile.h"


class Map
{
	Tile* tiles;
	int wigth;
	int height;

public:
	Map();
	Map(int w, int h);

	void create(int w, int h);
	void draw(sf::RenderWindow* win);
	void clear();

	Tile* getTile(sf::Vector2i pos);

	~Map();

};


#endif // MAP_H


