#include <iostream>
#include "stack.h"

static void TrzecieZadanie()
{
	int x, y;
	std::cin >> x;
	std::cin >> y;
	int **arr= new int*[x];
	for (size_t i = 0; i < x; i++)
	{
		arr[i] = new int[y];
	}
	for (size_t i = 0; i < x; i++)
	{
		for (size_t j = 0; j < y; j++)
		{
			std::cin >> arr[i][j];
		}
	}
	for (size_t i = 0; i < x; i++)
	{
		for (size_t j = 0; j < y; j++)
		{
			std::cerr << arr[i][j] << " ";
		}
		std::cerr << std::endl;
	}
	std::cerr << std::endl;
	//Finished file reading; 
	int *onerow = new int[y];
	stack<int*> histograms;
	for (int j = 0; j<y; j++)
	{
		onerow[j] = arr[0][j];
	}
	histograms.push(onerow);
	for (int i =1; i<x; i++)
	{
		onerow = new int[y];
		int *prevrow = histograms.top();
		for (int j =0;j<y;j++)
		{
			if (arr[i][j]==0)
			{
				onerow[j] = 0;
			}
			else
			{
				onerow[j] = prevrow[j] + 1;
			}
		}
		histograms.push(onerow);
	}
	while(!histograms.empty())
	{
		int *prevrow = histograms.pop();
		for (int i=0;i<y;i++)
		{
			std::cerr << prevrow[i]<<" ";
		}
		std::cerr << "\n";
	}
}
