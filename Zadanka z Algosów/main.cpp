//Linux compilation command 
//  g++ -std=c++11 main.cpp 
#include <iostream> 
#include <stdlib.h>  
#include <string>
#include <time.h>   
#include "heap_min.h"
#include "SortedArrayList.h"
#include "SortedLinkedList.h"
#include <chrono>
#include "stack.h"
#include "QuickSort.cpp"

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

template<class T>
void MakeTest(std::string name,T *t)
{
	
}

int main()
{

	srand(time(NULL));
	//Nawiasiki 

	long testSize = 18;

	for (int x = 0; x < 1000000; x++) {
		bool check = false;
		std::string result = "";
		stack<char> brackets;
		for (int i = 0; i < testSize; i++)
		{
			long a = rand() / (RAND_MAX/4);
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

				if (temp == '(' && temp != NULL)
				{
					//Jeśli nie liczy się to, że pierwszy i ostatni nawias ciągu
					//muszą być takie same, to trzeba usunąć wszystkie warunki
					//check = true;
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

	/*



	std::cout << "test array preparation";
	int const testSize = 1000;
	static int values[testSize];
	for (int i = 0; i < testSize; i++) {
		values[i] = rand();
	}
	std::cerr<<"complete" << std::endl;

	std::cout << "HEAP push ";
	static heap_min <int> heap;
	{
		auto start = std::chrono::high_resolution_clock::now();

		for (int i = 0; i < testSize; i++) {
			heap.push(values[i]);
		}

		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> elapsed = end - start;
		std::cerr << "Elapsed time[s] = " << elapsed.count() << std::endl;
	}

	std::cout << "LINKED push ";
	static SortedLinkedList <int> linked;
	{
		auto start = std::chrono::high_resolution_clock::now();

		for (int i = 0; i < testSize; i++) {
			linked.push(values[i]);
		}

		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> elapsed = end - start;
		std::cerr << "Elapsed time[s] = " << elapsed.count() << std::endl;
	}

	std::cout << "ARRAY push ";
	static SortedArrayList <int> array;
	{
		auto start = std::chrono::high_resolution_clock::now();

		for (int i = 0; i < testSize; i++) {
			array.push(values[i]);
		}

		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> elapsed = end - start;
		std::cerr << "Elapsed time[s] = " << elapsed.count() << std::endl;
	}	
	std::cerr << std::endl;

	//////////////////////
	{
		auto start = std::chrono::high_resolution_clock::now();

		QuickSort(values, 0, (sizeof values / 4)-1);

		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> elapsed = end - start;
		std::cerr << "Source quick sort Elapsed time[s] = " << elapsed.count() << std::endl;
	}
	
	//Display objects
	//heap.print();
	//array.print();
	//linked.print();
	//for (int i = 0; i < testSize; i++) 
	//{
	//	std::cerr << values[i] << " ";
	//}
	//std::cerr << std::endl;
	
	//////////////////////
	std::cerr << std::endl;
	std::cout << "HEAP pop ";
	{
		auto start = std::chrono::high_resolution_clock::now();

		for (int i = 0; i < testSize; i++) {
			if (heap.pop()!=values[i])
			{
				std::cerr << "HEAP ERROR!" << std::endl;
			}
			
		}

		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> elapsed = end - start;
		std::cerr << "Elapsed time[s] = " << elapsed.count() << std::endl;
	}
	std::cout << "LINKED pop ";
	{
		auto start = std::chrono::high_resolution_clock::now();

		for (int i = 0; i < testSize; i++) {
			if (linked.pop() != values[i])
			{
				std::cerr << "LINKED ERROR!" << std::endl;
				
			}
		}

		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> elapsed = end - start;
		std::cerr << "Elapsed time[s] = " << elapsed.count() << std::endl;
	}
	std::cout << "ARRAY pop ";
	{
		auto start = std::chrono::high_resolution_clock::now();

		for (int i = 0; i < testSize; i++) {
			if (array.pop() != values[i])
			{
				std::cerr << "ARRAY ERROR!" << std::endl;

			}
		}

		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> elapsed = end - start;
		std::cerr << "Elapsed time[s] = " << elapsed.count() << std::endl;
	}
	*/
	system("PAUSE");
	return 0;
}
