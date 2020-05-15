//Tile.h
// ����� �������������� ������� ���� �� ������� ������� �����
// ����� �������� � ����� ������ ���������.
// ������ Vector2i ������������ ������� � ����� ������
// ����� Vector2f ������������ ���������� ���� (� ��������)
//


#ifndef TILE_H
#define TILE_H



#include <SFML/Graphics.hpp>
#include <string>


using namespace sf;


class Tile
{
	Texture l1_tileTexture;
	Sprite l1_tileSprite;

	Vector2i pos, centre;

	struct Size
	{
		int wigth, height;
	}size;


	struct TileParam
	{
		std::string terrain;
		int tile_num;

	}param;
	
	//������ ��������� �����
	bool setParam();

public:
	// ����������� �� ���������
	Tile();


	// ����������� ��� �������, ����� �������
	Tile(int i, int e, std::string terr, int w, int h);

	/* ������� ������� ����
	- �������� i - ������ �������� � ������� ������
	- ������� � - ���������� ��������� � ����
	- �������� terr - �������� ����� � ����������� ���������. �� ������ ����� ���� /Texture � ������ .png
	- ��������� w, h - ������������� ������ � ������ ����������� ��������
	*/
	bool create(int i, int e, std::string terr = "Empty", int w = 100, int h = 100);
	void clear();

	//������ ��� ���������
	bool setTerrain(std::string terr);



	//���������� ��� ��������� �����
	std::string getTerrain();

	//���������� ������� ����� � ����� ������
	sf::Vector2i getPosition();

	//���������� ��������� �����
	const TileParam& getParam();

	void draw(sf::RenderWindow* window);

	// ���������� true, ���� ���������� ���������� ������������� ������� �����.
	bool operator== (Vector2f cor);
	friend bool operator== (Vector2f cor, Tile t);

};

#endif // TILE_H