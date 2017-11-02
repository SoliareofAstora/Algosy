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
#include "SingleList.h"
#include "LinkedList.h"
#include <list>

int main()
{

	ArrayList array;
	CursorList cursor;
	SingleList single;
	LinkedList linked;
	std::list<int> list;

	int n;
	std::cin >> n;
	std::string commands;
	int* values = new int[n];

	for (int i = 0; i < n; i++)
	{
		char command;
		std::cin >> command;
		commands += command;
		if (command == 'A' || command == 'F')
		{
			int value;
			std::cin >> value;
			values[i] = value;
		}
	}

	for (int i = 0; i < commands.length(); i++)
	{
		char command = commands[i];

		if (command == 'A')
		{
			array.push_back(values[i]);
			cursor.push_back(values[i]);
			single.push_back(values[i]);
			linked.push_back(values[i]);
			list.push_back(values[i]);
		}
		else if (command == 'F')
		{
			array.pop_front;
			cursor.pop_front;
			single.pop_front;
			linked.pop_front;
			list.pop_front;
		}
		else if (command == 'D')
		{

		}
		else if (command == 'S')
		{
		}
	}

	for (int i=0;i<list.size();i++)
	{
		auto l_front = list.begin();
		std::advance(l_front, i);

		if (*l_front != array.getValue(i))
		{
			std::cerr << "array FALSE!!!";
		}
		if (*l_front != cursor.getValue(i))
		{
			std::cerr << "cursor FALSE!!!";
		}
		if (*l_front != single.getValue(i))
		{
			std::cerr << "single FALSE!!!";
		}
		if (*l_front != linked.getValue(i))
		{
			std::cerr << "linked FALSE!!!";
		}
	}



	system("PAUSE");
	return 0;
}
