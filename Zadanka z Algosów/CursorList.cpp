#include "CursorList.h"
#include <iostream>
#include <ppltasks.h>

CursorList::CursorList()
{
	head = 0;
	length = 0;
	nextFree = 0;
	for (int i=0; i< sizeof tab / 8;i++)
	{
		tab[i].next = -2;
	}
}

CursorList::~CursorList()
{
}

void CursorList::UpdateNextFree()
{
	if (sizeof tab / 8 > length + 1)
	{
		do
		{
			nextFree++;
			if (nextFree == sizeof tab / 8)
			{
				nextFree = 0;
			}

		} while (tab[nextFree].next != -2);
	}
	else
	{
		std::cerr << "Error. Array is full";
	}

}

void CursorList::push_front(int value)
{
	if (sizeof tab / 8 > length + 1)
	{
		
		tab[nextFree].value = value;
		tab[nextFree].next = head;
		head = nextFree;
		if (length==0)
		{//First element
			tab[nextFree].next = -1;
		}
		length++;
		UpdateNextFree();

	}
	else
	{
		std::cerr << "NOPE! push_front Out of range exception";
	}
}

int CursorList::pop_front()
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

void CursorList::push_back(int value)
{
	if (length==0)
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

//TODO ten kawa³ek kodu jest po prostu z³y, Tak wstyd mi za niego :(
int CursorList::pop_back()
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
			if (length==1)
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

int* CursorList::find(int value)
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
	std::cerr << "NOPE! find Array is empty";
	return nullptr;
}

int CursorList::size() const
{
	return length;
}

void CursorList::display()
{
	int next = head;
	do
	{
		std::cout << tab[next].value<<std::endl;
		next = tab[next].next;
	} while (next != -1);//End of array
}

int CursorList::getValue(int i)
{
	int x = 0;
	int next = head;
	while (x<length)
	{
		if (x==i)
		{
			return tab[next].value;
		}
		next = tab[next].next;
		x++;
	}
	return -1;
}


