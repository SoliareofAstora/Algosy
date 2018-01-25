#pragma once
#include <string>


struct Node
{
	std::string key;
	struct Node *left;
	struct Node *right;
	int height;
};

class AVL
{
	
};