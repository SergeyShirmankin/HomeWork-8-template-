#include "Array.h"
#include "BadLength.h"
#include <iostream>
#include "Point.h"

template class Array <int>;
template class Array <double>;
//template class Array <Point>;

template <class T>
Array<T>::Array(int length) : m_length(length)//����������� �������
{
	try
	{
		m_data = new T[length]{}; // �������� ������������ ������� � ������� ��������� ������
	}
	catch (bad_alloc& ba)
	{
		cout << "bad_alloc caught!" << endl; //��� ������� �������� ������
		cout << ba.what() << endl;
	}
}

template<class T>
int Array<T>::getLength()
{
	return m_length;
}

template<class T>
T& Array<T>::operator[](const int index)
{
	if (index < 0 || index >= getLength())
		throw BadLength("Invalid index");//����������� ������
	return m_data[index];
}

template<class T>
T& Array<T>::operator=(const Array a)
{
	if (this->m_length != a.m_length)//�������� �������� ���� �������� ��� �����������
	{
		throw BadLength("Different length arrays");
	}
	else {
		for (int index = 0; index < m_length; ++index)//����� �������� ��������  
		{
			this->m_data[index] = a.m_data[index];
		}
		return  this->m_data[0];
	}
}

template<class T>
void Array<T>::insertBefore(int value, int index)
{
	// ��������� ������������ ������ �������� �������
	if (index >= 0 && index <= m_length)
	{
		T* data{ new T[m_length + 1] };// ������� ������� ����� ������ �� ���� ������� ������, ��� ������ ������
		for (int before{ 0 }; before < index; ++before)// �������� ��� �������� �� �������
			data[before] = m_data[before];
		data[index] = value;// ��������� ��� ����� ������� � ����� ������
		for (int after{ index }; after < m_length; ++after)// �������� ��� �������� ����� ������������ ��������
			data[after + 1] = m_data[after];
		delete[] m_data;// �������, ������� ������ ������ � ���������� ������ ���� ����� ������
		m_data = data;
		++m_length;
	}
}

template<class T>
void Array<T>::remove(int index)
{
	{
		if (index >= 0 && index <= m_length)
		{
			T* data{ new T[m_length - 1] };// ������� ������� ����� ������ �� ���� ������� ������, ��� ������ ������
										   // �������� ��� �������� �� �������
			for (int before{ 0 }; before < index; ++before)	// �������� ��� �������� �� �������
				data[before] = m_data[before];
			for (int after{ index + 1 }; after < m_length; ++after)// �������� ��� �������� ����� ���������� ��������
				data[after - 1] = m_data[after];
			// �������, ������� ������ ������ � ���������� ������ ���� ����� ������
			delete[] m_data;
			m_data = data;
			--m_length;
		}
		else
		{
			throw BadLength("Index not border");//���� �� ������ � �������� �� ��������� ������
		}
	}
}

template<class T>
void Array<T>::find(T value)
{
	for (int i = 0; i < m_length; ++i)
	{
		if (m_data[i] == value)
		{
			std::cout << "Finded  m_data[" << i << "] = " << m_data[i] << "  adress = " << &m_data[i] << endl;
		}
	}
}


