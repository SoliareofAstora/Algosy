//Linux compilation command 
//  g++ -std=c++11 main.cpp 
#include <iostream>
#include "deque.h"
#include "stack.h"
#include "queue.h"
#include <iterator>

template<class T>
void ExecuteCommands(std::string commands, int values[], T *t)
{
	for (int i = 0; i <5; i++)
	{
		char command = commands[i];

		if (command == 'A')
		{
			t->enqueue(values[i]);
		}
		else if (command == 'F')
		{
			//t->find(values[i]);
		}
		else if (command == 'D')
		{
		//	t->pop();
		}
		else if (command == 'S')
		{
		//	t->size();
		}
	}
}


int main()
{


	/*
	//Linux reading
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
	}*/
	

	//Test vlaues
	std::string commands = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAA";
	int values[30] = {1,1,3,4,5,2,3,4,5,2,3,4,5,6,1,2,3,6,7,8,2,3,1,3,5,3,1,3,3,2};

	queue <int> deq;
	ExecuteCommands(commands, values, &deq);
	std::cout << deq.size() << std::endl;
	while (!deq.empty())
	{
		std::cout << deq.dequeue() << std::endl;
	}


/*	ExecuteCommands(commands, values, &cursor);
	std::cerr << "cursor finished" << std::endl;

	ExecuteCommands(commands, values, &single);
	std::cerr << "single finished" << std::endl;

	ExecuteCommands(commands, values, &linked);
	std::cerr << "linked finished" << std::endl;

	ExecuteCommands(commands, values, &list);
	std::cerr << "std::list finished \n" << std::endl;*/

	/*for (int i = 0; i < list.size(); i++)
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
	}*/
	system("PAUSE");
	return 0;
}
