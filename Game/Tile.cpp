


#include "Tile.h"



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
	param.terrain = terr;
	param.tile_num = i;
	size.height = h;
	size.wigth = w;

	if (!l1_tileTexture.loadFromFile("Texture/" + terr + ".png")) return false;
	l1_tileSprite.setTexture(l1_tileTexture);
	//l1_tileSprite.setTextureRect(sf::IntRect(0, 0, w, h));
	//centre.x = (w * pos.x) / 2;
	//centre.y = (h * pos.y) / 2;
	l1_tileSprite.setPosition(pos.x * size.wigth, pos.y * size.height);
	return true;
}


bool Tile::setParam()
{

	return true;
}

bool Tile::setTerrain(std::string terr)
{
	if (!l1_tileTexture.loadFromFile("Texture/" + terr + ".png")) return false;
	l1_tileSprite.setTexture(l1_tileTexture);

	l1_tileSprite.setPosition(pos.x * size.wigth, pos.y * size.height);
	return true;
}

std::string Tile::getTerrain()
{
	return param.terrain;
}

sf::Vector2i Tile::getPosition()
{
	return pos;
}

const Tile::TileParam& Tile::getParam()
{
	return param;
}

void Tile::draw(sf::RenderWindow* win)
{
	win->draw(l1_tileSprite);
}

bool Tile::operator== (sf::Vector2f cor)
{
	float vertexX1 = pos.x * 100;
	float vertexX2 = (pos.x * 100) + (size.wigth - 0.001);

	float vertexY1 = pos.y * 100;
	float vertexY2 = (pos.y * 100) + (size.height - 0.001);

	return (((cor.x >= vertexX1) && (cor.x <= vertexX2)) && ((cor.y >= vertexY1) && (cor.y <= vertexY2)));
}

bool operator== (sf::Vector2f cor, Tile t)
{
	float vertexX1 = t.pos.x * 100;
	float vertexX2 = (t.pos.x * 100) + (t.size.wigth - 0.001);

	float vertexY1 = t.pos.y * 100;
	float vertexY2 = (t.pos.y * 100) + (t.size.height - 0.001);

	return (((cor.x >= vertexX1) && (cor.x <= vertexX2)) && ((cor.y >= vertexY1) && (cor.y <= vertexY2)));
}

