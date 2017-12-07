#include "genSorted.cpp"
#include <iostream>
#include "knuthShuffle.cpp"
static void displayIntArray(int *arr, int size)
{
	for (int i = 0; i<size; i++)
	{
		std::cerr << arr[i] << " ";
	}
	std::cerr << "\n";
}

static int simpleCounter(int *arr, int size)
{
	int out = 0;
	for (int i=0;i<size;i++)
	{
		if (arr[i]!=i)
		{	
			for (int j=i+1;j<size;j++)
			{
				if (arr[j]==i)
				{
					std::swap(arr[j], arr[i]);
					out++;
				}
			}
		}
	}
	return out;
}

static void DrugieZadanie()
{
	int testsize = 6;
	int* arr = genSorted(testsize);
	knuthShuffle(arr, arr + testsize);
	displayIntArray(arr, testsize);
	std::cerr<<simpleCounter(arr, testsize)<<"\t";
	displayIntArray(arr, testsize);
}