#pragma once
class stack
{
	struct node
	{
		int value;
		node* prev;
	};
	node *last;
	int length;
public:
	stack();
	~stack();

	void push(int x); // Dodaje element na stos
	int pop();        // Usuwa element ze stosu
	int& top();       // Zwraca referencjê do ostatniego elementu
	int size();       // Zwraca liczbê elementów na stosie
	bool empty();     // Sprawdza czy stos jest pusty
};

