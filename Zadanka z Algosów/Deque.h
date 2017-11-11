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

	void push_front(int value); // Wstawia element na pocz�tek kolejki
	int pop_front();        // Usuwa element z pocz�tku kolejki
	int& front();           // Zwraca referencj� do pocz�tkowego elementu
	void push_back(int value);  // Wstawia element na koniec kolejki
	int pop_back();         // Usuwa element z ko�ca kolejki
	int& back();            // Zwraca referencj� do ko�cowego elementu
	int size();             // Zwraca liczb� element�w w kolejce
	bool empty();           // Sprawdza czy kolejka jest pusta
	bool full();
};

