/*
A value - dodaj liczbę 0 ≤ x ≤ 106 do listy
F value - wypisz "TRUE" jeżeli value jest obecne w liście, "FALSE" w przeciwnym razie
D - usuń z listy pierwszy element i go wypisz, jeśli lista jest pusta wypisz "EMPTY"
S - wypisz rozmiar listy


10
A 6210
D
A 9704
A 3231
A 530
A 7019
F 3022
A 317
D
D
 */
#include <cstdlib>
#include <iostream>
#include "ArrayList.h"
#include "CursorList.h"
using namespace std;
int main()
{
	CursorList tab;
//	tab.push_back(10);
//	tab.push_back(12);
	cout << tab.getValue(1) << endl;
	tab.push_front(30);
	cout << tab.getValue(1) << endl;
	tab.push_front(12);
//	tab.push_back(95);
	cout << tab.getValue(1) << endl;
	tab.push_front(14);
	cout << tab.getValue(1) << endl;
/*	tab.display();
	cerr << tab.size() << endl;
	if (tab.find(10))
	{
		cerr << "true"<<endl;
	}
	else
	{
		cerr << "false" << endl;
	}
	cerr << tab.pop_front() << endl;
	if (tab.find(10))
	{
		cerr << "true" << endl;
	}
	else
	{
		cerr << "false" << endl;
	}
	cerr << "done" << endl;
	tab.pop_back();
	cerr << "done" << endl;
	tab.pop_back();
	cerr << "done" << endl;
	tab.pop_back();
	cerr << "done" << endl;
	cerr << tab.size() << endl;
	*/

	system("PAUSE");
	return 0;
}
