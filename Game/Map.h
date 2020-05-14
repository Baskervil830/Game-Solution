// Map.h
//Класс представляет игровую карту



#ifndef MAP_H
#define MAP_H


#include "Tile.h"
#include <map>
#include "Manipulator.h"
#include <string>
using namespace sf;


enum Error ;

class Map
{
	Tile* tiles_mesh;
	int wigth;
	int height;

	void eventError();

public:
	Map();
	Map(int w, int h);

	void create(int w, int h);
	void draw(RenderWindow* win);
	void clear();

	Tile& getTile(Vector2i pos);

	Tile& selectTile (Vector2f cor);
	Tile& selectGroupTile();


	~Map();
};


#endif // MAP_H


