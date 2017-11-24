#pragma once
#include "deque.h"

template<typename T>
class queue:public deque<T>
{
public:
	queue();
	~queue();

	void enqueue(T x); // Wstawia element do kolejki
	void push(T x) { enqueue(x); }
	T dequeue();       // Usuwa element z kolejki
	T pop() {return dequeue(); }
	T& peek();         // Zwraca referencj� do najstarszego elementu
	int size();          // Zwraca liczb� element�w w kolejce
	bool empty();        // Sprawdza czy kolejka jest pusty
};

