#pragma once
#include <chrono>

class Stopwatch
{
	std::chrono::time_point<std::chrono::high_resolution_clock> start;
public:
	void startCounting() {
		start = std::chrono::high_resolution_clock::now();
	}

	std::chrono::duration<double> stopCounting(){
		auto end = std::chrono::high_resolution_clock::now();
		 return end - start;
	}
};
