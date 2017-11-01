#include "SingleList.h"
#include <iostream>

SingleList::SingleList()
{
}

SingleList::~SingleList()
{
}

void SingleList::push_front(int value)
{
	node *temp =new node();
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
/*
int SingleList::pop_front()
{
	if (length>0)
	{
		length--;
		int temp = tab[head].next;
		int value = tab[head].value;
		tab[head].next = -2;
		head = temp;
		return value;
	}
	std::cerr << "NOPE! pop_front Array is empty";
	return -1;
}

void SingleList::push_back(int value)
{
	if (length == 0)
	{
		tab[nextFree].value = value;
		tab[nextFree].next = -1;
		length++;
		UpdateNextFree();
	}
	else
	{

		if (sizeof tab / 8 > length + 1)
		{
			int next = head;
			while (tab[next].next != -1)
			{
				next = tab[next].next;
			}
			tab[next].next = nextFree;
			tab[nextFree].value = value;
			tab[nextFree].next = -1;
			length++;
			UpdateNextFree();
		}
		else
		{
			std::cerr << "NOPE! push_back Out of range exception";
		}
	}

}

//TODO ten kawa³ek kodu jest po prostu z³y :(
int SingleList::pop_back()
{
	if (length>0)
	{
		length--;
		if (length>2)
		{
			//only for length>2 
			int next = head;
			while (tab[tab[next].next].next != -1)
			{
				next = tab[next].next;
			}
			tab[tab[next].next].next = -2;
			int value = tab[tab[next].next].value;
			tab[next].next = -1;
			return value;
		}
		else
		{
			if (length == 1)
			{
				int value = tab[head].value;
				tab[head].next = -2;
				head = nextFree;
				return value;
			}
			else
			{
				int value = tab[tab[head].next].value;
				tab[tab[head].next].next = -2;
				tab[head].next = -1;
				return value;
			}
		}

	}
	std::cerr << "NOPE! pop_back Array is empty";
	return -1;
}

int* SingleList::find(int value)
{
	if (length > 0)
	{
		int next = head;
		do
		{
			if (tab[next].value == value)
			{
				return &tab[next].value;
			}
			next = tab[next].next;
		} while (next != -1);//End of array
		return nullptr;
	}
	return nullptr;
}

int SingleList::size() const
{
	return length;
}

void SingleList::display()
{
	int next = head;
	do
	{
		std::cout << tab[next].value << std::endl;
		next = tab[next].next;
	} while (next != -1);//End of array
}
*/
int SingleList::getValue(int i)
{
	
	return head->value;

}


