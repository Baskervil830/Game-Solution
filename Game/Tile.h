//Tile.h
// Класс представляющий игровой тайл из которых состоит карта
// Класс работает с двумя типами координат.
// Вектор Vector2i представляет позицию в сетке тайлов
// Класс Vector2f представляет координаты окна (в пискелях)
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
	
	//Задает параметры тайла
	bool setParam();

public:
	// Конструктор по умолчанию
	Tile();


	// Конструктор для отладки, после удалить
	Tile(int i, int e, std::string terr, int w, int h);

	/* Создает базовый тайл
	- Параметр i - индекс элемента в массиве тайлов
	- Парметр е - количество элементов в ряду
	- Параметр terr - название файла с загружаемой текстурой. Он должен иметь путь /Texture и формат .png
	- Параметры w, h - соответствуют ширине и высоте загружаемой текстуры
	*/
	bool create(int i, int e, std::string terr = "Empty", int w = 100, int h = 100);
	void clear();

	//Задает тип местности
	bool setTerrain(std::string terr);



	//Возвращает тип местности тайла
	std::string getTerrain() { return param.terrain; }

	//Возвращает позицию тайла в сетке тайлов
	const sf::Vector2i getPosition() { return pos; }
	const sf::Vector2i getCenterPos() { return centre; }

	//Возвращает параметры тайла
	const TileParam& getParam() { return param; }

	void draw(sf::RenderWindow& window);

	// Возвращает true, если переданные координаты соответствуют позиции тайла.
	bool operator== (Vector2f cor);
	friend bool operator== (Vector2f cor, Tile t);

};

#endif // TILE_H