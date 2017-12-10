#include <iostream>
#include "stack.h"
#include <algorithm>


static int getMaxArea(int *hist, int n)
{
	// Create an empty stack. The stack holds indexes of hist[] array
	// The bars stored in stack are always in increasing order of their
	// heights.
	stack<int> s;

	int max_area = -1; // Initalize max area
	int tp;  // To store top of stack
	int area_with_top; // To store area with top bar as the smallest bar

					   // Run through all bars of given histogram
	int i = 0;
	while (i < n)
	{
		// If this bar is higher than the bar on top stack, push it to stack
		if (s.empty() || hist[s.top()] <= hist[i])
			s.push(i++);

		// If this bar is lower than top of stack, then calculate area of rectangle 
		// with stack top as the smallest (or minimum height) bar. 'i' is 
		// 'right index' for the top and element before top in stack is 'left index'
		else
		{
			tp = s.pop();  // store the top index
			  // pop the top

					  // Calculate the area with hist[tp] stack as smallest bar
			area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1);

			// update max area, if needed
			max_area = std::max(area_with_top, max_area);
		}
	}

	// Now pop the remaining bars from stack and calculate area with every
	// popped bar as the smallest bar
	while (s.empty() == false)
	{
		tp = s.pop();
		area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1);
		max_area = std::max(area_with_top, max_area);
	}

	return max_area;
}

static void TrzecieZadanie()
{
	//read from file;
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

	//create histograms
	int *singlerow = new int[y];
	stack<int*> histogram;
	for (int j = 0; j<y; j++)
	{
		singlerow[j] = arr[0][j];
	}
	histogram.push(singlerow);
	for (int i =1; i<x; i++)
	{
		singlerow = new int[y];
		int *prevrow = histogram.top();
		for (int j =0;j<y;j++)
		{
			if (arr[i][j]==0)
			{
				singlerow[j] = 0;
			}
			else
			{
				singlerow[j] = prevrow[j] + 1;
			}
		}
		histogram.push(singlerow);
	}
	//calculate biggest rectangle
	int result = -1;
	while(!histogram.empty())
	{
		result = std::max(result, getMaxArea(histogram.pop(), y));
	}
	std::cerr << "Najlepsze rozwiazanie to: " << result;
}
