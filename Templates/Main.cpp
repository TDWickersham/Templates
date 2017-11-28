#include <iostream>

int add(int a, int b)
{
	return a + b;
}

float add(float a, float b)
{
	return a + b;
}

template<typename T>

T add(T a, T b)
{
	return a + b;
}
template<typename T>
void Print(T arg)
{
	std::cout << arg << std::endl;
	
}

template<typename T>
int Min(T a, T b)
{
	if (a < b)
	{
		return a;
	}
	if (b < a)
	{
		return b;
	}
}

template<typename T>
T Max(T a, T b)
{
	if (a > b)
	{
		return a;
	}
	if (b > a)
	{
		return b;
	}
}

template<typename T>
T Clamp(T clamp, T top, T bottom)
{
	if (clamp < top && clamp > bottom)
	{
		return clamp;
	}
	if (clamp > top)
	{
		return top;
	}
	if (clamp < bottom)
	{
		return bottom;
	}
}

template<typename T, typename S>
void Person(T name, S age)
{
	std::cout << name << std::endl;
	std::cout << age << std::endl;
}



int main()
{
	int v1 = add(5, 2);

	Print<int>(2);
	Print<float>(1.2f);
	Print<bool>(true);
	Print<char const*>("Fart");

	std::cout << Min<int>(2, 3) << std::endl;
	std::cout << Min<int>(5, 4) << std::endl;

	std::cout << Max<int>(3, 2) << std::endl;
	std::cout << Max<int>(2, 3) << std::endl;

	std::cout << Clamp<int>(15, 20, 5) << std::endl;
	std::cout << Clamp<int>(21, 20, 5) << std::endl;
	std::cout << Clamp<int>(2, 20, 5) << std::endl;

	Person<char const*, int>("Caleb", 21);

	system("pause");
}