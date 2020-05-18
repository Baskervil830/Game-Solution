// Manipulator.h - �������� ������ ��� ��������� �����

#ifndef MANIPULATOR_H
#define MANIPULATOR_H
#include <SFML/Graphics.hpp>


class Border
{
	static Border* ptr_border;
	Border();
	Border(Border&) {};
	Border& operator= (Border&) {};
	~Border() {};
	bool live = false;

	sf::RectangleShape rectShape {sf::Vector2f (0, 0)};
	bool Retention = false; //��� ������������?
	struct Vertex { float top, left, width, height; } ver; //������� �����
	sf::Vector2f size; // ������� ������ �����

	void setStartPos(sf::Vector2i cor) { ver.left = static_cast<float> (cor.x); ver.top = static_cast <float>(cor.y); }						// ��������� ������
	void setEndPos(sf::Vector2i cor) { ver.width = static_cast<float>  (cor.x); ver.height = static_cast<float>  (cor.y);	 setSize(); }	//		�����
	void setSize() { size.x = ver.width - ver.left; size.y = ver.height - ver.top; }; // ������� ������� �����
	static void clearBorder();
public:
	const sf::RectangleShape& winBorder = rectShape; //������ �� ������ �����

	static Border* getBorder()
	{
		if (!ptr_border)
		{
			ptr_border = new Border;
		}
		return ptr_border;
	}
	//Border(sf::Vector2f cor1, sf::Vector2f cor2) { ver.top = cor1.x; ver.left = cor1.y; ver.width = cor2.x; ver.height = cor2.y; setSize(); }
	//Border(sf::Vector2i cor1, sf::Vector2i cor2) { ver.top = static_cast<float> (cor1.x); ver.left = static_cast<float> (cor1.y); ver.width = static_cast<float> (cor2.x); ver.height = static_cast<float> (cor2.y); setSize(); }

	
	sf::Vector2f getSize() { return size; };

	Vertex getVertex() { return ver; }
	static void setBorder(sf::RenderWindow& win);
	bool isRetention() { return Retention; }

};




#endif // !MANIPULATOR_H
