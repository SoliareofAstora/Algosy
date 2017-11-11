#include "stack.h"
#include <iostream>


stack::stack()
{
	last = new node;
	last->prev = last;
	length = 0;
}


stack::~stack()
{
}

void stack::push(int x)
{
	length++;
	node* temp = new node;
	temp->value = x;
	temp->prev = last->prev;
	last->prev = temp;
}

int stack::pop()
{
	if (length!=0)
	{
		length--;
		node *tempNode = last->prev;
		int temp = tempNode->value;
		last->prev = tempNode->prev;
		delete tempNode;
		return temp;
	}
	std::cerr << "stack is empty pop()";
	return -1;
	
}

int& stack::top()
{
	return last->prev->value;
}

int stack::size()
{
	return length;
}

bool stack::empty()
{
	return length == 0;
}
