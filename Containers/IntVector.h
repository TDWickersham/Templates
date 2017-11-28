#pragma once

class intVector
{
	int * data;
	size_t capacity;
	size_t size;

public:
	float operator[](unsigned idx) const;

	intVector();
	~intVector();
	
	int& at(size_t idx);

	int& append(int val);

	int* raw() const;

	size_t getCapacity() const;

	size_t getSize() const;

	bool empty() const;

	int front() const;
	int back() const;

	void clear();
	void erase(int idx);

	int count(int value);
	void insert(int value, int idx);

	void reserve(int elements);

	void compact();

private:
	bool grow(size_t minSize);
};

