#pragma once

template<typename T>
class tVector
{
	T * data;
	size_t capacity;
	size_t size;

public:

	float operator[](unsigned idx) const
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

	size_t capacity() const;

	size_t size() const;

	bool empty() const;

	T front() const;

	T back() const;

	void clear();

	void erase(int idx);

	void pop();

	T count(int value);

	void insert(int value, int idx);

	void reserve(int elements);

	void compact();
};

template<typename T>
tVector::operator[](unsigned idx) const
{
	return data[idx];
}

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

template<typename T>
tVector::c_ptr() const
{
	return data;
}

template<typename T>
tVector::capacity() const
{
	return capacity;
}

template<typename T>
tVector::size() const
{
	return size;
}

template<typename T>
tVector::clear()
{
	capacity = 2;
	int* newData = new int[capacity];
	delete[] data;
	data = newData;
	size = 0;
}

template<typename T>
tVector::empty() const
{
	return size == 0 ? true : false;
}

template<typename T>
tVector::front() const
{
	return data[0];
}

template<typename T>
tVector::back() const
{
	return data[size - 1];
}

template<typname T>
tVector::erase(int idx)
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

template<typename T>
tVector::pop()
{
	erase(size - 1);
}

template<typename T>
tVector::count(int value)
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
tVector::insert(int value, int idx)
{
	int* temp;

	if (idx < 0)
		abort();

	else if (size + 1 > capacity)
		grow(size + 1);
	size++;
	temp = new int[capacity];

	memcpy(temp, data, sizeof(int) * size);

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
tVector::reserve(int elements)
{
	if (elements >= capacity)
	{
		grow(elements + 1);
	}
}

template<typename T>
tVector::compact()
{
	int* newData = new int[size];
	for (int i = 0; i < size; ++i)
	{
		newData[i] = data[i];
	}
	capacity = size;
	delete[] data;
	data = newData;
}