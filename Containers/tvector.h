#pragma once

template<typename T>
class tVector
{
	T * data;
	size_t capacity;
	size_t size;

public:

	T  operator[](unsigned idx) const;
	
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

	T count(int value);

	void insert(int value, int idx);

	void reserve(int elements);

	void compact();
};

template<typename T>
tVector<T>::operator[](unsigned idx) const
{
	return data[idx];
}

template<typename T>
tVector<T>::~tVector()
{
	delete[] data;
}

template<typename T>
tVector<T>::at(size_t idx)
{
	assert(idx >= 0);
	assert(idx < size);
	return data[idx];
}

template<typename T>
tVector<T>::append(T val)
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
tVector<T>::c_ptr() const
{
	return data;
}

template<typename T>
tVector<T>::getCapacity() const
{
	return capacity;
}

template<typename T>
tVector<T>::getSize() const
{
	return size;
}

template<typename T>
tVector<T>::clear()
{
	capacity = 2;
	T* newData = new T[capacity];
	delete[] data;
	data = newData;
	size = 0;
}

template<typename T>
tVector<T>::empty() const
{
	return size == 0 ? true : false;
}

template<typename T>
tVector<T>::front() const
{
	return data[0];
}

template<typename T>
tVector<T>::back() const
{
	return data[size - 1];
}

template<typname T>
tVector<T>::erase(int idx)
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
tVector<T>::pop()
{
	erase(size - 1);
}

template<typename T>
tVector<T>::count(int value)
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
tVector<T>::insert(int value, int idx)
{
	T* temp = new T[capacity];

	if (idx < 0)
		abort();

	else if (size + 1 > capacity)
		grow(size + 1);
	size++;
	temp = new T[capacity];

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
tVector<T>::reserve(int elements)
{
	if (elements >= capacity)
	{
		grow(elements + 1);
	}
}

template<typename T>
tVector<T>::compact()
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