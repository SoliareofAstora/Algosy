#pragma warning (disable : 4244)
#include <random>
#include <chrono>

template<typename T>
static T* genSquare(int size) {
	T *arr = new T[size];

	std::default_random_engine generator(
		std::chrono::system_clock::now().time_since_epoch().count());
	std::uniform_real_distribution<double> distribution(0,1);

	//TODO distribution double
	for (int i = 0; i < size; i++)
	{
		arr[i].x = static_cast<float>(distribution(generator));
		arr[i].y = static_cast<float>(distribution(generator));
	}
	return arr;
}
