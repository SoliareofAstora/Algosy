#include "queue.h"



queue::queue()
{
}


queue::~queue()
{
}

void queue::enqueue(int x)
{
	push_back(x);
}

int queue::dequeue()
{
	return pop_front();
}

int& queue::peek()
{
	return front();
}

int queue::size()
{
	return deque::size();
}

bool queue::empty()
{
	return deque::empty();
}
