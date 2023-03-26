#include <iostream>
#include "Array.h"
#include "BadLength.h"
#include "Point.h"

int main()
{
	Array<int> arrayInt(10);//создание массива 
	Array<double> arrayDouble(20);
	//Array<Point> arrayPoint(15);
	Array<int> arrayCopy(10);//массив для тестировании копии
	Array <double> doublArrCopy(20);
	try {
		arrayInt[5] = 15;//присваивание массиву  данные
		int fInt = 15; // Число поиска Для шаблонной функции
		arrayDouble[7] = 20.2;// присваивание массиву  данные
		double fDouble = 20.2;// // Число поиска Для шаблонной функции
							  //	arrayPoint[1].setPoint(5, 6);
		std::cout << " arrayInt[5] = " << arrayInt[5] << std::endl;//Вывод элемент массива;
		std::cout << " arrayDouble[7] = " << arrayDouble[7] << std::endl;//Вывод элемент массива;
																		 //	std::cout << " arrayPoint[1] = " << arrayPoint[1].getPoint(1)<<" " << arrayPoint[1].getPoint(2)<< std::endl;//Вывод элемент массива;

		for (int i = 0; i < 10; ++i) { std::cout << arrayCopy[i] << " "; }//Проверяем пустую строку
		std::cout << endl;
		arrayCopy = arrayInt;//копирование массива
		for (int i = 0; i < 10; ++i) { std::cout << arrayInt[i] << " "; }//Проверка после копирования целые числа
		std::cout << endl;
		for (int i = 0; i < 10; ++i) { std::cout << arrayCopy[i] << " "; }//
		std::cout << endl;
		std::cout << endl;
		for (int i = 0; i < 10; ++i) { std::cout << doublArrCopy[i] << " "; }//Проверка  пустую строку дробное число
		std::cout << endl;
		doublArrCopy = arrayDouble;
		for (int i = 0; i < 10; ++i) { std::cout << arrayDouble[i] << " "; }//Проверка после копирования дроюное число
		std::cout << endl;
		for (int i = 0; i < 10; ++i) { std::cout << doublArrCopy[i] << " "; }//
		arrayInt.insertBefore(13, 6);//вставка элемента массива
		std::cout << endl;
		for (int i = 0; i < 10; ++i) { std::cout << arrayInt[i] << " "; }//Проверка после копирования целые числа
		std::cout << endl;
		arrayDouble.insertBefore(17, 2);
		for (int i = 0; i < 10; ++i) { std::cout << arrayDouble[i] << " "; }
		std::cout << endl;

		arrayInt.remove(1);
		for (int i = 0; i < 10; ++i) { std::cout << arrayInt[i] << " "; }
		std::cout << endl;
		arrayDouble.remove(1);
		for (int i = 0; i < 10; ++i) { std::cout << arrayDouble[i] << " "; }
		std::cout << endl;
		arrayInt.find(15);//Поиск элемента массива
		arrayDouble.find(20.2);//Поиск элемента массива
		std::cout << endl;
	}
	catch (BadLength &exception) // сначала ловим исключения дочернего класса - исключения
	{
		std::cerr << "An array exception occurred (" << exception.what() << ")\n";
	}
	catch (std::exception &exception)
	{
		std::cerr << "Some other std::exception occurred (" << exception.what() << ")\n";
	}

	return 0;
}
