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
//Compilation command 
//  g++ -std=c++11 main.cpp ArrayList.cpp CursorList.cpp LinkedList.cpp SingleList.cpp
#include <cstdlib>
#include <iostream>
#include "ArrayList.h"
#include "CursorList.h"
#include "SingleList.h"
#include "LinkedList.h"
#include <list>
#include <iterator>

int main()
{

	ArrayList array;
	CursorList cursor;
	SingleList single;
	LinkedList linked;
	std::list<int> list;

	int n;
//	std::cin >> n;
	std::string commands;
	//int* values = new int[n];

	//for (int i = 0; i < n; i++)
	{
		//char command;
	//	std::cin >> command;
	//	commands += command;
	//	if (command == 'A' || command == 'F')
		{
	//		int value;
		//	std::cin >> value;
		//	values[i] = value;
		}
	}
	commands = "AAADDAADADADAAD";
	int values[15] = { 1,2,3,4,5,6,7,8,9,0,1,2,3,4,5 };
	for (int i = 0; i < commands.length(); i++)
	{
		std::cerr << i << std::endl;
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

		}
		else if (command == 'D')
		{

			array.pop_front();
			cursor.pop_front();
			single.pop_front();
			linked.pop_front();
			list.pop_front();
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
	std::cerr << "Array" << std::endl;
	array.display();
	std::cerr << "Cursor"<<std::endl;
	cursor.display();
	std::cerr << "Single" << std::endl;
	single.display();
	std::cerr << "Linked" << std::endl;
	linked.display();



	system("PAUSE");
	return 0;
}
