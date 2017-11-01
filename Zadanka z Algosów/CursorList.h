#pragma once
class CursorList
{
	struct node
	{
		int value;			//node value 
		int next;		//index of new node
	};
	node tab[10000];	//node array
	int head;			//indeks of first node
	int length;
	int nextFree;

public:
	CursorList();
	~CursorList();
	void push_front(int value);
	int pop_front();
	void push_back(int value);
	int pop_back();
	int* find(int value);
	int size() const;
};

