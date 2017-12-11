/* 
 * 2017 (C) Andrzej Görlich
 * Compilation: g++ -std=c++11 -O2 -o genRandom.x genRandom.cpp
 */

#pragma warning (disable : 4244)
#include <random>
#include <chrono>

static int* genRandom(int size)
{
	int *arr = new int[size];
	
	std::default_random_engine generator(
		std::chrono::system_clock::now().time_since_epoch().count());
	std::uniform_int_distribution<int> distribution(0, 20);

	for (int i = 0; i < size; i++)
	{
		arr[i] = distribution(generator);
	}
	return arr;
}
