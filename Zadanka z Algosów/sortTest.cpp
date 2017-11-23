#include "sortTest.h"
#include <iostream>
#include "genRandom.cpp"
#include "QuickSort.cpp"
#include <stdio.h>
#include <fstream>

void sortTest::copyArray(int source[], int output[], int size)
{
	for(int i=0;i<size;i++)
	{
		output[i] = source[i];
	}
}

sortTest::~sortTest()
{
}

void sortTest::beginTest()
{
	std::ofstream ofs;
	for (std::string element : fileNames)
	{
		ofs.open(element, std::ofstream::out | std::ofstream::trunc);
		ofs << Labels;
		ofs.close();
	}
	

}

void sortTest::testAllAlgorithms(int arrayToSort[], int size, std::string TestName)
{
	int *arrCopy = new int[size];
	copyArray(arrayToSort, arrCopy, size);
	watch.startCounting();
	QuickSort(arrCopy, 0, size - 1);
	watch.stopCounting();
	copyArray(arrayToSort, arrCopy, size);

	delete arrCopy;
}

void sortTest::testRandom(int size)
{
	system("PAUSE");
	int *arr = genRandom(size);
	testAllAlgorithms(arr, size, "Random_Numbers");

	system("PAUSE");
	delete arr;
}

void sortTest::testSorted()
{

}

void sortTest::testReverse()
{

}

void sortTest::testSortedFirst()
{

}

void sortTest::testSortedLast()
{

}
