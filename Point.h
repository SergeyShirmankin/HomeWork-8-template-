#pragma once
class Point {//  ��� ��������������� ���� ������
public:
	Point() = default;
	Point(int x, int y);
	int getPoint(int index);
	void setPoint(int x1, int y1);
private:
	int x;//��������� x
	int y;//���������� y
};