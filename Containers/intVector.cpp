#include "IntVector.h"
#include <cassert>
#include <cstring>

float intVector::operator[](unsigned idx) const
{
	return data[idx];
}

intVector::intVector()
{
	capacity = 2;
	data = new int[capacity];
	size = 0;
}

intVector::~intVector()
{
	delete[] data;
}

int& intVector::at(size_t idx)
{
	assert(idx >= 0);
	assert(idx < size);
	return data[idx];

}

int& intVector::append(int val)
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

int * intVector::raw() const
{
	return data;
}

size_t intVector::getCapacity() const
{
	return capacity;
}

size_t intVector::getSize() const
{
	return size;
}

bool intVector::empty() const
{
	return size == 0 ? true : false;
}

int intVector::front() const
{
	return data[0];
}

int intVector::back() const
{
	return data[size - 1];
}

void intVector::clear()
{
	capacity = 2;
	int* newData = new int[capacity];
	delete[] data;
	data = newData;
	size = 0;
}

void intVector::erase(int idx)
{
	int* temp = data;

	for (int i = 0; i < size; ++i)
	{
		if (i < idx)
			data[i] = temp[i];
		else
			data[i] = temp[i + 1];
	}

	size--;
}

int intVector::count(int value)
{
	int counter = 0;

	for (int i = 0; i < size; ++i)
	{
		if (data[i] == value)
			counter++;
	}
	return counter;
}

bool intVector::grow(size_t minSize)
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


	int* newData = new int[capacity];
	memcpy(newData, data,sizeof(int) * size);

	delete[] data;
	data = newData;

	return true;
}
