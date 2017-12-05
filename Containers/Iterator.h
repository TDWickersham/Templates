#pragma once

template<typename T>
class iterator
{
public:
	iterator() = delete;

	iterator(T& container, int initalIndex)
		: owningContainer(&container)
		, currentIndex(intialIndex)
	{

	}

	iterator(const iterator<T>& other)
		: owningContainer(other.owningContainer)
		, currentIndex(other.currentIndex)
	{

	}
	iterator<T>& operator=(const iterator<T>& other)
	{
		owningContainer = other.owningContainer;
		currentIndex = other.currentIndex;
	}
	
	bool operator==(const iterator<T>& other)
	{
		bool isSameContainer = owningContainer == other.owningContainer;
		bool isSameIndex = currentIndex == other.currentIndex;

		return isSameContainer && isSameContainer;
	}
	bool operator!=(const iterator<T>& other)
	{
		bool isSameContainer = owningContainer == other.owningContainer;
		bool isSameIndex = currentIndex == other.currentIndex;

		return !isSameContainer || !isSameContainer;
	}

	auto& operator*() 
	{
		return owningContainer->at(currentIndex);
	}

	iterator<T>& operator++()
	{
		currentIndex++;
		return *this;
	}
	iterator<T>& operator++(int previousValue)
	{
		iterator<T> tmp(owningContainer, previousValue);
		operator++();
		return tmp;
	}


private:
	T* owningContainer;
	int currentIndex;
};