#include "IntVector.h"
#include <iostream>

template<bool T>
bool AssertedBool(bool arg)
{
	if (arg == T)
	{
		return true;
	}
	abort();
}

template<typename T>
bool AssertedEqual(T x, T y)
{
	if (x == y)
	{
		return true;
	}
	abort();
}

int main()
{
	intVector nums;
	AssertedBool<true>(nums.empty());
	AssertedEqual<size_t>(nums.getCapacity(), 2);
	nums.append(1);
	nums.append(5);

	AssertedEqual(nums.at(0), 1);
	AssertedEqual(nums.at(1), 5);

	nums.append(33);

	AssertedEqual(nums.at(0), 1);
	AssertedEqual(nums.at(1), 5);
	AssertedEqual(nums.at(2), 33);
	AssertedEqual<size_t>(nums.getCapacity(), 4);
	AssertedEqual<size_t>(nums.getSize(), 3);
	AssertedEqual(nums.front(), 1);
	AssertedEqual(nums.back(), 33);
	AssertedEqual(nums.raw(), &nums.at(0));

	AssertedEqual<size_t>(nums[0], 1);
	
	
	

	return 0;
}