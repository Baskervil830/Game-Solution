// Map.h
//Класс представляет игровую карту

#pragma once
//
#ifndef MAP_H
#define MAP_H


#include "Tile.h"
#include <string>
#include <iostream>
#include "Manipulator.h"

extern Border& brd, * ptr_border;

using namespace sf;


enum Error;

class Map
{
	Tile *tiles_mesh, *sel_tile = nullptr;
	int sel_element;
	int wigth, height;

	void eventError();

	//Возвращает тайл по переданным координатам сетки
	Tile& getTile(Vector2i pos);
	Map(Map&) {};
	Map& operator= (Map&) {};

public:
	Map();
	Map(int w, int h, std::string ter = "Empty");
	void create(int w, int h, std::string ter = "Empty");

	// Отрисовка всех эелементов карты
	void draw(RenderWindow* win);
	//Очистка карты
	void clear();




	//Выделение тайла(-ов) по координатам курсора
	void selectTile (Vector2i cor);
	void selectGroupTile();


	void setTexture(std::string); 

	//Управление выделяющей рамкой
	void createBorder(sf::RenderWindow& win);
	//void deleteBorder();
	~Map();
};


#endif // MAP_H


