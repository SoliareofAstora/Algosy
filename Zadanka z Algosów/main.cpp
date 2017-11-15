//Linux compilation command 
//  g++ -std=c++11 main.cpp 
#include <iostream> 
#include <stdlib.h>  
#include <string>
#include <time.h>   
#include "heap_min.h"
#include <chrono>

typedef unsigned char byte;

template<class T>
void ExecuteCommands(std::string commands, int values[], T *t)
{
	for (int i = 0; i <10; i++)
	{
		char command = commands[i];

		if (command == 'A')
		{
			//t->enqueue(values[i]);
			t->push(values[i]);
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
	
	std::cout << "ftw" << std::endl;
	srand(time(NULL));
	//Nawiasiki 
	/*
	long testSize = 18;

	for (int x = 0; x < 1000000; x++) {
		bool check = false;
		std::string result = "";
		stack<char> brackets;
		for (int i = 0; i < testSize; i++)
		{
			long a = rand() % 4;
			if (a == 0)
			{
				check = false;
				brackets.push('(');
				result += "(";
			}
			else if (a == 1)
			{
				check = false;
				brackets.push('[');
				result += "[";
			}
			else if (a == 2)
			{
				result += ")";
				char temp = brackets.pop();

				if (temp == '(' && temp != NULL )
				{
					//Jeśli nie liczy się to, że pierwszy i ostatni nawias ciągu
					//muszą być takie same, to trzeba usunąć wszystkie warunki
					//check = true;
					if (i==testSize-1)
					{
						check = true;
					}
					else if (brackets.empty())
					{
						check = false;
						break;
					}
				}
				else
				{
					check = false;
					break;
				}
			}
			else
			{
				char temp = brackets.pop();
				result += "]";
				if (temp == '[' && temp != NULL)
				{
					if (i == testSize - 1)
					{
						check = true;
					}
					else if (brackets.empty())
					{
						check = false;
						break;
					}
				}
				else
				{
					check = false;
					break;
				}
			}
		}
		if (check && brackets.empty())
		{

			std::cout << result << " Good Combination!!!! \n";
		}
		else
		{
			//std::cerr << result << " Bad Combination \n";
		}
	}

	/**/

	//Linux reading
	/*
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
	//	std::string commands = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAA";
	//int values[] = {50,23,3,54,2,54,12,7,8,100};
std::cout << "ftw" << std::endl;
	int const testSize = 1000000;
	static int values[testSize];

	for (int i = 0; i < testSize; i++) {
		values[i] = rand();
	}
	std::cout <<"first HEAP" << std::endl;
	static 	heap_min <int> deq;
	{
		auto start = std::chrono::high_resolution_clock::now();

		deq.build(values, testSize);

		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> elapsed = end - start;
		std::cerr << "Elapsed time[s] = " << elapsed.count() << std::endl;
	}
	std::cout << "second HEAP" << std::endl;

	static heap_min <int> deq2;
	{
		auto start = std::chrono::high_resolution_clock::now();

		for (int i = 0; i < testSize; i++) {
			deq2.push(values[i]); 
		}

		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> elapsed = end - start;
		std::cerr << "Elapsed time[s] = " << elapsed.count() << std::endl;
	}
	

	std::cout <<std::endl <<"SIZE1: "<< deq.size() << std::endl;
	std::cout << std::endl << "SIZE2: " << deq2.size() << std::endl;
	

	/*
	ExecuteCommands(commands, values, &cursor);
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
