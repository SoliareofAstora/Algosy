#include <iostream>

template<typename T>
static void displayArray(T *arr, int size)
{
	for (int i = 0; i<size; i++)
	{
		std::cerr << arr[i] << " ";
	}
	std::cerr << "\n";
}

template<typename T>
static void copyArray(T *source, T *output, int size)
{
	for (int i = 0; i < size; i++)
	{
		output[i] = source[i];
	}
}