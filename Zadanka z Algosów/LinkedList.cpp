#include "LinkedList.h"
#include <codecvt>
#include <iostream>

LinkedList::LinkedList()
{
	head = new node;
	head->next = head->prev = head;
}

LinkedList::~LinkedList()
{
}

void LinkedList::push_front(int value)
{
	node *temp = new node;
	temp->value = value;
	temp->next = head->next;
	temp->prev = head;
	temp->next->prev = temp;
	temp->prev->next = temp;
}

int LinkedList::pop_front()
{
	node *temp = head->next;
	temp->prev->next = temp->next;
	temp->next->prev = temp->prev;
	int value = temp->value;
	delete temp;
	return value;
}

void LinkedList::push_back(int value)
{
	node *temp = new node;
	temp->value = value;
	temp->next = head;
	temp->prev = head->prev;
	temp->next->prev = temp;
	temp->prev->next = temp;
}

int LinkedList::pop_back() 
{
	node *temp = head->prev;
	temp->prev->next = temp->next;
	temp->next->prev = temp->prev;
	int value = temp->value;
	delete temp;
	return value;
}

int* LinkedList::find(int value)
{
	node* temp = head->next;
	while (temp != nullptr)
	{
		if (temp->value == value)
		{
			return &temp->value;
		}
		temp = temp->next;
		if (temp==head)
		{
			break;
		}
	}
	return nullptr;
}

int LinkedList::size() 
{
	int size = 0;
	node *current = head->next;
	while (current != head)
	{
		size++;
		current = current->next;
	} 
	return size;
}

void LinkedList::display()
{
	node *current = head->next;
	while (current != head)
	{
		std::cout << current->value << std::endl;	
		current = current->next;
	}
}

int LinkedList::getValue(int i)
{
	node *temp = head;
	int x = 0;
	do
	{
		if (x == i)
		{
			return temp->value;
		}
		temp = temp->next;
		x++;
	} while (temp != nullptr);

	return -1;
}



