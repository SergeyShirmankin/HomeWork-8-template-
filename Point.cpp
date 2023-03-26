#include "Point.h"
#include "BadLength.h"

Point::Point(int x, int y)
{
	this->x = x;
	this->y = y;
}

int Point::getPoint(int index)
{
	// �������� ������������ ������ ������� �������
	if (index >= 1 && index <= 2)
	{
		if (index == 1)
		{
			return x;
		}
		else {
			return y;
		}
	}
	else
	{
		throw BadLength("Index not border");//���� �� ������ � �������� �� ��������� ������
	}
}

void Point::setPoint(int x1, int y1)
{
	this->x = x1;
	this->y = y1;
}
