#include "genSquare.cpp"
#include "pair.cpp"
#include <cfloat>
#include "Stopwatch.h"
#include <iostream>
#include <iomanip>

template<typename T>
static void displayArray(T *arr, int size)
{
	for (int i = 0; i<size; i++)
	{
		std::cerr << std::setprecision(2)<< arr[i]<<"\n";
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

class outputData
{
public:
	float d;
	pair a, b;
	outputData() : d(FLT_MAX)
	{}
	outputData(float x, pair a, pair b) : d(x), a(a), b(b)
	{}

	friend std::ostream& operator <<(std::ostream& stream, const outputData &data) {
		stream << std::setprecision(5)<< data.a << " " << data.b 
		<< " with distance of " << std::setprecision(10) << data.d << "\n";
		return stream;
	}
};

static outputData min(outputData a, outputData b)
{
	return a.d < b.d ? a : b;
}

static outputData bruteForce(pair* arr, int size)
{
	outputData minimum;
	for (int i = 0; i < size; ++i)
	{
		for (int j = i + 1; j < size; ++j)
		{
			float dist = distance(&arr[i], &arr[j]);
			if (dist < minimum.d)
			{
				minimum = outputData(dist, arr[i], arr[j]);
			}
		}
	}
	return minimum;
}

static outputData closestToStrip(pair* arr, int size, outputData minimum_d)
{
	outputData minimum = minimum_d;
	for(int i =0;i<size;i++)
	{
		for (int j = i + 1; j < size && (arr[j].y - arr[i].y) < minimum.d; ++j)
		{
			float dist = distance(&arr[i], &arr[j]);
			if (dist < minimum.d)
			{
				minimum = outputData(dist, arr[i], arr[j]);
			}
		}
	}
	return minimum;
}

static outputData closestPair(pair* arrx, pair* arry, int size)
{
	if (size < 4)
	{
		return bruteForce(arrx, size);
	}

	int middleIndex = size / 2;
	pair middlePair = arrx[middleIndex];

	static pair* newArryL = new pair[middleIndex + 1];
	static pair* newArryR = new pair[size - middleIndex - 1];
	int rindex = 0, lindex = 0;
	for (int i = 0; i < size; i++)
	{
		if (arry[i] <= middlePair)
		{
			newArryL[lindex++] = arrx[i];
		}
		else
		{
			newArryR[rindex++] = arrx[i];
		}
	}

	outputData lmin = closestPair(arrx, newArryL, middleIndex);
	outputData rmin = closestPair(arrx, newArryR, size - middleIndex);

	outputData minimum = min(lmin, rmin);

	static pair* strip = new pair[size];
	int j = 0;
	for (int i =0;i<size;i++)
	{
		if (abs(arry[i]-middlePair) < minimum.d)
		{
			strip[j++] = arry[i];
		}
	}
	minimum = min(minimum, closestToStrip(strip, j, minimum));

	//delete[] strip, newArryL, newArryR;
	return minimum;
}

static void displayOutput(outputData out,Stopwatch watch)
{
	std::cout << " took " << watch.stopCounting() << " miliseconds\n";
	std::cout  << "Found " << out;
}

static void PierwszeZadanie()
{
	Stopwatch watch;
	const int testSize = 10000;
	pair* arr = genSquare<pair>(testSize);
	


	pair* arrSortedByX = new pair[testSize];
	pair* arrSortedByY = new pair[testSize];
	copyArray<pair>(arr, arrSortedByX, testSize);
	copyArray<pair>(arr, arrSortedByY, testSize);
	qsort(arrSortedByX, testSize, sizeof pair, compareX);
	qsort(arrSortedByY, testSize, sizeof pair, compareY);
	
	outputData out;
	
	watch.startCounting();
	out = closestPair(arrSortedByX, arrSortedByY, testSize);
	std::cout << "\nRecurrent";
	displayOutput(out, watch);
	//delete[] arrSortedByX;
	//delete[] arrSortedByY;

	watch.startCounting();
	out = bruteForce(arr, testSize);
	std::cout << "\nBruteForce";
	displayOutput(out, watch);

	//delete[] arr;
}
