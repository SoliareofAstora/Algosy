#include <stdlib.h>
#include <iostream>
#include <chrono>
int recurentFibonachi(int n)
{
	if (n==0)
	{
		return 0;
	}
	if (n==1)
	{
		return 1;
	}
	return recurentFibonachi(n - 1) + recurentFibonachi(n - 2);
}


int IterFibonachi(int n)
{
	
	if (n<3)
	{
		if (n==0)
		{
			return 0;
		}
		else { return 1; }
	}
	int a = 0, b = 1;
	for (int i=1;i<n;i++)
	{
		a = a + b;
		b = a - b;
	}
	return a;
}


int main()
{
	auto start = std::chrono::high_resolution_clock::now();
	int lo = recurentFibonachi(5);
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = end - start;
	std::cerr << lo << " recurentFibonachi(50) " << elapsed.count() << std::endl;

	start = std::chrono::high_resolution_clock::now();
	lo = IterFibonachi(5);
	end = std::chrono::high_resolution_clock::now();
	elapsed = end - start;
	std::cerr << lo << " IterFibonachi(50) " << elapsed.count() << std::endl;

	std::cin;
	system("PAUSE");
}