#pragma once
class SingleList
{
	struct node
	{
		int value;		//node value 
		node* next;		//ref no new node
	};
	node *head;	//first node address
	int length;

public:
	SingleList();
	~SingleList();
	void push_front(int value);
	int pop_front();
	void push_back(int value);
	int pop_back();
	int* find(int value);
	int size() const;
	void display();
	int getValue(int i);
};

