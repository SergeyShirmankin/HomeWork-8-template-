#pragma once
#include <iostream>

using namespace std;
template <class T>  class Array //ќбь¤вление класса шаблона
{
private:
	int m_length;  //ƒлина массива
	T * m_data; //”казатель на массив

public:
	Array() = default;
	Array(int length);
	int getLength();
	T& operator[](const int index);
	T&  operator=(const Array a);
	void insertBefore(int value, int index);
	// void show(T mess);
	// void show(Point mess);
	void remove(int index);
	void find(T value);
};

