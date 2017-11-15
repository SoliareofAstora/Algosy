#pragma once

template <typename T>
class SortedLinkedList
{
	struct node {
		node *prev;                 // previous node 
		node *next;                 // next node 
		T value;               // stored value 
	};
	node* head;         // WskaŸnik do pierwszego wêz³a
	int length;

public:

	SortedLinkedList();
	~SortedLinkedList();
	void push(T value);
	void push_front(T value);
	T pop() const;
	void push_back(T value);
	T pop_back();
	int find(T value);
	int size() const;
	void print();
	T getValue(int i);
	void unique();
	T erase(int i);   
	void remove(T x);
	static SortedLinkedList merge(const SortedLinkedList&a,
										SortedLinkedList& b);
};

