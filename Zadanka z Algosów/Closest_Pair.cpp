#include "genSquare.cpp"
#include "pair.cpp"
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
	for(int i =0;i<size;++i)
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

	static pair* temp = new pair[size];
	int j = 0;
	for (int i = middleIndex + 1; i < size; i++)
		temp[j++] = arrx[i];
	outputData rmin = closestPair(temp, newArryR, size - middleIndex);

	outputData minimum = min(lmin, rmin);

	static pair* strip = new pair[size];
	j = 0;
	for (int i =0;i<size;i++)
	{
		if (abs(arry[i].x-middlePair.x) < minimum.d)
		{
			strip[j++] = arry[i];
		}
	}
	minimum = min(minimum, closestToStrip(strip, j, minimum));

	//delete[] strip;
	//delete[] newArryL;
	//delete[] newArryR;
	return minimum;
}

static void displayOutput(outputData out,Stopwatch watch)
{
	std::cerr << " took " << watch.stopCounting() << " miliseconds\n";
	std::cerr  << "Found " << out;
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

	watch.startCounting();
	static outputData out = closestPair(arrSortedByX, arrSortedByY, testSize);
	static outputData out2 = bruteForce(arr, testSize);
	std::cerr << "\nRecurrent";

	displayOutput(out, watch);


	watch.startCounting();
	
	std::cerr << "\nBruteForce";
	displayOutput(out, watch);

	//delete arr;
}
