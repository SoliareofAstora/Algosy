#include "StdList.h"
#include "StdList.h"
#include <iostream>

StdList::StdList()
{
}


StdList::~StdList()
{
}

void StdList::push_front(int value)
{
	tab.push_front(value);
}

int StdList::pop_front()
{
	if (tab.size() > 0)
	{
		auto l_front = tab.begin();
		int i = *l_front;
		tab.pop_front();
		return i;
	}
	return -1;
}

void StdList::push_back(int value)
{
	tab.push_back(value);
}

int StdList::pop_back()
{
	auto l_front = tab.end();
	int i = *l_front;
	tab.pop_back();
	return i;
}

int* StdList::find(int value)
{
	for (int i=0;i<tab.size();i++)
	{
		auto l_front = tab.begin();
		std::advance(l_front, i);
		if (*l_front==value)
		{
			return &*l_front;
		}
	}
	return nullptr;
}

int StdList::size() const
{
	return tab.size();
}

void StdList::display()
{
	for (int i = 0; i < tab.size(); i++)
	{
		auto l_front = tab.begin();
		std::advance(l_front, i);
		std::cout << *l_front;
	}
}

int StdList::getValue(int i)
{
	auto l_front = tab.begin();
	std::advance(l_front, i);
	return *l_front;
}

std::list<int>::iterator StdList::begin()
{
	return tab.begin();
}

