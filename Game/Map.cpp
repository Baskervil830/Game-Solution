


#include "Map.h"
#include <iostream>




Map::Map() { }

Map::Map(int w, int h)
{
	wigth = w;
	height = h;
	int size = w * h;
	tiles_mesh = new Tile[size];
	for (int i = 0; i < size; i++)
	{
		if (!tiles_mesh[i].create(i, w)) ;
	}
}

void Map::create(int w, int h)
{
	int size = w * h;
	tiles_mesh = new Tile[size];
	for (int i = 0; i < size; i++)
	{
		tiles_mesh[i].create(i, w);
	}
}

void Map::draw(sf::RenderWindow* win)
{
	int size = wigth * height;
	for (int i = 0; i < size; i++)
	{
		tiles_mesh[i].draw(win);
		//win.draw(frame);
	}
}

// Возможно стоит пределать под Vector2f. Т.к. по логике некому запрашивать тайл по координатам сетки.
Tile& Map::getTile(Vector2i pos)
{
	int index = (pos.y * wigth + pos.x);
	//std::cout << "returne tile " << tiles_mesh[index].getParam().tile_num << std::endl;
	return tiles_mesh[index];

}

void Map::clear()
{
	
}

Map::~Map()
{
	delete[] tiles_mesh;
	tiles_mesh = NULL;
}