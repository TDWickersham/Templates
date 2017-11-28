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
T Min(T a, T b)
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

template<typename T>
void Swap(T a, T b)
{
	T c;
	c = b;
	b = a;
	a = c;
	std::cout << a << " , " << b << std::endl;
}

template<typename T, typename S>
void Person(T name, S age)
{
	std::cout << name << std::endl;
	std::cout << age << std::endl;
}

template<>
char Min(char a, char b)
{
	return a < b ? a : b;
}

template<>
char Max(char a, char b)
{
	return a > b ? a : b;
}

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

template<typename T>
bool AssertedNotEqual(T x, T y)
{
	if (x != y)
	{
		return true;
	}
		abort();
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

	Swap<int>(2, 3);
	
	char charA = 'a';
	char charB = 'b';

	std::cout << "Min char alphabetically: " << Min(charA, charB) << std::endl;

	char charY = 'y';
	char charZ = 'z';

	std::cout << "Max char alphabetically: " << Max(charY, charZ) << std::endl;

	if (AssertedBool<true>(true));

	//if (AssertedBool<false>(true));

	if (AssertedEqual<int>(5, 5));

	//if (AssertedEqual<float>(4.0f, 5.0f));

	if (AssertedNotEqual<int>(4, 5));
	//if (AssertedNotEqual<float>(5.0f, 5.0f));

	system("pause");
}