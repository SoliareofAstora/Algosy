#pragma warning (disable : 4244)
#include <random>
#include <chrono>

static int* genSortedLast(int size)
{
	int *arr = new int[size];
	for (int i = 1; i < size; i++)
	{
		arr[i] = i;
	}

	std::default_random_engine generator(
		std::chrono::system_clock::now().time_since_epoch().count());
	std::uniform_int_distribution<int> distribution(0, INT_MAX);
	arr[0]= distribution(generator);

	return arr;
}