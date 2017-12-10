#pragma once

template<typename T>
class stack
{
	struct node
	{
		T value;
		node* prev;
	};
	node *last;
	int length;

public:
	stack();
	~stack();

	void push(T x); // Dodaje element na stos
	T pop();        // Usuwa element ze stosu
	T& top();       // Zwraca referencjê do ostatniego elementu
	int size();       // Zwraca liczbê elementów na stosie
	bool empty();     // Sprawdza czy stos jest pusty
};

