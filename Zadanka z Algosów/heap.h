#pragma once
template <typename T>
class heap
{
	T arr[100000];
	int length=0;
	void heapify(T i);  //Metoda heapify(int i) umieszcza korze� i w odpowiednim miejscu 
						//zak�adaj�c, �e jego dzieci s� korzeniami prawid�owych kopc�w.

public:
	heap();
	~heap();
	void build(T[], int n); //Metoda build(int a[], int n) kopiuje zawarto�� tablicy a 
							//o rozmiarze n do wewn�trznej tablicy kopca, 
							//a nast�pnie naprawia jego struktur� metod� heapify().
	void push(T x);   // Wstawia element na stos
	T pop();        // Usuwa element ze stosu
	T& top();       // Zwraca referncj� do ostatniego elementu
	int size();       // Zwraca liczb� element�w na stosie
	bool empty();     // Sprawdza czy stos jest pusty
	bool check();     // Sprawdza czy w�a�ciwo�� kopca jest zachowana

};
