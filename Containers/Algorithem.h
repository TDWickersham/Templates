#pragma once

template<typename T, typename S>
static S addRange(int* start, int* end)
{

	S total = 0;
	T* iter = start;
	while (iter != end)
	{
		total += *iter;
		++iter;
	}

	return total;
}

template<typename T, typename S>
static S addRangeFinished(int* start, int* end)
{

	S total = 0;
	T* iter = start;
	while (iter != end)
	{
		total += *iter;
		++iter;
	}

	return total;

}

template<typename T>
static T addRangeComplex(T start, T end)
{
	
}