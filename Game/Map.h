// Map.h
//����� ������������ ������� �����

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

	//���������� ���� �� ���������� ����������� �����
	Tile& getTile(Vector2i pos);
	Map(Map&) {};
	Map& operator= (Map&) {};

public:
	Map();
	Map(int w, int h, std::string ter = "Empty");
	void create(int w, int h, std::string ter = "Empty");

	// ��������� ���� ���������� �����
	void draw(RenderWindow* win);
	//������� �����
	void clear();




	//��������� �����(-��) �� ����������� �������
	void selectTile (Vector2i cor);
	void selectGroupTile();


	void setTexture(std::string); 

	//���������� ���������� ������
	void createBorder(sf::RenderWindow& win);
	//void deleteBorder();
	~Map();
};


#endif // MAP_H


