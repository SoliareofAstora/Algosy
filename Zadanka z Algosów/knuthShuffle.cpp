#include <iterator>
#include <random>
#include <chrono>
template<typename RandomAccessIterator>
void knuthShuffle(RandomAccessIterator begin, RandomAccessIterator end) {
	for (unsigned int n = end - begin - 1; n >= 1; --n) {
		std::default_random_engine generator(
			std::chrono::system_clock::now().time_since_epoch().count());
		std::uniform_int_distribution<int> distribution(0, INT_MAX);
		unsigned int k = distribution(generator) / (INT_MAX/(n + 1));
		if (k != n) {
			std::iter_swap(begin + k, begin + n);
		}
	}
}