//Compilation command 
//  g++ -std=c++11 main.cpp ArrayList.cpp CursorList.cpp LinkedList.cpp SingleList.cpp StdList.cpp
#include <cstdlib>
#include <iostream>
#include "ArrayList.h"
#include "CursorList.h"
#include "SingleList.h"
#include "LinkedList.h"
#include <list>
#include <iterator>
#include "StdList.h"


int main()
{

	ArrayList array;
	CursorList cursor;
	SingleList single;
	LinkedList linked;
	StdList list;

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

	//Test vlaues
	//std::string commands = "AAADDAADADADAAD";
	//int values[15] = { 1,2,3,4,5,6,7,8,9,0,1,2,3,4,5 };

	for (int i = 0; i < commands.length(); i++)
	{
		char command = commands[i];

		if (command == 'A')
		{
			array.push_back(values[i]);
		}
		else if (command == 'F')
		{
			array.find(values[i]);
		}
		else if (command == 'D')
		{
			array.pop_front();
		}
		else if (command == 'S')
		{
			array.size();
		}
	}std::cerr << "array finished"<<std::endl;

	for (int i = 0; i < commands.length(); i++)
	{
		char command = commands[i];

		if (command == 'A')
		{
			std::cerr << "a" << std::endl;
			cursor.push_back(values[i]);
		}
		else if (command == 'F')
		{
			std::cerr << "f" << std::endl;
			cursor.find(values[i]);
		}
		else if (command == 'D')
		{
			std::cerr << "d" << std::endl;
			cursor.pop_front();
		}
		else if (command == 'S')
		{
			std::cerr << "s" << std::endl;
			cursor.size();
		}
	}std::cerr << "cursor finished" << std::endl;

	for (int i = 0; i < commands.length(); i++)
	{
		char command = commands[i];

		if (command == 'A')
		{
			single.push_back(values[i]);
		}
		else if (command == 'F')
		{
			single.find(values[i]);
		}
		else if (command == 'D')
		{
			single.pop_front();
		}
		else if (command == 'S')
		{
			single.size();
		}
	}std::cerr << "single finished" << std::endl;

	for (int i = 0; i < commands.length(); i++)
	{
		char command = commands[i];

		if (command == 'A')
		{
			linked.push_back(values[i]);
		}
		else if (command == 'F')
		{
			linked.find(values[i]);
		}
		else if (command == 'D')
		{
			linked.pop_front();
		}
		else if (command == 'S')
		{
			linked.size();
		}
	}std::cerr << "linked finished" << std::endl;

	for (int i = 0; i < commands.length(); i++)
	{
		char command = commands[i];

		if (command == 'A')
		{
			list.push_back(values[i]);
		}
		else if (command == 'F')
		{
			list.find(values[i]);
		}
		else if (command == 'D')
		{
			list.pop_front();
		}
		else if (command == 'S')
		{
			list.size();
		}
	}std::cerr << "list finished" << std::endl;

	for (int i=0;i<list.size();i++)
	{
		auto l_front = list.begin();
		std::advance(l_front, i);
		std::cout << *l_front << " " << array.getValue(i) << " " << cursor.getValue(i) << " " << single.getValue(i) << " " << linked.getValue(i);
		if (*l_front != array.getValue(i))
		{
			std::cerr << "array FALSE!!!";
		}
		if (*l_front != cursor.getValue(i))
		{
			std::cerr << "cursor FALSE!!!";
		}
		if (*l_front !=
			single.getValue(i))
		{
			std::cerr << "single FALSE!!!";
		}
		if (*l_front != linked.getValue(i))
		{
			std::cerr << "linked FALSE!!!";
		}
		std::cout << std::endl;
	}




	system("PAUSE");
	return 0;
}
