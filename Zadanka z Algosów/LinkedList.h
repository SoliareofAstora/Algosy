#pragma once

class LinkedList
{
	struct node {
		node *prev;                 // previous node 
		node *next;                 // next node 
		int value;               // stored value 
	};
	node* head;         // WskaŸnik do pierwszego wêz³a
	int length;

public:

	LinkedList();
	~LinkedList();
	void push_front(int value);
	int pop_front();
	void push_back(int value);
	int pop_back();
	int* find(int value);
	int size();
	void display();
	int getValue(int i);
};

