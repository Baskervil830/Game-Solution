
#include "Manipulator.h"
#include <iostream>

Border* Border::ptr_border = 0;
Border& brd = *Border::getBorder();

Border::Border()
{
	
	ver.left = ver.top = ver.width = ver.height = 0; 
	size.x = size.y = 0;
	rectShape.setSize(size); 

	Retention = false; 
}

void Border::setBorder(sf::RenderWindow& win)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if (!brd.Retention) brd.setStartPos(sf::Mouse::getPosition(win)); //������������� ��������� ������� �����
		brd.Retention = true; // ����������� ���

		brd.setEndPos(sf::Mouse::getPosition(win)); //��������� ��������� �������
		brd.rectShape.setSize(brd.getSize()); //������������� ������ ��������������
		brd.rectShape.setPosition(brd.getVertex().left, brd.getVertex().top); //������������� ������� �� ������
		brd.rectShape.setOutlineColor(sf::Color(255, 255, 255)); //����
		brd.rectShape.setOutlineThickness(1); // �������
		brd.rectShape.setFillColor(sf::Color(0, 0, 0, 0));// ������� ������� ��������������
		std::cout << "pos top: " << brd.getVertex().top << " pos left: " << brd.getVertex().left;                  // ���������� |
		std::cout << "pos width " << brd.getVertex().width << " pos heigh:" << brd.getVertex().height << std::endl;// ���������� |
	}
	else
	{
		brd.clearBorder();
		brd.Retention = false; // ��������� ������ ����
	}
};

void Border::clearBorder()
{
	brd.ver.left = brd.ver.top = brd.ver.width = brd.ver.height = 0;
}