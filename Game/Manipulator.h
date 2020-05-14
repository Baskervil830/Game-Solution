// Manipulator.h - содержит классы для обработки ввода

#ifndef MANIPULATR_H
#define MANIPULATR_H

#include <SFML/Graphics.hpp>



class Frame
{
	sf::RectangleShape rectShape;
	bool ButtonPresed = false;
	struct corRect {
		int top, left, width, height;
	} rect;
	sf::Vector2f size;

	void setSize() { size.x = rect.width - rect.left; size.y = rect.height - rect.top; };
public:
	Frame() {};
	Frame(sf::Vector2f cor) { rect.top = cor.x; rect.left = cor.y; }

	void setStartPos(sf::Vector2i cor) { rect.left = cor.x; rect.top = cor.y; }
	void setEndPos(sf::Vector2i cor) { rect.width = cor.x; rect.height = cor.y; setSize(); }
	sf::Vector2f getSize() { return size; };

	const corRect& getFrame() { return rect; }
	static void createFrame(sf::RenderWindow& win);

};



#endif // !MANIPULATR_H
