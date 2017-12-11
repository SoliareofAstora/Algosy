#include "genRandom.cpp"
#include "QuickSort.cpp"
#include <iostream>

static void FindSum()
{
	int testsize = 10;
	int* arra = genRandom(testsize);
	int* arrb = genRandom(testsize);
	QuickSort(arra, 0, testsize - 1);
	QuickSort(arrb, 0, testsize - 1);

	int summax = 30;


	for (int i = 0; i <= testsize; i++)
	{
		std::cerr << arra[i] << " ";
	}
	std::cerr << "\n";
	for (int i = 0; i < testsize; i++)
	{
		std::cerr << arrb[i] << " ";
	}
	std::cerr << "\n";
	
	for (int sum = 0; sum<summax;sum++)
	{
		int a = 0;
		int b = 0;
		//Go with A index to the end or the value higher than it should be
		while (a+1 < testsize)
		{
			if (arra[a]+arrb[b]<sum)
			{
				a++;
			}
			else
			{
				break;
			}
		}
		while (true)
		{
			if (arra[a] + arrb[b] == sum)
			{
				std::cerr << sum << " = " << arra[a] << " + " << arrb[b] << "\n";
				break;
			}
			if (arra[a] + arrb[b] > sum || b == testsize - 1)
			{
				if (a == 0 || arra[a] + arrb[b]<sum)
				{
					std::cerr << "Sum "<<sum<<" not found\n";
					break;
				}
				a--;
			}
			else
			{
				b++;
			}
		}
	}
}
