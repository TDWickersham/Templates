#pragma once

template<typename T>
class tVector
{
	T * data;
	size_t capacity;
	size_t size;

public:
	tVector()
	{
		capacity = 2;
		data = new T[capacity];
		size = 0;
	}
	~tVector();

	T& at(size_t idx);

	T& append(T val);
};

template<typename T>
tVector::~tVector()
{
	delete[] data;
}

template<typename T>
tVector::at(size_t idx)
{
	assert(idx >= 0);
	assert(idx < size);
	return data[idx];
}

template<typename T>
tVector::append(T val)
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