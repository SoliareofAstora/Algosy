#include "ArrayList.h"
#include <iostream>

ArrayList::ArrayList()
{
	firstFree = 0;
}

ArrayList::~ArrayList()
{
}

void ArrayList::push_front(int value)
{
	
	if (sizeof tab / 4 > firstFree+1)
	{
		for (int i = firstFree; i >0; i--)
		{
			tab[i] = tab[i - 1];
		}
		tab[0] = value;
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
	return -1;
}

void ArrayList::push_back(int value)
{
	if (sizeof tab /4 >firstFree+1)
	{
		tab[firstFree++] = value;
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
	return -1;
}

int* ArrayList::find(int value)
{
	for (int i =0; i<firstFree;i++)
	{
		if (tab[i] == value)
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

void ArrayList::display()
{
	for (int i = 0; i<firstFree; i++)
	{
		std::cout << tab[i] << std::endl;
	}
}

int ArrayList::getValue(int i)
{
	return tab[i];
}






/*
    void push_front(int value) - wstawia element na pocz�tek listy
    int pop_front() - usuwa element z pocz�tku listy i zwraca jego warto��
    void push_back(int value) - wstawia element na koniec listy
    int pop_back() - usuwa element z ko�ca listy i zwraca jego warto��
    int* find(int value) - wyszukuje element o warto�ci value i zwraca do niego wska�nik lub nullptr gdy nie element istnieje
    int size() - zwraca liczb� element�w w li�cie
*/

