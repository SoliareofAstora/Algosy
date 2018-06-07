#pragma once
#include <vector>
#include <bitset>
#include <iostream>


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
		node() {}
		node(const T& input):value(input),left(nullptr),right(nullptr),depth(0){}
	};

	static const int N = 64;
	std::vector<std::pair<char *, std::bitset<N>>> arr;

public:
	AVL();
	void insert(const T& value);

};

template <typename T>
AVL<T>::AVL()
{
}

template <typename T>
void AVL<T>::insert(const T& value)
{
	arr.push_back(
		std::pair<char *, std::bitset<N>>(
			new char[sizeof(node<T>)*N],
			std::bitset<N>())
	);
	int i = 0;
	auto* wtf = new (arr[0].first) node<T>(value);
	
	std::cout << wtf->value;
	
}
