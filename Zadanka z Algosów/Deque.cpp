#include "deque.h"
#include <cstdio>
#include <immintrin.h>
#include <iostream>

deque::deque()
{
	read = 0;
	write = 0;
}

deque::~deque()
{
}

void deque::increasePointer(int& pointer)
{
	pointer++;
	if (pointer==sizeof arr /4)
	{
		pointer = 0;
	}
}

void deque::decreasePointer(int& pointer)
{
	pointer--;
	if (pointer == -1)
	{
		pointer = sizeof arr / 4 - 1;
	}
}

int deque::getIncreasedPointer(int& pointer)
{
	int temp = pointer;
	increasePointer(temp);
	return temp;
}

int deque::getDecreasedPointer(int& pointer)
{
	int temp = pointer;
	decreasePointer(temp);
	return temp;
}

void deque::push_front(int value)
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
		}
		else 
		{
			decreasePointer(read);
			arr[read] = value;
		}
	}

}

int deque::pop_front()
{
	if (!empty())
	{
		int temp = arr[read];
		increasePointer(read);
		return	temp;
	}
	std::cerr <<"deque is empty pop_front()" <<std::endl;
	return -1;
}

int& deque::front()
{
	return arr[read];
}

void deque::push_back(int value)
{
	if (!full())
	{
		arr[write] = value;
		increasePointer(write);
	}
	else
	{
		std::cerr << "deque is full push_back "<< value<<std::endl;
	}
}

int deque::pop_back()
{
	if (!empty())
	{
		decreasePointer(write);
		return arr[write];
	}
	std::cout << "deque is empty pop_back()" << std::endl;
	return -1;
}

int& deque::back()
{
	if (empty())
	{
		return arr[write];
	}
	return arr[getDecreasedPointer(write)];
}

int deque::size()
{
	if (write > read)
	{
		return write - read;
	}
	return write + (sizeof arr / 4 - read);
}

bool deque::empty()
{
	return read == write;
}

bool deque::full()
{
	increasePointer(write);
	bool temp = empty();
	decreasePointer(write);
	return temp;
}