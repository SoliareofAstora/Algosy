#pragma once
#include <string>
#include "Stopwatch.h"

class sortTest
{
	Stopwatch watch;
	sortTest(){}
	void copyArray(int source[], int output[], int size);
	std::string fileNames[5] = {
		"Random.txt",
		"Sorted.txt",
		"Reverse.txt",
		"SortedFrist.txt",
		"SortedLast.txt",
	};
	std::string Labels = "n, MergeSort, QuickSort, HeapSort, RadxSort, std::sort, qsort";
public:
	static sortTest &instance() { static sortTest test; return test; };
	~sortTest();
	void beginTest();
	void testAllAlgorithms(int arrayToSort[], int size, std::string TestName);
	void testRandom(int test); //program testeruje ci�g losowych liczb
	void testSorted(); //program testeruje ci�g rosn�cy
	void testReverse(); //program testeruje ci�g malej�cy
	void testSortedFirst(); //program testeruje ci�g rosn�cy z losowym elementem na pocz�tku
	void testSortedLast(); //program testeruje ci�g rosn�cy z losowym elementem na ko�cu
};

