#pragma once
#include "Closest_Pair.cpp"
#include "PermutationCount.cpp"
#include <iostream>
#include <iomanip>

class Assigment6
{
public:
	static Assigment6 &instance() { static Assigment6 as6; return as6; };
	void RunAll()
	{
		std::cerr << "ClosestPair\n";
		//PierwszeZadanie();
		std::cerr << "\nPermutation Count\n";
		DrugieZadanie();


		system("PAUSE");
	}
	Assigment6(){};
	~Assigment6(){};
};

