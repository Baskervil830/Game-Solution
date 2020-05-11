//Tile.h
//����� �������������� ������� ���� �� ������� ������� ����� �����


#ifndef TILE_H
#define TILE_H






#include <SFML/Graphics.hpp>
#include <string>

class Tile
{
	sf::Texture l1_tileTexture;
	sf::Sprite l1_tileSprite;

	sf::Vector2i pos;
	sf::Vector2i centre;

	struct Size
	{
		int wigth;
		int height;
	}size;


	struct TileParam
	{
		std::string terrain;

	}param;
	
	//������ ��������� �����
	bool setParam();

public:
	Tile();
	Tile(int i, int e, std::string = "Empty", int w = 100, int h = 100);

	bool create(int i, int e, std::string = "Empty", int w = 100, int h = 100);
	void clear();

	
	bool setTerrain(std::string terr);
	//������ ��� ���������

	//////////////////////////////////////////////////////
	//���������� ��� ��������� �����
	std::string getTerrain();
	//���������� ������� �����
	sf::Vector2i getPosition();

	//���������� ��������� �����
	const TileParam* getParam();

	void draw(sf::RenderWindow* window);



};

#endif // TILE_H