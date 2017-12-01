#pragma warning (disable : 4244)
#include <random>
#include <chrono>

template<typename T>
static T* genSquare(int size) {
	T *arr = new T[size];

	std::default_random_engine generator(
		std::chrono::system_clock::now().time_since_epoch().count());
	std::uniform_int_distribution<int> distribution(1, INT_MAX-2);

	for (int i = 0; i < size; i++)
	{
		arr[i].x = (float)distribution(generator)/(float) INT_MAX;
		arr[i].y = (float)distribution(generator) / (float)INT_MAX;
	}
	return arr;
}
