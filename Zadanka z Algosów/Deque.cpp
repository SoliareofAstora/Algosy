#include "deque.h"
#include <cstdio>
#include <immintrin.h>
#include <iostream>
template<typename T>
deque<typename T>::deque()
{
	 read = 0;
	 write = 0;
}

template<typename T>
deque<typename T>::~deque() 
{
}

template<typename T>
void deque<typename T>::increasePointer(int& pointer)
{
	pointer++;
	if (pointer==sizeof arr /4)
	{
		pointer = 0;
	}
}

template<typename T>
void deque<typename T>::decreasePointer(int& pointer)
{
	pointer--;
	if (pointer == -1)
	{
		pointer = sizeof arr / 4 - 1;
	}
}

template<typename T>
int deque<typename T>::getIncreasedPointer(int& pointer)
{
	int temp = pointer;
	increasePointer(temp);
	return temp;
}

template<typename T>
int deque<typename T>::getDecreasedPointer(int& pointer)
{
	int temp = pointer;
	decreasePointer(temp);
	return temp;
}

template<typename T>
void deque<typename T>::push_front(T value)
{
	if (empty())
	{
		push_back(value);
	}
	else 
	{
		if (full())
		{
			std::cerr << "Out of space deque push_front " << value << std::endl;
			std::out_of_range("push_front");
		}
		else 
		{
			decreasePointer(read);
			arr[read] = value;
		}
	}

}

template<typename T>
T deque<typename T>::pop_front()
{
	if (!empty())
	{
		int temp = arr[read];
		increasePointer(read);
		return	temp;
	}
	std::cerr <<"deque is empty pop_front()" <<std::endl;
	std::out_of_range("pop_front");
	return -1;
}

template<typename T>
T& deque<typename T>::front()
{
	return arr[read];
}

template<typename T>
void deque<typename T>::push_back(T value)
{
	if (!full())
	{
		arr[write] = value;
		increasePointer(write);
	}
	else
	{
		std::cerr << "deque is full push_back "<< value<<std::endl;
		std::out_of_range("push_back");
	}
}

template<typename T>
T deque<typename T>::pop_back()
{
	if (!empty())
	{
		decreasePointer(write);
		return arr[write];
	}
	std::cout << "deque is empty pop_back()" << std::endl;
	std::out_of_range("pop_back");
	return -1;
}

template<typename T>
T& deque<typename T>::back()
{
	if (empty())
	{
		return arr[write];
	}
	return arr[getDecreasedPointer(write)];
}
template<typename T>
int deque<typename T>::size()
{
	if (empty())
	{
		return 0;
	}
	if (write > read)
	{
		return write - read;
	}
	return write + (sizeof arr / 4 - read);
}

template<typename T>
bool deque<typename T>::empty()
{
	return read == write;
}
template<typename T>
bool deque<typename T>::full()
{
	increasePointer(write);
	bool temp = empty();
	decreasePointer(write);
	return temp;
}

template class deque<int>;
