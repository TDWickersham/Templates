#pragma once

class intVector
{
	int * data;
	size_t capacity;
	size_t size;

public:
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



private:
	bool grow(size_t minSize);
};

