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
		node(const T& input,int&parent):value(input),left(-1),right(-1),parent(parent),depth(1){}
		void copy_except_value(node* from)
		{
			left = from->left;
			right = from->right;
			parent = from->parent;
			depth = from->depth;
		}
	};

	int root_ = -1;
	MemoryBlock<node<T>> memory_;

	size_t depth(int index);
	int get_balance(int index);
	void rotate_right(int index,int parent);
	void rotate_left(int index,int parent);
	int find_index(const T& value);
	int in_order_successor(int index);

public:
	node<T>* insert(const T& value);
	node<T>* find(const T& value);
	void remove(const T& value);
	node<T>* root_node();

	typedef typename MemoryBlock<node<T>>::iterator memoryIterator;
	memoryIterator begin_memory_iterator();
	memoryIterator end_memory_iterator();

};

template <typename T>
size_t AVL<T>::depth(int index)
{
	if (index == -1)
		return 0;
	return memory_[index]->depth;
}

template <typename T>
int AVL<T>::get_balance(int index)
{
	if (index == -1)
		return 0;
	return depth(memory_[index]->left) - depth(memory_[index]->right);
}

template <typename T>
void AVL<T>::rotate_right(int index, int parent)
{
	int left = memory_[index]->left;
	int leftRight = memory_[left]->right;

	memory_[left]->right = index;
	memory_[left]->parent = parent;
	memory_[index]->left = leftRight;
	memory_[index]->parent = left;

	if (leftRight != -1)
	{
		memory_[leftRight]->parent = index;
	}

	memory_[index]->depth = 1 + std::max(depth(memory_[index]->left), depth(memory_[index]->right));
	memory_[left]->depth = 1 + std::max(depth(memory_[left]->left), depth(memory_[left]->right));

	if (parent == -1)
	{
		root_ = left;
	}
	else
	{
		if (memory_[left]->value > memory_[parent]->value)
		{
			memory_[parent]->right = left;
		}
		else
		{
			memory_[parent]->left = left;
		}
	}
}

template <typename T>
void AVL<T>::rotate_left(int index, int parent)
{
	int right = memory_[index]->right;
	int rightLeft = memory_[right]->left;

	memory_[right]->left = index;
	memory_[right]->parent = parent;
	memory_[index]->right = rightLeft;
	memory_[index]->parent = right;

	if (rightLeft != -1)
	{
		memory_[rightLeft]->parent = index;
	}


	memory_[index]->depth = 1 + std::max(depth(memory_[index]->left), depth(memory_[index]->right));
	memory_[right]->depth = 1 + std::max(depth(memory_[right]->left), depth(memory_[right]->right));


	if (parent == -1)
	{
		root_ = right;
	}
	else
	{
		if (memory_[right]->value > memory_[parent]->value)
		{
			memory_[parent]->right = right;
		}
		else
		{
			memory_[parent]->left = right;
		}
	}
}

template <typename T>
int AVL<T>::find_index(const T& value)
{
	auto index = root_;
	while (index != -1)
	{
		if (value < memory_[index]->value)
			index = memory_[index]->left;
		else if (value > memory_[index]->value)
			index = memory_[index]->right;
		else return index;
	}
	return -1;
}

template <typename T>
int AVL<T>::in_order_successor(int index)
{
	int next = memory_[index]->right;
	if (next ==-1)
	{
		return -1;
	}

	while (memory_[next]->left != -1)
	{
		next = memory_[next]->left;
	}
	return next;
}

template <typename T>
typename AVL<T>::node<T>* AVL<T>::find(const T& value)
{
	auto temp = find_index(value);
	if (temp == -1)
	{
		return nullptr;
	}
	return memory_[temp];
}

template <typename T>
typename AVL<T>::node<T>* AVL<T>::insert(const T& value)
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
		else return nullptr;
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

		while (parentIndex!=-1)
		{
			currentIndex = parentIndex;
			parentIndex = memory_[parentIndex]->parent;

			memory_[currentIndex]->depth = 1 + std::max(depth(memory_[currentIndex]->left), depth(memory_[currentIndex]->right));

			//todo use smaller data
			const int balance = get_balance(currentIndex);

			if (balance > 1)
			{
				if (value < memory_[memory_[currentIndex]->left]->value)
				{
					// Left Left case
					rotate_left(currentIndex, parentIndex);
				}
				else 
				{
					// Left Right case
					rotate_left(memory_[currentIndex]->left, parentIndex);
					rotate_right(currentIndex, parentIndex);
				}
			}
			else
			if (balance < -1)
			{
				if(value > memory_[memory_[currentIndex]->right]->value)
				{
					// Right Right case
					rotate_left(currentIndex, parentIndex);
				}
				else
				{
					// Right Left case
					rotate_right(memory_[currentIndex]->right, parentIndex);
					rotate_left(currentIndex, parentIndex);
				}
			}
		}

	}
	return tmp;
}



template <typename T>
void AVL<T>::remove(const T& value)
{
	auto indexToDelete = find_index(value);
	if (indexToDelete == -1)
	{
		return;
	}
	node<T>* toDelete = memory_[indexToDelete];
	int parent = memory_[toDelete->parent];

	if (std::min(toDelete->right, toDelete->left)==-1)
	{
		//one or no child
		int child = memory_[indexToDelete]->left == -1 ? memory_[indexToDelete]->right : memory_[indexToDelete]->left;
		if (parent!=-1)
		{
			if (toDelete->value >  memory_[parent]->value)
			{
				memory_[parent]->right = child;
			}
			else
			{
				memory_[parent]->left = child;
			}
			if (child!=-1)
			{
				memory_[child]->parent = parent;
			}
		}
		else
		{
			root_ = child;
		}
	}
	else
	{
		//2 childrens
		int replaceIndex = in_order_successor(indexToDelete);
		memory_[memory_[replaceIndex]->parent]->left = memory_[replaceIndex]->right;
		if (memory_[replaceIndex]->right!=-1)
		{
			memory_[memory_[replaceIndex]->right]->parent = memory_[replaceIndex]->parent;
		}
		memory_[replaceIndex]->copy_except_value(toDelete);
		
		memory_[memory_[replaceIndex]->left]->parent = replaceIndex;
		memory_[memory_[replaceIndex]->right]->parent = replaceIndex;

		if (parent != -1)
		{
			if (toDelete->value >  memory_[parent]->value)
			{
				memory_[parent]->right = replaceIndex;
			}
			else
			{
				memory_[parent]->left = replaceIndex;
			}
		}
		else
		{
			root_ = replaceIndex;
		}
	}
	memory_.erase(indexToDelete);


}

template <typename T>
typename AVL<T>::node<T>* AVL<T>::root_node()
{
	return memory_[root_];
}

template <typename T>
typename AVL<T>::memoryIterator AVL<T>::begin_memory_iterator()
{
	return memory_.begin();
}

template <typename T>
typename AVL<T>::memoryIterator AVL<T>::end_memory_iterator()
{
	return memory_.end();
}

