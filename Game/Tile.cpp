


#include "Tile.h"



Tile::Tile()
{

}

Tile::Tile(int i, int e, std::string terr , int w, int h)
{

}

bool Tile::create(int i, int e, std::string terr, int w, int h)
{
	pos.x = i % e;
	pos.y = i / e;
	param.terrain = terr;
	size.height = h;
	size.wigth = w;

	if (!l1_tileTexture.loadFromFile("Texture/" + terr + ".png")) return false;
	l1_tileSprite.setTexture(l1_tileTexture);

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

const Tile::TileParam* Tile::getParam()
{
	return &param;
}

void Tile::draw(sf::RenderWindow* win)
{
	win->draw(l1_tileSprite);
}