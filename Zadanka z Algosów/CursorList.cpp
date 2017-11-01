#include "CursorList.h"
#include <iostream>

CursorList::CursorList()
{
	head = 0;
	length = 0;
	nextFree = 0;
}

CursorList::~CursorList()
{
}

void CursorList::push_front(int value)
{
	if (nextFree > length)
	{
		for (int i=0;i<nextFree+1;i++)
			if (tab[i].next==-1)
			{
				
			}
	}
	else
	{
		std::cerr << "NOPE! push_front Out of range exception";
	}
}

int CursorList::pop_front()
{
	if (firstFree>0)
	{
		firstFree--;
		int temp = tab[0];
		for (int i = 0; i<firstFree; i++)
		{
			tab[i] = tab[i + 1];
		}
		return temp;
	}
	std::cerr << "NOPE! pop_front Array is empty";
	return 0;
}

void CursorList::push_back(int value)
{
	if (sizeof tab / 8 > length + 1) 
	{

	}
	else
	{
		std::cerr << "NOPE! push_back Out of range exception";
	}

}

int CursorList::pop_back()
{
	if (firstFree>0)
	{
		return tab[firstFree--];
	}
	std::cerr << "NOPE! pop_back Array is empty";
	return 0;
}

int* CursorList::find(int value)
{
	for (int i = 0; i<firstFree; i++)
	{
		if (tab[i].value == value)
		{
			return &tab[i];
		}
	}
	return nullptr;
}

int CursorList::size() const
{
	return sizeof tab / 8;
}
