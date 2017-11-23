#include "stack.h"
#include <cstdint>

template class stack<uint8_t>;

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
	while (!empty())
	{
		pop();
	}
	delete last;
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
	length--;
	node* tempNode = last->prev;
	T temp = tempNode->value;
	last->prev = tempNode->prev;
	delete tempNode;
	return temp;
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


