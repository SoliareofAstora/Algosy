#include <iostream>
#include "stack.h"
#include <algorithm>


static int getMaxArea(int *histogram, int n)
{
	stack<int> s;
	int max_area = -1;
	int tp;
	int area_with_top;

	int i = 0;
	while (i < n)
	{
		if (s.empty() || histogram[s.top()] <= histogram[i])
			s.push(i++);
		else
		{
			tp = s.pop();
			area_with_top = histogram[tp] * (s.empty() ? i : i - s.top() - 1);

			max_area = std::max(area_with_top, max_area);
		}
	}

	while (s.empty() == false)
	{
		tp = s.pop();
		area_with_top = histogram[tp] * (s.empty() ? i : i - s.top() - 1);
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
	std::cerr << "Najwiêkszy prostok¹t to: " << result;
}
