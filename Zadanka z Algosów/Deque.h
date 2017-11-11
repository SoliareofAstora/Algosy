#pragma once
class Deque
{
	int arr[10000];
	int read;
	int write;

	void increasePointer(int &pointer);
	void decreasePointer(int &pointer);
	int getIncreasedPointer(int &pointer);
	int getDecreasedPointer(int &pointer);

public:
	Deque();
	~Deque();

	void push_front(int value); // Wstawia element na pocz¹tek kolejki
	int pop_front();        // Usuwa element z pocz¹tku kolejki
	int& front();           // Zwraca referencjê do pocz¹tkowego elementu
	void push_back(int value);  // Wstawia element na koniec kolejki
	int pop_back();         // Usuwa element z koñca kolejki
	int& back();            // Zwraca referencjê do koñcowego elementu
	int size();             // Zwraca liczbê elementów w kolejce
	bool empty();           // Sprawdza czy kolejka jest pusta
	bool full();
};

