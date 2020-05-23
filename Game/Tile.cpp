


#include "Tile.h"
#include <iostream>>


Tile::Tile()
{

}

Tile::Tile(int i, int e, std::string terr , int w, int h)
{

}

bool Tile::create(int i, int e, std::string terr , int w , int h )
{
	pos.x = i % e;
	pos.y = i / e;
	centre.x = (w * pos.x) + 50;
	centre.y = (h * pos.y) + 50;

	param.terrain = terr;
	param.tile_num = i;
	size.height = h;
	size.wigth = w;

	if (!l1_tileTexture.loadFromFile("Texture/" + terr + ".png")) return false;
	l1_tileSprite.setTexture(l1_tileTexture);
	l1_tileSprite.setPosition(static_cast <float> (pos.x * size.wigth), static_cast <float> (pos.y * size.height));
	return true;
}


bool Tile::setParam()
{

	return true;
}

bool Tile::setTerrain(std::string terr)
{
	if (!l1_tileTexture.loadFromFile("Texture/" + terr + ".png")) { std::cout << "Erorr loading file" << std::endl; return false; }	
	l1_tileSprite.setTexture(l1_tileTexture);

	l1_tileSprite.setPosition(static_cast <float> (pos.x * size.wigth), static_cast <float> (pos.y * size.height));
	return true;
}



void Tile::draw(sf::RenderWindow& win)
{
	win.draw(l1_tileSprite);
}

bool Tile::operator== (sf::Vector2f cor)
{
	float vertexX1 = static_cast <float> (pos.x * 100);
	float vertexX2 = static_cast <float> ((pos.x * 100) + (size.wigth - 0.001));

	float vertexY1 = static_cast <float> (pos.y * 100);
	float vertexY2 = static_cast <float> ((pos.y * 100) + (size.height - 0.001));

	return (((cor.x >= vertexX1) && (cor.x <= vertexX2)) && ((cor.y >= vertexY1) && (cor.y <= vertexY2)));
}

bool operator== (sf::Vector2f cor, Tile t)
{
	float vertexX1 = static_cast <float> (t.pos.x * 100);
	float vertexX2 = static_cast <float> ((t.pos.x * 100) + (t.size.wigth - 0.001));

	float vertexY1 = static_cast <float> (t.pos.y * 100);
	float vertexY2 = static_cast <float> ((t.pos.y * 100) + (t.size.height - 0.001));

	return (((cor.x >= vertexX1) && (cor.x <= vertexX2)) && ((cor.y >= vertexY1) && (cor.y <= vertexY2)));
}

