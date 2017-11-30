#include "genSquare.cpp"
#include "pair.cpp"

template<typename T>
void copyArray(T *source, T *output, int size)
{
	for (int i = 0; i<size; i++)
	{
		output[i] = source[i];
	}
}

struct outputData
{
	float d;
	pair a, b;
};



static void PierwszeZadanie()
{
	const int testSize = 10;
	pair* arr = genSquare<pair>(testSize);

	pair* arrSortedByX=new pair[testSize];
	pair* arrSortedByY = new pair[testSize];
	copyArray<pair>(arr, arrSortedByX, testSize);
	copyArray<pair>(arr, arrSortedByY, testSize);

	qsort(arrSortedByX, testSize, sizeof pair, compareX);
	qsort(arrSortedByY, testSize, sizeof pair, compareY);
}