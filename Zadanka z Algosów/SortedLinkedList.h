#pragma once

class SortedLinkedList
{
	struct node {
		node *prev;                 // previous node 
		node *next;                 // next node 
		int value;               // stored value 
	};
	node* head;         // WskaŸnik do pierwszego wêz³a
	int length;

public:

	SortedLinkedList();
	~SortedLinkedList();
	void push(int value);
	void push_front(int value);
	int pop() const;
	void push_back(int value);
	int pop_back();
	int find(int value);
	int size() const;
	void print();
	int getValue(int i);
	void unique();
	int erase(int i);   
	void remove(int x);
	static SortedLinkedList merge(const SortedLinkedList&a,
										SortedLinkedList& b);
};

