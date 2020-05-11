


#include "Map.h"



Map::Map() {};

Map::Map(int w, int h)
{
	wigth = w;
	height = h;
	int size = w * h;
	tiles = new Tile[size];
	for (int i = 0; i < size; i++)
	{
		tiles[i].create(i, w);
	}
}

void Map::create(int w, int h)
{
	int size = w * h;
	tiles = new Tile[size];
	for (int i = 0; i < size; i++)
	{
		tiles[i].create(i, w);
	}
}

void Map::draw(sf::RenderWindow* win)
{
	int size = wigth * height;
	for (int i = 0; i < size; i++)
	{
		tiles[i].draw(win);
	}
}

Tile* Map::getTile(sf::Vector2i pos)
{
	int index = ((pos.x + 1) * (pos.y + 1));
	return &tiles[index];
}

void Map::clear()
{
	
}

Map::~Map()
{
	delete[] tiles;
	tiles = NULL;
}