#pragma once
#include "deque.h"

class queue:deque
{
public:
	queue();
	~queue();

	void enqueue(int x); // Wstawia element do kolejki
	int dequeue();       // Usuwa element z kolejki
	int& peek();         // Zwraca referencj� do najstarszego elementu
	int size();          // Zwraca liczb� element�w w kolejce
	bool empty();        // Sprawdza czy kolejka jest pusty
};

