#include "ArrayList.h"
#include <iostream>

ArrayList::ArrayList()
{
	firstFree = 0;
}

void ArrayList::push_front(int x)
{
	
	if (sizeof tab / 4 > firstFree+1)
	{
		for (int i = firstFree; i >0; i--)
		{
			tab[i] = tab[i - 1];
		}
		tab[0] = x;
		firstFree++;
	}
	else
	{
		std::cerr << "NOPE! push_front Out of range exception";
	}
}

int ArrayList::pop_front()
{
	if (firstFree>0)
	{	
		firstFree--;
		int temp = tab[0];
		for (int i =0; i<firstFree;i++)
		{
			tab[i] = tab[i + 1];
		}
		return temp;
	}
	std::cerr << "NOPE! pop_front Array is empty";
	return 0;
}

void ArrayList::push_back(int x)
{
	if (sizeof tab /4 >firstFree+1)
	{
		tab[firstFree++] = x;
	}
	else
	{
		std::cerr << "NOPE! push_back Out of range exception";
	}
	
}

int ArrayList::pop_back()
{
	if (firstFree>0)
	{
		return tab[firstFree--];
	}
	std::cerr << "NOPE! pop_back Array is empty";
	return 0;
}

int* ArrayList::find(int x)
{
	for (int i =0; i<firstFree;i++)
	{
		if (tab[i]==x)
		{
			return &tab[i];
		}
	}
	return nullptr;
}

int ArrayList::size() const
{
	return firstFree;
}




/*
    void push_front(int x) - wstawia element na pocz�tek listy
    int pop_front() - usuwa element z pocz�tku listy i zwraca jego warto��
    void push_back(int x) - wstawia element na koniec listy
    int pop_back() - usuwa element z ko�ca listy i zwraca jego warto��
    int* find(int x) - wyszukuje element o warto�ci x i zwraca do niego wska�nik lub nullptr gdy nie element istnieje
    int size() - zwraca liczb� element�w w li�cie
*/

