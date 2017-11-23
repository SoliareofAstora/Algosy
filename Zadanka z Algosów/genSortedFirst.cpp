#include <climits>
#include <random>
#include <chrono>
#pragma warning (disable : 4244)
//warning C4244: 'argument': conversion from 'std::chrono::system_clock::rep' to 'unsigned int', possible loss of data

static int* genSortedLast(int size)
{
	int *arr = new int[size];
	for (int i = 0; i < size-1; i++)
	{
		arr[i] = i;
	}

	std::default_random_engine generator(
		std::chrono::system_clock::now().time_since_epoch().count());
	std::uniform_int_distribution<int> distribution(0, INT_MAX);
	arr[size-1] = distribution(generator);

	return arr;
}
