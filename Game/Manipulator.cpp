
#include "Manipulator.h"
#include <iostream>

void Frame::createFrame(sf::RenderWindow& win)
{
	Frame frame;
	if (!frame.ButtonPresed) frame.setStartPos(sf::Mouse::getPosition(win));
	frame.ButtonPresed = true;
	while (win.isOpen() && frame.ButtonPresed == true)
	{
		//float time = t;
		frame.setEndPos(sf::Mouse::getPosition(win));
		frame.rectShape.setSize(frame.getSize());
		frame.rectShape.setPosition(frame.getFrame().left, frame.getFrame().top);
		frame.rectShape.setOutlineColor(sf::Color(0, 0, 0));
		frame.rectShape.setOutlineThickness(1);
		frame.rectShape.setFillColor(sf::Color(0, 0, 0, 0));
		std::cout << "pos top: " << frame.getFrame().top << " pos left: " << frame.getFrame().left;
		std::cout << "pos width " << frame.getFrame().width << " pos heigh:" << frame.getFrame().height << std::endl;
		win.draw(frame.rectShape);
		win.display();
		if (!(sf::Mouse::isButtonPressed(sf::Mouse::Left)))  frame.ButtonPresed = false;;
	}
}