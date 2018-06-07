#pragma once
#include <vector>
#include <bitset>


template<typename T>
class AVL
{
	template<typename T>
	struct node
	{
		T value;
		node* left;
		node* right;
		int depth;
	};

	static const int batchSize = 64;
	std::vector < std::pair<char *, std::bitset<batchSize>>> arr;






};