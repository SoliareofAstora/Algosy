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
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
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

static float abs(pair a, pair b)
{
	float out = a.x - b.x;
	return out<0 ? out*-1 : out;
}

static outputData stripClosest(pair* arr, int size, outputData currentmin)
{
	outputData out = currentmin;
	for (int i = 0; i < size; i++)
	{
		for (int j = i+1; j < size && arr[i].y - arr[j].y < out.d; j++)
		{
			float d = distance(&arr[i], &arr[j]);
			if (d<out.d)
			{
				out = outputData(d, arr[i], arr[j]);
			}
		}
	}
	return out;
}

static outputData closestPair(pair* arrx, int size)
{
	if (size < 4)
	{
		return bruteForce(arrx, size);
	}

	int middleIndex = size / 2;
	pair middlePair = arrx[middleIndex];

	pair *larray = new pair[middleIndex];
	pair *rarray = new pair[size - middleIndex];
	
	for (int i = 0;i<size;i++)
	{
		if (i <middleIndex)
		{
			larray[i] = arrx[i];
		}else
		{
			rarray[i - middleIndex] = arrx[i];
		}
	}
	outputData lout = closestPair(larray, middleIndex);
	outputData rout = closestPair(rarray, size - middleIndex);
	
	outputData minimmum= min(lout, rout);

	pair *strip = new pair[size];
	int j = 0;
	for (int i = 0; i < size; i++)
	{
		if (abs(middlePair,arrx[i])<minimmum.d)
		{
			strip[j++] = arrx[i];
		}
	}
	outputData output = min(minimmum, stripClosest(strip, j, minimmum));
	delete[] strip;
	delete[] larray;
	delete[] rarray;

	return output;
}

static void displayOutput(outputData out,Stopwatch watch)
{
	std::cerr << " took " << watch.stopCounting() << " miliseconds\n";
	std::cerr  << "Found " << out;
}

static void PierwszeZadanie()
{
	Stopwatch watch;
	const int testSize = 10003;
	pair* arr = genSquare<pair>(testSize);
	
	qsort(arr, testSize, sizeof pair, compareX);
	watch.startCounting();
	static outputData out = closestPair(arr, testSize);
	std::cerr << "\nRecurrent";
	displayOutput(out, watch);

	watch.startCounting();
	static outputData out2 = bruteForce(arr, testSize);
	std::cerr << "\nBruteForce";
	displayOutput(out2, watch);


	delete arr;
}
