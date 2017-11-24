#pragma once
template<typename T>
class deque
{
	T arr[100000];
	int read;
	int write;

	void increasePointer(int &pointer);
	void decreasePointer(int &pointer);
	int getIncreasedPointer(int &pointer);
	int getDecreasedPointer(int &pointer);

public:
	deque();

	~deque( );

	void push_front(T value); // Wstawia element na pocz¹tek kolejki
	T pop_front();        // Usuwa element z pocz¹tku kolejki
	T& front();           // Zwraca referencjê do pocz¹tkowego elementu
	void push_back(T value);  // Wstawia element na koniec kolejki
	T pop_back();         // Usuwa element z koñca kolejki
	T& back();            // Zwraca referencjê do koñcowego elementu
	int size();             // Zwraca liczbê elementów w kolejce
	bool empty();           // Sprawdza czy kolejka jest pusta
	bool full();
};

