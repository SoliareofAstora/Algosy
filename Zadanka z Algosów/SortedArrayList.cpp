#include <iostream>
#include <algorithm>
#include "SortedArrayList.h"


SortedArrayList::SortedArrayList()
{
	firstFree = 0;
	for (int i = 0; i < sizeof tab / 4; i++)
	{
		tab[i] = INT_MAX;
	}
}

SortedArrayList::~SortedArrayList()
{
}


int SortedArrayList::pop()
{
	return erase(0);
}

void SortedArrayList::push(int value)
{
	if (sizeof tab / 4 > firstFree + 1)
	{
		int temp = value;
		firstFree++;
		for (int i = 0; i < firstFree; i++)
		{
			if (tab[i] > temp)
			{
				std::swap(temp, tab[i]);
			}
		}
	}
	else
	{
		std::cerr << "NOPE! push Out of range exception" << std::endl;;
	}
}

void SortedArrayList::pushSorted(int value)
{
	if (sizeof tab / 4 > firstFree)
	{
		tab[firstFree] = value;
		firstFree++;
	}
	else
	{
		std::cerr << "NOPE! pushSorted Out of range exception" << std::endl;;
	}
}

int SortedArrayList::erase(int i)
{
	if (firstFree > 0)
	{
		if (i >= firstFree)
		{
			std::cerr << "NOPE! erase index too high" << std::endl;;
			return -1;
		}
		firstFree--;
		int temp = tab[i];
		for (int a = i; a < firstFree; a++)
		{
			tab[a] = tab[a + 1];
		}
		return temp;
	}
	std::cerr << "NOPE! erase Array is empty" << std::endl;;
	return -1;
}

int SortedArrayList::find(int value)
{
	for (int i = 0; i < firstFree; i++)
	{
		if (tab[i] == value)
		{
			return i;
		}
	}
	return -1;
}

void SortedArrayList::remove(int value)
{
	for (int i = 0; i < firstFree; i++)
	{
		if (tab[i] == value)
		{
			erase(i);
			i--;
		}
	}
}

int SortedArrayList::size() const
{
	return firstFree;
}

int SortedArrayList::getValue(int i) const
{
	if (i > firstFree)
	{
		std::cerr << "NOPE! getvalue index too high " << std::endl;;
		return INT_MAX;
	}
	return tab[i];
}

//O(2N)
SortedArrayList SortedArrayList::merge(
	const SortedArrayList& a,
	const SortedArrayList& b)
{
	SortedArrayList output;
	int outputSize = a.size() + b.size();
	std::cerr << outputSize << std::endl;
	if (outputSize > output.maxElements())
	{
		std::cerr << "ERROR! merge - too many elements" << std::endl;;
		return output;
	}
	int ai = 0;
	int bi = 0;
	int amin = a.getValue(0);
	int bmin = b.getValue(0);

	for (int i = 0; i < outputSize+1; i++)
	{
		if (amin < bmin)
		{
			//input: a

			ai++;
			if (ai > a.size())
			{
				amin = INT_MAX;
			}
			else
			{
			//	std::cerr << "a";
				output.pushSorted(amin);
				amin = a.getValue(ai);
			}

		}
		else
		{
			//input: b
			bi++;
			if (bi > b.size())
			{
				bmin = INT_MAX;
			}
			else
			{
			//	std::cerr << "b";
				output.pushSorted(bmin);
				bmin = b.getValue(bi);
			}
		}
	}
	return output;
}

void SortedArrayList::print()
{
	std::cout << std::endl;
	for (int i = 0; i < firstFree; i++)
	{
		std::cout << tab[i] << " ";// << std::endl;
	}
	std::cout << std::endl;
}

//O(N)
void SortedArrayList::unique()
{
	int distance = 1;
	for (int i=0;i<firstFree-distance;i++)
	{
		if (tab[i]==tab[i+distance])
		{
			distance++;
			i--;
		}
		else {
			tab[i + 1] = tab[i + distance];
		}
	}
	firstFree -= distance-1;
}
