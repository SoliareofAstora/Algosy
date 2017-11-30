#include "Assigment6.h"
#include "genSquare.cpp"
#include "QuickSort.cpp"
#include <iostream>
#include <iomanip>

template<typename  T>
struct pair
{
	T x;
	T y;

	bool operator<(pair a) {
		return x < a.x;
	}
	bool operator>(pair a) {
		return x > a.x;
	}
	pair& operator =(pair a) {
		x = a.x;
		y = a.y;
		return *this;
	}
};

void Assigment6::run()
{
	const int testSize = 100;
	pair<float>* arr= genSquare<pair<float>>(testSize);
	QuickSort(arr, 0, testSize-1);
	
	for (int i = 0; i<testSize; i++)
	{
		std::cout << std::endl <<arr[i].x<<" "<<arr[i].y;
	}
	system("PAUSE");
}

Assigment6::~Assigment6()
{
}
