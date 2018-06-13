#pragma once
#include "MemoryBlock.h"

template<typename T>
class AVL
{
	template<typename T>
	struct node
	{
		T value;
		int left;
		int right;
		int parent;
		size_t depth;
		node(){};
		node(const T& input,int&parent):value(input),left(-1),right(-1),parent(parent),depth(0){}
	};

	int root_ = -1;
	MemoryBlock<node<T>> memory_;

	size_t depth(int index);
	size_t get_balance(int index);
	int rotate_right(int index);
	int rotate_left(int index);

public:
	void insert(const T& value);
	node<T>* find(const T& value);
	void remove(const T& value);
	node<T>* root_node();
};


template <typename T>
size_t AVL<T>::depth(int index)
{
	if (index == -1)
		return 0;
	return memory_[index]->depth;
}

template <typename T>
size_t AVL<T>::get_balance(int index)
{
	if (index == -1)
		return 0;
	return depth(memory_[index]->left) - depth(memory_[index]->right);

}

template <typename T>
int AVL<T>::rotate_right(int index)
{
	int left = memory_[index]->left;
	int leftRight = memory_[left]->right;

	memory_[left]->right = index;
	memory_[index]->left = leftRight;

	memory_[index]->depth = 1 + std::max(depth(memory_[index]->left), depth(memory_[index]->right));
	memory_[left] ->depth = 1 + std::max(depth(memory_[left]->left), depth(memory_[left]->right));
	
	return left;
}

template <typename T>
int AVL<T>::rotate_left(int index)
{
	int right = memory_[index]->right;
	int rightLeft = memory_[right]->left;

	memory_[right]->left = index;
	memory_[index]->right = rightLeft;

	memory_[index]->depth = 1 + std::max(depth(memory_[index]->left), depth(memory_[index]->right));
	memory_[right]->depth = 1 + std::max(depth(memory_[right]->left), depth(memory_[right]->right));

	return right;
}

template <typename T>
void AVL<T>::insert(const T& value)
{

	int parentIndex = -1;
	int currentIndex = root_;

	while (currentIndex != -1)
	{
		parentIndex = currentIndex;
		if (memory_[currentIndex]->value > value)
			currentIndex = memory_[currentIndex]->left;
		else if (memory_[currentIndex]->value < value)
			currentIndex = memory_[currentIndex]->right;
		else return;
	}

	const std::pair<char*, int> newAddress = memory_.allocate();
	currentIndex = newAddress.second;
	auto* tmp =new (newAddress.first)node<T>(value,parentIndex);

	if (parentIndex==-1)
	{
		root_ = currentIndex;
	}
	else
	{
		if (memory_[parentIndex]->value > value)
			memory_[parentIndex]->left = currentIndex;
		else 
			memory_[parentIndex]->right = currentIndex;

		while (parentIndex != -1)
		{
			currentIndex = parentIndex;
			parentIndex = memory_[parentIndex]->parent;

			memory_[currentIndex]->depth = 1 + std::max(depth(memory_[currentIndex]->left), depth(memory_[currentIndex]->right));

			size_t balance = get_balance(currentIndex);

			// Left Left case
			if (balance > 1 && value < memory_[memory_[currentIndex]->left]->value)
				 

			// Right Right case
			if (balance < -1 && value > memory_[memory_[currentIndex]->right]->value)

			// Left Right case
			if (balance > 1 && value > memory_[memory_[currentIndex]->left]->value)


			// Right Left case
			if (balance < -1 && value < memory_[memory_[currentIndex]->right]->value)
			{ }
			//return;

		}

	}
}

/*template <typename T>
int avl<T>::get_balance(node<T>* node)
{
	if (node == nullptr)
		return 0;
	return depth(node->left) - depth(node->right);
}

template <typename T>
int avl<T>::depth(node<T>* node)
{
	if (node == nullptr) return 0;
	return node->depth;
}*/

template <typename T>
typename AVL<T>::node<T>* AVL<T>::find(const T& value)
{
	
	int index = root_;
	while (index != -1)
	{
		if (value < memory_[index]->value)
			index = memory_[index]->left;
		else if (value > memory_[index]->value)
			index = memory_[index]->right;
		else return memory_[index];
	}
	return nullptr;
}

template <typename T>
void AVL<T>::remove(const T& value)
{

}

template <typename T>
typename AVL<T>::node<T>* AVL<T>::root_node()
{
	return memory_[root_];
}

