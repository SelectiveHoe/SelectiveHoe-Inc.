#pragma once

#include <iostream>
using namespace std;
typedef unsigned int uint;

template <typename T>
class Vector
{
	T *_data;
	uint _size;
	void CopyHelper(const Vector & v);
public:
	Vector();
	Vector(uint size);
	Vector(const Vector & v); // конструктор копирования
	Vector& operator=(const Vector & v); // оператор =
	void Clear(); // очистка вектора
	~Vector() { Clear(); _size = 0; }
	// работа с размером вектора
	uint GetCount() const { return _size; }
	bool IsEmpty() const { return 0 == _size; }
	// доступ к элементам
	T & operator[](uint index);
	T operator[](uint index) const;
	// добавление и удаление элементов
	void Add(const T & item); // добавление элемента в конец
	void Insert(uint index, const T & item); // вставка в заданную позицию
	void Remove(uint index);

	template <typename T>
	friend ostream & operator<<(ostream & out, const Vector<T> &v);
};

template <typename T>
void Vector<T>::CopyHelper(const Vector<T> & v)
{
	_size = v._size;
	_data = new T[_size];
	for (uint i = 0; i < _size; i++)
	{
		_data[i] = v._data[i];
	}
}

template <typename T>
Vector<T>::Vector() : _data(nullptr), _size(0)
{
}

template <typename T>
Vector<T>::Vector(uint size)
{
	_size = size;
	_data = new T[_size];
	for (uint i = 0; i < _size; i++)
	{
		_data[i] = T();
	}
}

template <typename T>
Vector<T>::Vector(const Vector<T> & v)
{
	CopyHelper(v);
}

template <typename T>
Vector<T> & Vector<T>::operator=(const Vector<T> & v)
{
	if (this != &v)
	{
		Clear();
		CopyHelper(v);
	}
	return *this;
}

template <typename T>
void Vector<T>::Clear()
{
	delete[] _data;
	_data = nullptr;
}

template <typename T>
T & Vector<T>::operator[](uint index)
{
	if (index >= 0 && index < _size)
	{
		return _data[index];
	}
	else
	{
		cout << "ERROR: index " << index << " out of range 0.." << _size << endl;
		return _data[0];
	}
}

template <typename T>
T Vector<T>::operator[](uint index) const
{
	if (index >= 0 && index < _size)
	{
		return _data[index];
	}
	else
	{
		cout << "ERROR: index " << index << " out of range 0.." << _size << endl;
		return _data[0];
	}
}

template <typename T>
void Vector<T>::Add(const T & item)
{
	T *p = new T[_size + 1];
	uint i;
	for (i = 0; i < _size; i++)
	{
		p[i] = _data[i];
	}
	p[i] = item;
	Clear();
	_data = p;
	_size++;
}

template <typename T>
void Vector<T>::Insert(uint index, const T & item)
{
	T *p = new T[_size + 1];
	if (index >= _size)
	{
		index = _size;
	}

	uint i;
	for (i = 0; i < _size + 1; i++)
	{
		if (i < index)
		{
			p[i] = _data[i];
		}
		else if (i == index)
		{
			p[i] = item;
		}
		else
		{
			p[i] = _data[i - 1];
		}
	}

	Clear();
	_data = p;
	_size++;
}

template <typename T>
void Vector<T>::Remove(uint index)
{
	T *p = new T[_size - 1];
	if (index >= _size)
	{
		index = _size - 1;
	}
	for (uint i = 0; i < _size; i++)
	{
		if (i < index)
		{
			p[i] = _data[i];
		}
		else if (i > index)
		{
			p[i - 1] = _data[i];
		}
	}

	Clear();
	_data = p;
	_size--;
}

template <typename T>
ostream & operator<<(ostream & out, const Vector<T> & v)
{
	if (v.IsEmpty())
	{
		out << "<Vector is empty>";
	}
	else
	{
		for (uint i = 0; i < v.GetCount(); i++)
		{
			out << v._data[i] << " ";
		}
	}
	return out;
}
