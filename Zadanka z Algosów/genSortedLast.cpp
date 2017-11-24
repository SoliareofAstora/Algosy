#pragma warning (disable : 4244)
#include <random>
#include <chrono>

static int* genSortedLast(int size)
{
	int *arr = new int[size];
	for (int i = 0; i < size; i++)
	{
		arr[i] = i;
	}

	std::default_random_engine generator(
		std::chrono::system_clock::now().time_since_epoch().count());
	std::uniform_int_distribution<int> distribution(0, size);
	arr[size - 1] = distribution(generator);

	return arr;
}