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
	};

	int root_ = -1;
	MemoryBlock<node<T>> memory_;

	size_t depth(int index);
	int get_balance(int index);
	void rotate_right(int index,int parent);
	void rotate_left(int index,int parent);
	int find_index(const T& value);
	int in_order_successor(int index);
	int min_node(int index);

public:
	node<T>* insert(const T& value);
	node<T>* find(const T& value);
	void remove(const T& value);
	node<T>* root_node();

	class iterator
	{
		AVL<T>* tree_;
		int current_;
	public:
		iterator();
		iterator(AVL<T>* tree, int node);
		bool operator ==(const iterator& i);;
		bool operator !=(const iterator& i);
		iterator& operator++();
		iterator operator ++(int);
		T& operator*();
	};
	iterator begin();
	iterator end();

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
	if (next !=-1)
	{
		return min_node(next);
	}
	int tmp = next;
	next = memory_[index]->parent;

	if (memory_[next]->right == index)
	{
		do
		{
			if (memory_[next]->right == tmp && next == root_)
			{
				return -1;
			}
			tmp = next;
			next = memory_[next]->parent;

		}
		while (memory_[next]->left!=tmp);
	}
	return next;
}

template <typename T>
int AVL<T>::min_node(int index)
{
	int current = index;
	if (current != -1)
	{
		while (memory_[current]->left!=-1)
		{
			current = memory_[current]->left;
		}
		return current;
	}
	return -1;
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
		memory_[currentIndex]->parent = -1;
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

			const int balance = get_balance(currentIndex);

			if (balance > 1)
			{
				if (value < memory_[memory_[currentIndex]->left]->value)
				{
					// Left Left case
					rotate_right(currentIndex, parentIndex);
				}
				else 
				{
					// Left Right case
					rotate_left(memory_[currentIndex]->left, currentIndex);
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
					rotate_right(memory_[currentIndex]->right, currentIndex);
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
	int parent = toDelete->parent;

	if (toDelete->right == -1 || toDelete->left==-1)
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
			if (child!=-1)
			{
				memory_[child]->parent = -1;
			}
			
		}
	}
	else
	{
		//2 childrens
		int replaceIndex = in_order_successor(indexToDelete);

		if (replaceIndex!=toDelete->right)
		{
			memory_[memory_[replaceIndex]->parent]->left = memory_[replaceIndex]->right;
			memory_[toDelete->right]->parent = replaceIndex;
			memory_[replaceIndex]->right = toDelete->right;
		}

		if (memory_[replaceIndex]->right!=-1)
		{
			memory_[memory_[replaceIndex]->right]->parent = memory_[replaceIndex]->parent;
		}
		
		memory_[replaceIndex]->depth = toDelete->depth;
		memory_[replaceIndex]->parent = toDelete->parent;
		memory_[replaceIndex]->left = toDelete->left;
		memory_[toDelete->left]->parent = replaceIndex;
		if (toDelete->parent != -1)
		{
			if (memory_[toDelete->parent]->value > toDelete->value)
			{
				memory_[toDelete->parent]->left = replaceIndex;
			}
			else
			{
				memory_[toDelete->parent]->right = replaceIndex;
			}
		}
		else
		{
			root_ = replaceIndex;
		}




	}
	/*
	 //TODO fix never ending loop
	while (parent != -1)
	{
		memory_[parent]->depth = 1 + std::max(depth(memory_[parent]->left), depth(memory_[parent]->right));
		//todo use smaller data
		const int balance = get_balance(parent);
		if (balance > 1)
		{
			if (get_balance(memory_[parent]->left) >= 0)
			{
				// Left Left case
				rotate_right(parent, memory_[parent]->parent);
			}
			else
			{
				// Left Right case
				rotate_left(memory_[parent]->left, parent);
				rotate_right(parent, memory_[parent]->parent);
			}
		}
		else
		if (balance < -1)
		{
			if (get_balance(memory_[parent]->right) <= 0)
			{
				// Right Right case
				rotate_left(parent, memory_[parent]->parent);
			}
			else
			{
				// Right Left case
				rotate_right(memory_[parent]->right, parent);
				rotate_left(parent, memory_[parent]->parent);
			}
		}
		
	}
	*/
	memory_.erase(indexToDelete);

}

template <typename T>
typename AVL<T>::node<T>* AVL<T>::root_node()
{
	return memory_[root_];
}

template <typename T>
AVL<T>::iterator::iterator()
{
	current_ = tree_->min_node();
}

template <typename T>
AVL<T>::iterator::iterator(AVL<T>* tree, int node):tree_(tree),current_(node)
{
}

template <typename T>
bool AVL<T>::iterator::operator==(const iterator& i)
{
	return tree_ == i.tree_ && current_ == i.current_;
}

template <typename T>
bool AVL<T>::iterator::operator!=(const iterator& i)
{
	return tree_ != i.tree_ || current_ != i.current_;
}

template <typename T>
typename AVL<T>::iterator& AVL<T>::iterator::operator++()
{
	current_ = tree_->in_order_successor(current_);
	return *this;
}

template <typename T>
typename AVL<T>::iterator AVL<T>::iterator::operator++(int)
{
	iterator temp = iterator(tree_, current_);
	current_ = tree_.in_order_successor(current_);
	return temp;
}

template <typename T>
T& AVL<T>::iterator::operator*()
{
	return tree_->memory_[current_]->value;
}

template <typename T>
typename AVL<T>::iterator AVL<T>::begin()
{
	return iterator(this, min_node(root_));
}

template <typename T>
typename AVL<T>::iterator AVL<T>::end()
{
	return iterator(this, -1);
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


