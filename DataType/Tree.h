#pragma once
#include <cassert>
#include <iostream>
#include <deque>
#include <climits>
#include <vector>

struct node
{
	int key_value;
	node *left;
	node*right;
};

class tree
{
public:
	tree();
	~tree();

	void insert(int key);
	node *search(int key);
	void destroy_tree();

private:
	void destroy_tree(node *leaf);
	void insert(int key, node *leaf);
	node *search(int key, node *leaf);

	node *root;
};
