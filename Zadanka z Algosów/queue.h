#pragma once
#include "deque.h"

template<typename T>
class queue:public deque<T>
{
public:
	queue();
	~queue();

	void enqueue(T x); // Wstawia element do kolejki
	int dequeue();       // Usuwa element z kolejki
	int& peek();         // Zwraca referencj� do najstarszego elementu
	int size();          // Zwraca liczb� element�w w kolejce
	bool empty();        // Sprawdza czy kolejka jest pusty
};

