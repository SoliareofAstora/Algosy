#include "heap.h"

template class heap<int>;

template <typename T>
void heap<T>::heapify(T i)
{

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
	return length;
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

