#pragma once
template <typename T>
/*Kopiec binarny (ang. binary heap_min) to drzewo binarne, którego wszystkie poziomy 
 *z wyj¹tkiem ostatniego s¹ pe³ne, a ostatni poziom jest zape³niony od lewej strony. 
 *W kopcu typu min rodzic jest zawsze mniejszy (lub równy) od dzieci. 
 *W korzeniu drzewa znajduje siê najmniejszy element.
 */
class heap_min
{
	T arr[1000002] = {};
	int length=1;
	void heapify();  //Metoda heapify(T i) umieszcza korzeñ i w odpowiednim miejscu 
					 //zak³adaj¹c, ¿e jego dzieci s¹ korzeniami prawid³owych kopców.
	void heapifyDown(int i);
	void heapifyUp(int i);

public:
	heap_min();
	~heap_min();
	void build(T a[], int n); //Metoda build(T a[], int n) kopiuje zawartoœæ tablicy a 
							  //o rozmiarze n do wewnêtrznej tablicy kopca, 
							  //a nastêpnie naprawia jego strukturê metod¹ heapify(T).
	void push(T x);   // Wstawia element na stos
	T pop();          // Usuwa element ze stosu
	T& top();         // Zwraca referncjê do ostatniego elementu
	int size();       // Zwraca liczbê elementów na stosie
	bool empty();     // Sprawdza czy stos jest pusty
	bool check();     // Sprawdza czy w³aœciwoœæ kopca jest zachowana
	void print();
};
