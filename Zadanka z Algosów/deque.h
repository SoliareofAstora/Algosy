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

	void push_front(T value); // Wstawia element na pocz�tek kolejki
	T pop_front();        // Usuwa element z pocz�tku kolejki
	T& front();           // Zwraca referencj� do pocz�tkowego elementu
	void push_back(T value);  // Wstawia element na koniec kolejki
	T pop_back();         // Usuwa element z ko�ca kolejki
	T& back();            // Zwraca referencj� do ko�cowego elementu
	int size();             // Zwraca liczb� element�w w kolejce
	bool empty();           // Sprawdza czy kolejka jest pusta
	bool full();
};

