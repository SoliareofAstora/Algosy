#include "SortedLinkedList.h"
#include <codecvt>
#include <iostream>

SortedLinkedList::SortedLinkedList()
{
	head = new node;
	head->next = head->prev = head;
}

SortedLinkedList::~SortedLinkedList()
{
}

void SortedLinkedList::push(int value)
{
	node* next = head->next;
	{
		while (next != head && next->value < value)
		{
			next = next->next;
		}
		if (next == head)
		{
			push_back(value);
		}
		else {
			if (next->prev == head)
			{
				push_front(value);
			}
			else {
				node *temp = new node;
				temp->value = value;
				temp->next = next;
				temp->prev = next->prev;
				next->prev = temp;
				temp->prev->next = temp;
			}
		}
	}
}


void SortedLinkedList::push_front(int value)
{
	node *temp = new node;
	temp->value = value;
	temp->next = head->next;
	temp->prev = head;
	temp->next->prev = temp;
	temp->prev->next = temp;
}

int SortedLinkedList::pop  ()const
{
	node *temp = head->next;
	temp->prev->next = temp->next;
	temp->next->prev = temp->prev;
	int value = temp->value;
	delete temp;
	return value;
}

void SortedLinkedList::push_back(int value)
{
	node *temp = new node;
	temp->value = value;
	temp->next = head;
	temp->prev = head->prev;
	temp->next->prev = temp;
	temp->prev->next = temp;
}

int SortedLinkedList::pop_back() 
{
	node *temp = head->prev;
	temp->prev->next = temp->next;
	temp->next->prev = temp->prev;
	int value = temp->value;
	delete temp;
	return value;
}

int SortedLinkedList::find(int value)
{
	node* temp = head->next;
	int result = 0;
	while (true)
	{
		if (temp->value == value)
		{
			result++;
		}
		temp = temp->next;
		if (temp == head || temp->value > value)
		{
			break;
		}
	}
	return result;
}

int SortedLinkedList::size() const
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

void SortedLinkedList::print()
{
	node *current = head->next;
	while (current != head)
	{
		std::cout << current->value << std::endl;	
		current = current->next;
	}
}

int SortedLinkedList::getValue(int i)
{
	node *temp = head->next;
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

void SortedLinkedList::unique()
{
	node* next= head->next;
	while (next != head )
	{
		if (next->value==next->next->value)
		{
			next->next= next->next->next;
			next->next->next->prev = next;
		}
		else 
		{
			next = next->next;
		}
	}
}

int SortedLinkedList::erase(int i)
{
	node *temp = head->next;
	int x = 0;
	do
	{
		if (x == i)
		{
			int a = temp->value;
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
			return a;
		}
		temp = temp->next;
		x++;
	} while (temp != nullptr);
	return -1;
}

void SortedLinkedList::remove(int value)
{
	node* next = head->next;
	while (true)
	{
		if (next->value == value)
		{
			next->prev->next = next->next;
			next->next->prev = next->prev;
		}

		next = next->next;
		
		if (next == head || next->value > value)
		{
			break;
		}
	}
}

SortedLinkedList SortedLinkedList::merge(const SortedLinkedList& a, SortedLinkedList& b)
{
	SortedLinkedList output;
	int sizea = a.size();
	int sizeb = b.size();
	int tempa = a.pop();
	int tempb = b.pop();

	std::cerr <<"length of arrays " <<sizea << " + "<<sizeb<<" = ";
	while(true)
	{
		if (tempa>tempb)
		{
			
			if (sizeb>0)
			{
				output.push_back(tempb);
				sizeb--;
				tempb = b.pop();
			}
			else
			{
				tempb = INT_MAX;
			}
		}
		else
		{
			
			if(sizea>0)
			{
				output.push_back(tempa);
				sizea--;
				tempa = a.pop();
			}
			else
			{
				tempa = INT_MAX;
			}
		}
		if (sizea==0&&sizeb==0)
		{
			break;
		}
	}
	std::cerr << output.size()<<std::endl;
	return output;
}



