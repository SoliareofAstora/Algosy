#include "stack.h"
#include <iostream>

template class stack<int>;
template class stack<char>;

template <typename T>
stack<T>::stack()
{
	last = new node;
	last->prev = last;
	length = 0;
}

template <typename T>
stack<T>::~stack()
{
}

template <typename T>
void stack<T>::push(T x)
{
	length++;
	node* temp = new node;
	temp->value = x;
	temp->prev = last->prev;
	last->prev = temp;
}

template <typename T>
T stack<T>::pop()
{
	if (length > 0)
	{
		length--;
		node* tempNode = last->prev;
		T temp = tempNode->value;
		last->prev = tempNode->prev;
		delete tempNode;
		return temp;
	}
	//std::cerr << "stack is empty pop()";
	std::out_of_range("stack pop()");
	return NULL;
}

template <typename T>
T& stack<T>::top()
{
	return last->prev->value;
}

template <typename T>
int stack<T>::size()
{
	return length;
}

template <typename T>
bool stack<T>::empty()
{
	return length == 0;
}


