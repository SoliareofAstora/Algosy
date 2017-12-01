#pragma once
#include "Closest_Pair.cpp"
#include <iostream>
#include <iomanip>

class Assigment6
{
public:
	static Assigment6 &instance() { static Assigment6 as6; return as6; };
	void RunAll()
	{
		PierwszeZadanie();
		system("PAUSE");
	}
	Assigment6(){};
	~Assigment6(){};
};

