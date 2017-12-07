#include "genSorted.cpp"
#include <iostream>
#include "knuthShuffle.cpp"
#include "utils.cpp"
#include "MergeSort.cpp"


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

	int* source = genSorted(testsize);
	knuthShuffle(source, source + testsize);
	displayArray(source, testsize);

	int *arr = new int[testsize];

	copyArray(source, arr,testsize);
	std::cerr<<simpleCounter(arr, testsize)<<"\t";
	displayArray(arr, testsize);

	copyArray(source, arr, testsize);
	std::cerr << MergeSort(arr, 0,testsize-1) << "\t";
	displayArray(arr, testsize);
}