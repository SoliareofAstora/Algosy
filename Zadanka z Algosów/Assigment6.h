#pragma once
class Assigment6
{
public:
	static Assigment6 &instance() { static Assigment6 as6; return as6; };
	void run();
	Assigment6(){};
	~Assigment6();
};

