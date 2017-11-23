#include <iostream>
#include <algorithm>
#include "SortedArrayList.h"

template class SortedArrayList<int>;

template <typename T>
SortedArrayList<T>::SortedArrayList()
{
	firstFree = 0;
	for (int i = 0; i < sizeof tab / 4; i++)
	{
		tab[i] = INT_MAX;
	}
}

template <typename T>
SortedArrayList<T>::~SortedArrayList()
{
}

template <typename T>
T SortedArrayList<T>::pop()
{
	return erase(0);
}

template <typename T>
void SortedArrayList<T>::push(T value)
{
	if (sizeof tab / sizeof T > firstFree + 1)
	{
		//tab[firstFree] = value;
		
		for (int i = firstFree-1; i < 0; i--)
		{
			if (tab[i]>value)
			{
				tab[i + 1] = tab[i];
			}
			else
			{
				tab[i + 1] = value;
			}
		}
		firstFree++;
		
	}
	else
	{
		std::cerr << "NOPE! push Out of range exception" << std::endl;;
	}
}

template <typename T>
void SortedArrayList<T>::pushSorted(T value)
{
	if (sizeof tab / sizeof T > firstFree)
	{
		tab[firstFree] = value;
		firstFree++;
	}
	else
	{
		std::cerr << "NOPE! pushSorted Out of range exception" << std::endl;;
	}
}

template <typename T>
T SortedArrayList<T>::erase(int i)
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

template <typename T>
int SortedArrayList<T>::find(T value)
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

template <typename T>
void SortedArrayList<T>::remove(int value)
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

template <typename T>
int SortedArrayList<T>::size() const
{
	return firstFree;
}

template <typename T>
T SortedArrayList<T>::getValue(int i) const
{
	if (i > firstFree)
	{
		std::cerr << "NOPE! getvalue index too high " << std::endl;;
		return INT_MAX;
	}
	return tab[i];
}

//O(2N)
template <typename T>
SortedArrayList<T> SortedArrayList<T>::merge(
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

template <typename T>
void SortedArrayList<T>::print()
{
	for (int i = 0; i < firstFree; i++)
	{
		std::cout << tab[i] << " ";// << std::endl;
	}
	std::cout << std::endl;
}

//O(N)
template <typename T>
void SortedArrayList<T>::unique()
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
