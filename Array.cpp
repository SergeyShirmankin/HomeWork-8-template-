#include "Array.h"
#include "BadLength.h"
#include <iostream>
#include "Point.h"

template class Array <int>;
template class Array <double>;
//template class Array <Point>;

template <class T>
Array<T>::Array(int length) : m_length(length)//конструктор массива
{
	try
	{
		m_data = new T[length]{}; // проверка правильности индекса и размера выделения памяти
	}
	catch (bad_alloc& ba)
	{
		cout << "bad_alloc caught!" << endl; //при неудаче выдавать ошибку
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
		throw BadLength("Invalid index");//выбрасывают аварию
	return m_data[index];
}

template<class T>
T& Array<T>::operator=(const Array a)
{
	if (this->m_length != a.m_length)//проверка разности длин массивов для копирования
	{
		throw BadLength("Different length arrays");
	}
	else {
		for (int index = 0; index < m_length; ++index)//Затем копируем элементы  
		{
			this->m_data[index] = a.m_data[index];
		}
		return  this->m_data[0];
	}
}

template<class T>
void Array<T>::insertBefore(int value, int index)
{
	// Проверяем правильность нашего значения индекса
	if (index >= 0 && index <= m_length)
	{
		T* data{ new T[m_length + 1] };// Сначала создаем новый массив на один элемент больше, чем старый массив
		for (int before{ 0 }; before < index; ++before)// Копируем все элементы до индекса
			data[before] = m_data[before];
		data[index] = value;// Вставляем наш новый элемент в новый массив
		for (int after{ index }; after < m_length; ++after)// Копируем все значения после вставленного элемента
			data[after + 1] = m_data[after];
		delete[] m_data;// Наконец, удаляем старый массив и используем вместо него новый массив
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
			T* data{ new T[m_length - 1] };// Сначала создаем новый массив на один элемент меньше, чем старый массив
										   // Копируем все элементы до индекса
			for (int before{ 0 }; before < index; ++before)	// Копируем все элементы до индекса
				data[before] = m_data[before];
			for (int after{ index + 1 }; after < m_length; ++after)// Копируем все значения после удаленного элемента
				data[after - 1] = m_data[after];
			// Наконец, удаляем старый массив и используем вместо него новый массив
			delete[] m_data;
			m_data = data;
			--m_length;
		}
		else
		{
			throw BadLength("Index not border");//если не входим в диапазон то запускаем аварию
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


