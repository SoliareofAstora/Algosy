#include "sortTest.h"
#include "genRandom.cpp"
#include "genSorted.cpp"
#include "genReverse.cpp"
#include "genSortedFirst.cpp"
#include "genSortedLast.cpp"
#include "QuickSort.cpp"
#include "QSort.cpp"
#include "MergeSort.cpp"
#include "RadxSort.cpp"
#include "HeapSort.cpp"
#include <fstream>
#include <iomanip>
#include <stdlib.h> 
#include <iostream>

void sortTest::copyArray(int *source, int *output, int size)
{
	for(int i=0;i<size;i++)
	{
		output[i] = source[i];
	}
}

void sortTest::displayArray(int *arr, int size)
{
	for (int i=0;i<size;i++)
	{
		std::cerr << arr[i] << " ";
	}
	std::cerr << "\n";
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
		ofs <<Labels<<"\n";
		ofs.close();
	}
	for (int i = 10; i < 20; i += 2)
	{
		testRandom(i);
		testSorted(i);
		testReverse(i);
		testSortedFirst(i);
		testSortedLast(i);
	}
}

void sortTest::testRandom(int size)
{
	int *arr = genRandom(size);
	testAllAlgorithms(arr, size, 0);
	delete[] arr;
}

void sortTest::testSorted(int size)
{
	int *arr = genSorted(size);
	testAllAlgorithms(arr, size, 1);
	delete[] arr;
}

void sortTest::testReverse(int size)
{
	int *arr = genReverse(size);
	testAllAlgorithms(arr, size, 2);
	delete[] arr;
}

void sortTest::testSortedFirst(int size)
{
	int *arr = genSortedFirst(size);
	testAllAlgorithms(arr, size, 3);
	delete[] arr;
}

void sortTest::testSortedLast(int size)
{
	int *arr = genSortedLast(size);
	testAllAlgorithms(arr, size, 4);
	delete[] arr;
}

void sortTest::testAllAlgorithms(int *sourceArray, int size, int fileNameID)
{
	std::ofstream ofs;
	ofs.open(fileNames[fileNameID], std::ofstream::out | std::ofstream::app);
	ofs << size << ", ";
	int *arrCopy = new int[size];

	copyArray(sourceArray, arrCopy, size);
	watch.startCounting();
	MergeSort(arrCopy,0,size-1);
	displayArray(arrCopy,size);
	ofs << std::fixed << std::setprecision(8) << watch.stopCounting() << ", ";

	copyArray(sourceArray, arrCopy, size);
	watch.startCounting();
	QuickSort(arrCopy, 0, size - 1);
	ofs << std::fixed << std::setprecision(8) << watch.stopCounting() << ", ";

	copyArray(sourceArray, arrCopy, size);
	watch.startCounting();
	HeapSort(arrCopy,size);
	ofs << std::fixed << std::setprecision(8) << watch.stopCounting() << ", ";

	copyArray(sourceArray, arrCopy, size);
	watch.startCounting();
	RadxSort();
	ofs << std::fixed << std::setprecision(8) << watch.stopCounting() << ", ";

	copyArray(sourceArray, arrCopy, size);
	watch.startCounting();
	std::sort(&arrCopy[0], &arrCopy[size - 1]);
	ofs << std::fixed << std::setprecision(8) << watch.stopCounting() << ", ";

	copyArray(sourceArray, arrCopy, size);
	watch.startCounting();
	QSort(arrCopy, size);
	ofs << std::fixed << std::setprecision(8) << watch.stopCounting() << "\n";

	ofs.close();
	delete[] arrCopy;
	//system("PAUSE");
}