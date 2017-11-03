#pragma once
#include <list>

class StdList
{
	std::list<int> tab;
public:
	StdList();
	~StdList();
	void push_front(int value);
	int pop_front();
	void push_back(int value);
	int pop_back();
	int* find(int value);
	int size() const;
	void display();
	int getValue(int i);
	std::list<int>::iterator begin();

};

