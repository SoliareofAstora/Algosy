#include "queue.h"


template<typename T>
queue<typename T>::queue()
{
}

template<typename T>
queue<typename T>::~queue()
{
}
template<typename T>
void queue<typename T>::enqueue(T x)
{
	push_back(x);
}
template<typename T>
int queue<typename T>::dequeue()
{
	return pop_front();
}
template<typename T>
int& queue<typename T>::peek()
{
	return front();
}
template<typename T>
int queue<typename T>::size()
{
	return deque<typename T>::size();
}
template<typename T>
bool queue<typename T>::empty()
{
	return deque<typename T>::empty();
}

template class queue<int>;
