#include <iostream>
#include <cassert>
#include "Tree.h"



int main()
{
	tree root;

	root.insert(3);

	assert(root.search(3) != NULL);

	root.destroy_tree;
	
	system("pause");

	root.insert(4);

	assert(root.search(4) != NULL);

	system("pause");
}
