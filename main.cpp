#include <iostream>
#include "Array.h"
#include "BadLength.h"
#include "Point.h"

int main()
{
	Array<int> arrayInt(10);//�������� ������� 
	Array<double> arrayDouble(20);
	//Array<Point> arrayPoint(15);
	Array<int> arrayCopy(10);//������ ��� ������������ �����
	Array <double> doublArrCopy(20);
	try {
		arrayInt[5] = 15;//������������ �������  ������
		int fInt = 15; // ����� ������ ��� ��������� �������
		arrayDouble[7] = 20.2;// ������������ �������  ������
		double fDouble = 20.2;// // ����� ������ ��� ��������� �������
							  //	arrayPoint[1].setPoint(5, 6);
		std::cout << " arrayInt[5] = " << arrayInt[5] << std::endl;//����� ������� �������;
		std::cout << " arrayDouble[7] = " << arrayDouble[7] << std::endl;//����� ������� �������;
																		 //	std::cout << " arrayPoint[1] = " << arrayPoint[1].getPoint(1)<<" " << arrayPoint[1].getPoint(2)<< std::endl;//����� ������� �������;

		for (int i = 0; i < 10; ++i) { std::cout << arrayCopy[i] << " "; }//��������� ������ ������
		std::cout << endl;
		arrayCopy = arrayInt;//����������� �������
		for (int i = 0; i < 10; ++i) { std::cout << arrayInt[i] << " "; }//�������� ����� ����������� ����� �����
		std::cout << endl;
		for (int i = 0; i < 10; ++i) { std::cout << arrayCopy[i] << " "; }//
		std::cout << endl;
		std::cout << endl;
		for (int i = 0; i < 10; ++i) { std::cout << doublArrCopy[i] << " "; }//��������  ������ ������ ������� �����
		std::cout << endl;
		doublArrCopy = arrayDouble;
		for (int i = 0; i < 10; ++i) { std::cout << arrayDouble[i] << " "; }//�������� ����� ����������� ������� �����
		std::cout << endl;
		for (int i = 0; i < 10; ++i) { std::cout << doublArrCopy[i] << " "; }//
		arrayInt.insertBefore(13, 6);//������� �������� �������
		std::cout << endl;
		for (int i = 0; i < 10; ++i) { std::cout << arrayInt[i] << " "; }//�������� ����� ����������� ����� �����
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
		arrayInt.find(15);//����� �������� �������
		arrayDouble.find(20.2);//����� �������� �������
		std::cout << endl;
	}
	catch (BadLength &exception) // ������� ����� ���������� ��������� ������ - ����������
	{
		std::cerr << "An array exception occurred (" << exception.what() << ")\n";
	}
	catch (std::exception &exception)
	{
		std::cerr << "Some other std::exception occurred (" << exception.what() << ")\n";
	}

	return 0;
}
