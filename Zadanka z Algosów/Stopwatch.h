#pragma once
#include <chrono>

class Stopwatch
{
	std::chrono::time_point<std::chrono::high_resolution_clock> start;
public:
	void startCounting() {
		start = std::chrono::high_resolution_clock::now();
	}

	double stopCounting() const
	{
		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double, std::milli> output = end - start;
		return output.count();
	}
};
