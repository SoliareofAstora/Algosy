#include "SingleList.h"
#include <iostream>

SingleList::SingleList()
{
	head = nullptr;
}

SingleList::~SingleList()
{
}

void SingleList::push_front(int value)
{
	node *temp = new node;
	temp->value = value;
	if (head)
	{
		temp->next = head;
	}
	else
	{
		temp->next = nullptr;
	}
	head = temp;
}

int SingleList::pop_front()
{
	if (head!=nullptr)
	{
		node *temp = head;
		head = head->next;
		delete temp;
	}
	std::cerr << "NOPE! pop_front Array is empty";
	return -1;
}

void SingleList::push_back(int value)
{
	node *temp = new node;
	temp->value = value;
	temp->next = nullptr;

	if (head==nullptr)
	{
		head = temp;
	}
	else 
	{
		node* current = head;
		while (current->next != nullptr)
		{
			current = current->next;
		}
		current->next = temp;
	}
}

int SingleList::pop_back()
{
	node *temp = new node;
	node *previous = new node;
	temp = head;
	while (temp->next != nullptr)
	{
		previous = temp;
		temp = temp->next;
	}
	previous->next = nullptr;
	int value = temp->value;
	delete temp;
	return value;
}

int* SingleList::find(int value)
{
	node* temp = head;
	while (temp != nullptr)
	{
		if (temp->value==value)
		{
			return &temp->value;
		}
		temp = temp->next;
	}
	return nullptr;
}

int SingleList::size() const
{
	int size = 0;
	node *current = head;
	while (current->next != nullptr)
	{
		size++;
		current = current->next;
	}
	return size;
}

void SingleList::display()
{
	node* temp = head;
	while (temp != nullptr)
	{
		std::cout << temp->value << std::endl;
		temp = temp->next;
	} 
}

int SingleList::getValue(int i)
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
	} while (temp!= nullptr);
	
	return -1;
}


