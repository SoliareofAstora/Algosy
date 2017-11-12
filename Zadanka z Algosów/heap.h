#pragma once
template <typename T>
class heap
{
	T arr[100000];
	int length=0;
	void heapify(T i);  //Metoda heapify(int i) umieszcza korzeñ i w odpowiednim miejscu 
						//zak³adaj¹c, ¿e jego dzieci s¹ korzeniami prawid³owych kopców.

public:
	heap();
	~heap();
	void build(T[], int n); //Metoda build(int a[], int n) kopiuje zawartoœæ tablicy a 
							//o rozmiarze n do wewnêtrznej tablicy kopca, 
							//a nastêpnie naprawia jego strukturê metod¹ heapify().
	void push(T x);   // Wstawia element na stos
	T pop();        // Usuwa element ze stosu
	T& top();       // Zwraca referncjê do ostatniego elementu
	int size();       // Zwraca liczbê elementów na stosie
	bool empty();     // Sprawdza czy stos jest pusty
	bool check();     // Sprawdza czy w³aœciwoœæ kopca jest zachowana

};
