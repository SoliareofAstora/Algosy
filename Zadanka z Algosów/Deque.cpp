#include "Deque.h"
#include <cstdio>
#include <immintrin.h>
#include <iostream>

Deque::Deque()
{
	read = 0;
	write = 0;
}

Deque::~Deque()
{
}

void Deque::increasePointer(int& pointer)
{
	pointer++;
	if (pointer==sizeof arr /4)
	{
		pointer = 0;
	}
}

void Deque::decreasePointer(int& pointer)
{
	pointer--;
	if (pointer == -1)
	{
		pointer = sizeof arr / 4 - 1;
	}
}

int Deque::getIncreasedPointer(int& pointer)
{
	int temp = pointer;
	increasePointer(temp);
	return temp;
}

int Deque::getDecreasedPointer(int& pointer)
{
	int temp = pointer;
	decreasePointer(temp);
	return temp;
}

void Deque::push_front(int value)
{
	if (empty())
	{
		push_back(value);
	}
	else 
	{
		if (full())
		{
			std::cerr << "Out of space Deque push_front " << value << std::endl;
		}
		else 
		{
			decreasePointer(read);
			arr[read] = value;
		}
	}

}

int Deque::pop_front()
{
	if (!empty())
	{
		int temp = arr[read];
		increasePointer(read);
		return	temp;
	}
	std::cerr <<"Deque is empty pop_front()" <<std::endl;
	return -1;
}

int& Deque::front()
{
	return arr[read];
}

void Deque::push_back(int value)
{
	if (!full())
	{
		arr[write] = value;
		increasePointer(write);
	}
	else
	{
		std::cerr << "Deque is full push_back "<< value<<std::endl;
	}
}

int Deque::pop_back()
{
	if (!empty())
	{
		decreasePointer(write);
		return arr[write];
	}
	std::cout << "Deque is empty pop_back()" << std::endl;
	return -1;
}

int& Deque::back()
{
	if (empty())
	{
		return arr[write];
	}
	return arr[getDecreasedPointer(write)];
}

int Deque::size()
{
	if (write > read)
	{
		return write - read;
	}
	return write + (sizeof arr / 4 - read);
}

bool Deque::empty()
{
	return read == write;
}

bool Deque::full()
{
	increasePointer(write);
	bool temp = empty();
	decreasePointer(write);
	return temp;
}