#pragma once
#include <cassert>
#include <cstring>
#include <cstdlib>
#include <iostream>

template<typename T>
class tVector
{
	T * data;
	size_t capacity;
	size_t size;

public:

	T const operator[](unsigned idx) const;
	T& operator[](unsigned idx);
	tVector()
	{
		capacity = 2;
		data = new T[capacity];
		size = 0;
	}
	~tVector();

	T& at(size_t idx);

	T& append(T val);

	T* c_ptr() const;

	size_t getCapacity() const;

	size_t getSize() const;

	bool empty() const;

	T front() const;

	T back() const;

	void clear();

	void erase(int idx);

	void pop();

	T count(T value);

	void insert(T value, int idx);

	void reserve(int elements);

	void compact();

private:
	bool grow(size_t minSize);
};

template<typename T>
T const tVector<T>::operator[](unsigned idx) const
{
	return data[idx];
}

template<typename T>
T& tVector<T>::operator[](unsigned idx)
{
	return data[idx];
}

template<typename T>
tVector<T>::~tVector()
{
	delete[] data;
}

template<typename T>
T& tVector<T>::at(size_t idx)
{
	assert(idx >= 0);
	assert(idx < size);
	return data[idx];
}

template<typename T>
T& tVector<T>::append(T val)
{
	if (size == capacity)
	{
		bool didGrow = grow(size + 1);
		assert(didGrow);
	}
	data[size] = val;
	++size;

	return data[size - 1];
}

template<typename T>
T* tVector<T>::c_ptr() const
{
	return data;
}

template<typename T>
size_t tVector<T>::getCapacity() const
{
	return capacity;
}

template<typename T>
size_t tVector<T>::getSize() const
{
	return size;
}

template<typename T>
void tVector<T>::clear()
{
	capacity = 2;
	T* newData = new T[capacity];
	delete[] data;
	data = newData;
	size = 0;
}

template<typename T>
bool tVector<T>::empty() const
{
	return size == 0 ? true : false;
}

template<typename T>
T tVector<T>::front() const
{
	return data[0];
}

template<typename T>
T tVector<T>::back() const
{
	return data[size - 1];
}

template<typename T>
void tVector<T>::erase(int idx)
{
	T* temp = data;

	for (int i = 0; i < size; ++i)
	{
		if (i < idx)
			data[i] = temp[i];
		else
			data[i] = temp[i + 1];
	}

	size--;
}

template<typename T>
void tVector<T>::pop()
{
	erase(size - 1);
}

template<typename T>
T tVector<T>::count(T value)
{
	int counter = 0;

	for (int i = 0; i < size; ++i)
	{
		if (data[i] == value)
			counter++;
	}
	return counter;
}

template<typename T>
void tVector<T>::insert(T value, int idx)
{
	T* temp = new T[capacity];

	if (idx < 0)
		abort();

	else if (size + 1 > capacity)
		grow(size + 1);
	size++;
	//temp = new T[capacity];

	memcpy(temp, data, sizeof(T) * size);

	for (int i = 0; i < size; ++i)
	{
		if (i < idx)
			data[i] = temp[i];
		else if (i == idx)
			data[i] = value;
		else
			data[i] = temp[i - 1];
	}

	delete[] temp;
}

template<typename T>
void tVector<T>::reserve(int elements)
{
	if (elements >= capacity)
	{
		grow(elements + 1);
	}
}

template<typename T>
void tVector<T>::compact()
{
	T* newData = new T[size];
	for (int i = 0; i < size; ++i)
	{
		newData[i] = data[i];
	}
	capacity = size;
	delete[] data;
	data = newData;
}

template<typename T>
bool tVector<T>::grow(size_t minSize)
{
	assert(minSize <= 64000);
	if (minSize <= capacity)
	{
		return true;
	}
	while (capacity < minSize)
	{
		capacity *= 2;
	}


	T* newData = new T[capacity];
	memcpy(newData, data, sizeof(T) * size);

	delete[] data;
	data = newData;

	return true;
}