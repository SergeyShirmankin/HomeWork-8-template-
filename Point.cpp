#include "Point.h"
#include "BadLength.h"

Point::Point(int x, int y)
{
	this->x = x;
	this->y = y;
}

int Point::getPoint(int index)
{
	// ѕровер¤ем правильность нашего значени¤ индекса
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
		throw BadLength("Index not border");//если не входим в диапазон то запускаем аварию
	}
}

void Point::setPoint(int x1, int y1)
{
	this->x = x1;
	this->y = y1;
}
