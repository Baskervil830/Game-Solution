


#include "Map.h"



Map::Map() { }

Map::Map(int w, int h, std::string ter)
{
	wigth = w;
	height = h;
	int size = w * h;
	tiles_mesh = new Tile[size];
	for (int i = 0; i < size; i++)
	{
		tiles_mesh[i].create(i, w, ter);
	}
}

void Map::create(int w, int h, std::string ter)
{
	//if (size != 0) delete tiles_mesh;
	wigth = w;
	height = h;
	size = w * h;
	tiles_mesh = new Tile[size];
	for (int i = 0; i < size; i++)
	{
		tiles_mesh[i].create(i, w, ter);
	}
}

void Map::clear()
{
	delete[] tiles_mesh;
	tiles_mesh = NULL;
}



////////////////////////////////////////////////////////////////
  Tile& Map::getTile(Vector2i cor)
{
	int index = (cor.y * wigth + cor.x);
	//std::cout << "returne tile " << tiles_mesh[index].getParam().tile_num << std::endl; //Отладочная информация
	return tiles_mesh[index];
}


void Map::selectTile(Vector2i pos_cur)
{
	if (sel_tile != nullptr)
	{
		if (sel_element > 1) { delete[] sel_tile; sel_tile = nullptr; sel_element = 0; }
		else if (sel_element == 1) { delete sel_tile; sel_tile = nullptr; sel_element = 0; }
	}
	//std::cout << "get cor x: " << pos_cur.x << " get cor y: " << pos_cur.y << std::endl; //Отладочная информация
	Vector2i pos_mesh(pos_cur.x / 100, pos_cur.y / 100); // Координаты окна переводим в координаты сетки
	//std::cout << "pos_mesh x: " << pos_mesh.x << " pos_mesh y: " << pos_mesh.y << std::endl; //Отладочная информация

	int index = (pos_mesh.y * wigth + pos_mesh.x); // Получаем индекс запрашиваемой ячейки
	std::cout << "index: " << index << std::endl; // Отладочная информация
	Tile* temp = new Tile;
	temp = &tiles_mesh[index];
	sel_tile = &temp;
	sel_element = 1;
//	std::cout << "returne tile " << sel_tile->getParam().tile_num << std::endl << "--------------------\n"; //Отладочная информация

}

void Map::selectGroupTile()
{
	if (brd.isRetention()) 
	{
		if (brd.getVertex().left > brd.getVertex().width) brd.reverse();

		int left, top, right, lower; // Позиции граней рамки
		left = static_cast<int> (brd.getVertex().left) / 100;
		top = static_cast<int> (brd.getVertex().top) / 100;
		right = static_cast<int> (brd.getVertex().width) / 100;
		lower = static_cast<int> (brd.getVertex().height) / 100;
		Vector2i tiles_cor[] // Определяем координаты тайлов с вершинами рамки
		{
			Vector2i(left, top), // 0 - левый верхний
			Vector2i(right, top), // 1 - правый верхний
			Vector2i(left, lower), // 2 - левый нижний
			Vector2i(right, lower)  // 3 - правый нижний
		};
		// Выравниваем грани рамки по тайлам, которые будут выделены
		if (brd.getVertex().left > getTile(tiles_cor[0]).getCenterPos().x) ++left;
		if (brd.getVertex().width < getTile(tiles_cor[1]).getCenterPos().x) --right;
		if (brd.getVertex().top > getTile(tiles_cor[0]).getCenterPos().y) ++top;
		if (brd.getVertex().height < getTile(tiles_cor[2]).getCenterPos().y) --lower;


		// Сбрасываем прошлое выделение
		if (sel_tile != nullptr)
		{
			if (sel_element > 1) { delete[] sel_tile; sel_tile = nullptr; sel_element = 0; }
			else if (sel_element == 1) { delete sel_tile; sel_tile = nullptr; sel_element = 0; }
			else std::cout << "select " << sel_element << " element\n";
		}

		// Выделение выбранных тайлов
		sel_element = ((lower + 1 ) - top) * ((right + 1 )- left);
		int ct = 0;

		sel_tile = new Tile*[sel_element];
		for (int l = top; l <= lower; ++l) // Проходим строку
			for (int c = left; c <= right; ++c) // Проходим столбец
			{
				int index = (l * wigth) + c;
				sel_tile[ct] = &tiles_mesh[index];
				++ct;
			}

		//sel_tile = temp; // Помечаем выделенными
		//temp = nullptr;

		//Отладочная информация
		//system("cls");
		//std::cout << "Total tiles: " << sel_element << "\n Selected tiles:\n";
		//for (int i = 0; i < sel_element; ++i)
		//{
		//	std::cout << "Element " << i << " :" << sel_tile[i]->getParam().tile_num << std::endl; // Выод индекса выделенного тайла

		//}
	}
}



////////////////////////////////////////////////////////////////
void Map::setTexture(std::string ter)
{
	for (int i = 0; i < sel_element; ++i)
		sel_tile[i]->setTerrain(ter);
}



////////////////////////////////////////////////////////////////
void Map::createBorder(sf::RenderWindow& win)
{
	brd.setBorder(win);
}





////////////////////////////////////////////////////////////////
void Map::draw(sf::RenderWindow& win)
{
	int size = wigth * height;
	for (int i = 0; i < size; i++)
	{
		tiles_mesh[i].draw(win);
	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) win.draw(brd.winBorder);
}



Map::~Map()
{
	delete[] tiles_mesh;
	tiles_mesh = NULL;
}