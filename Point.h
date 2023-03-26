#pragma once
class Point {//  Для пользоватеского типа данных
public:
	Point() = default;
	Point(int x, int y);
	int getPoint(int index);
	void setPoint(int x1, int y1);
private:
	int x;//кордината x
	int y;//координата y
};