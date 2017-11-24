#pragma once
#include "Stopwatch.h"
#include <string>

class sortTest
{
	Stopwatch watch;

	sortTest(){}
	static void copyArray(int *source, int *output, int size);
	static void displayArray(int *arr, int size);

	std::string fileNames[5] = {
		"Random.txt",
		"Sorted.txt",
		"Reverse.txt",
		"SortedFrist.txt",
		"SortedLast.txt",
	};
	std::string Labels = 
	"n, MergeSort, QuickSort, HeapSort, RadxSort, std::sort, qsort";
public:
	static sortTest &instance() { static sortTest test; return test; };
	~sortTest();
	void beginTest();
	void testAllAlgorithms(int *arrayToSort, int size, int fileNameID);
	void testRandom(int size); //program testeruje ci�g losowych liczb
	void testSorted(int size); //program testeruje ci�g rosn�cy
	void testReverse(int size); //program testeruje ci�g malej�cy
	void testSortedFirst(int size); //program testeruje ci�g rosn�cy z losowym elementem na pocz�tku
	void testSortedLast(int size); //program testeruje ci�g rosn�cy z losowym elementem na ko�cu
};

