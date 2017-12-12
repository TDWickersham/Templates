#include <iostream>
#include <cassert>
#include "Tree.h"



int main()
{
	tree base;

	base.insert(3);

	assert(base.search(3) != NULL);

	base.destroy_tree();
	
	system("pause");

	base.insert(4);

	assert(base.search(4) != NULL);

	system("pause");

	base.insert(3);

	assert(base.search(3) != NULL);

	system("pause");

	base.insert(2);
	
	assert(base.search(4) != NULL);

	assert(base.search(3) != NULL);

	assert(base.search(2) != NULL);

	system("pause");
}
