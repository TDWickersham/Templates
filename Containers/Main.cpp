#include "tvector.h"
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
	tVector<int>nums;
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
	AssertedEqual(nums.c_ptr(), &nums.at(0));

	AssertedEqual<size_t>(nums[0], 1);
	nums.clear();
	AssertedBool<true>(nums.getSize() == 0);
	AssertedBool<true>(nums.getCapacity() == 2);
	AssertedBool<true>(nums.empty());
	
	nums.append(22);
	nums.append(42);
	nums.append(22);

	AssertedEqual<size_t>(nums.getSize(), 3);
	AssertedEqual(nums.count(22), 2);

	nums.erase(0);
	AssertedEqual(nums.front(), 42);
	nums.insert(78, 2);
	AssertedEqual(nums.at(2), 78);
	nums.clear();
	nums.reserve(10);
	AssertedBool<true>(nums.getCapacity() >= 10);
	nums.append(56);
	nums.append(90);
	nums.append(34);
	nums.compact();
	AssertedEqual(nums.getCapacity(), nums.getSize());

	return 0;
}