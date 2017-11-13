#include "heap.h"
#include <iostream>

template class heap<int>;

template <typename T>
T heap<T>::getParent(int i)
{
	return arr[static_cast<int>(i / 2)];
}

template <typename T>
T heap<T>::getMin()
{
	return arr[1];
}


template <typename T>
void heap<T>::heapify(T i)
{
	T min = arr[i];
	if (2a > min)
	{
		
	}
}

template <typename T>
heap<T>::heap()
{
}

template <typename T>
heap<T>::~heap()
{
}

template <typename T>
void heap<T>::build(T[], int n)
{
	if ( length + n < sizeof arr / sizeof T)
	{
		for (int i=0;i<n;i++)
		{

		}
	}
	std::out_of_range("heap build");
}

template <typename T>
void heap<T>::push(T x)
{
	if (length + 1 < sizeof arr / sizeof T)
	{
		
		length++;
	}
	std::out_of_range("heap push");
}

template <typename T>
T heap<T>::pop()
{
	T temp;
	temp = 0;

	return temp;
}

template <typename T>
T& heap<T>::top()
{
	return arr[0];
}

template <typename T>
int heap<T>::size()
{
	return length-1;
}

template <typename T>
bool heap<T>::empty()
{
	return false;
}

template <typename T>
bool heap<T>::check()
{
	return false;
}

