#include "heap_min.h"
#include <iostream>
//Created with help: https://www.codeproject.com/Tips/816934/Min-Binary-Heap-Implementation-in-Cplusplus

template class heap_min<int>;

template <typename T>
void heap_min<T>::heapify()
{
	if (size() > 0)
	{
		for (int i = size(); i > 0; i--)
			heapifyDown(i);
		return;
	}
	std::out_of_range("heapify");
}

template <typename T>
void heap_min<T>::heapifyDown(int i)
{
	int left = 2 * i;
	if (left >=length)
		return; 
	int right = 2 * i + 1;
	int min = i;
	if (arr[min] > arr[left])
		min = left;
	if (right<length && arr[min] > arr[right])
		min = right;
	if (min == i)
		return;
	std::swap(arr[i], arr[min]);
	heapifyDown(min);
}

template <typename T>
void heap_min<T>::heapifyUp(int i)
{
	if (i==1)
		return;
	int parent = static_cast<int> (i / 2);
	if (arr[parent]>arr[i])
	{
		std::swap(arr[parent], arr[i]);
		heapifyUp(parent);
	}
}

template <typename T>
heap_min<T>::heap_min()
{
}

template <typename T>
heap_min<T>::~heap_min()
{
}

template <typename T>
void heap_min<T>::build(T a[], int n)
{
	if ( length + n < sizeof arr / sizeof T)
	{
		for (int i=0;i<n;i++)
		{
			arr[length + i] = a[i];
		}
		length += n;
		heapify();
	}
	std::out_of_range("heap_min build");
}

template <typename T>
void heap_min<T>::push(T x)
{
	if (length < sizeof arr / sizeof T)
	{
		arr[length] = x;
		heapifyUp(length);
		length++;
		
		return;
	}
	std::out_of_range("heap_min push");
}

template <typename T>
T heap_min<T>::pop()
{
	if (length != 1)
	{
		T temp = arr[1];
		arr[1] = arr[length-1];
		heapify();
		length--;
		return temp;
	}
	std::out_of_range("heap_min pop");
}

template <typename T>
T& heap_min<T>::top()
{
	return arr[length-1];
}

template <typename T>
int heap_min<T>::size()
{
	return length-1;
}

template <typename T>
bool heap_min<T>::empty()
{
	return length==1;
}

template <typename T>
bool heap_min<T>::check()
{
	bool ok = true;
	for (int i=2;i<length;i++)
	{
		if (arr[i]<arr[static_cast<int> (i / 2)])
		{
			ok = false;
		}
	}
	return ok;
}

template <typename T>
void heap_min<T>::print()
{
	for (int i = 1; i<length;i++)
	{
		std::cerr << arr[i] << " ";
	}
	std::cerr << std::endl;
}

