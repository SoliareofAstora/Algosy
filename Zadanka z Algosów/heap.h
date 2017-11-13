#pragma once
template <typename T>
/*Kopiec binarny (ang. binary heap) to drzewo binarne, kt�rego wszystkie poziomy 
 *z wyj�tkiem ostatniego s� pe�ne, a ostatni poziom jest zape�niony od lewej strony. 
 *W kopcu typu min rodzic jest zawsze mniejszy (lub r�wny) od dzieci. 
 *W korzeniu drzewa znajduje si� najmniejszy element.
 */
class heap
{
	T arr[100000];
	int length=1;
	void heapify(T i);  //Metoda heapify(T i) umieszcza korze� i w odpowiednim miejscu 
						//zak�adaj�c, �e jego dzieci s� korzeniami prawid�owych kopc�w.
	T getParent(int i);
	T getMin();
public:
	heap();
	~heap();
	void build(T a[], int n); //Metoda build(T a[], int n) kopiuje zawarto�� tablicy a 
							  //o rozmiarze n do wewn�trznej tablicy kopca, 
							  //a nast�pnie naprawia jego struktur� metod� heapify(T).
	void push(T x);   // Wstawia element na stos
	T pop();          // Usuwa element ze stosu
	T& top();         // Zwraca referncj� do ostatniego elementu
	int size();       // Zwraca liczb� element�w na stosie
	bool empty();     // Sprawdza czy stos jest pusty
	bool check();     // Sprawdza czy w�a�ciwo�� kopca jest zachowana

};
