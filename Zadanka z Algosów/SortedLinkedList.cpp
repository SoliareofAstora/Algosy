#include "SortedLinkedList.h"
#include <codecvt>
#include <iostream>

template class SortedLinkedList<int>;

template <typename T>
SortedLinkedList<T>::SortedLinkedList()
{
	head = new node;
	head->next = head->prev = head;
}

template <typename T>
SortedLinkedList<T>::~SortedLinkedList()
{
}

template <typename T>
void SortedLinkedList<T>::push(T value)
{
	node* next = head->next;
	{
		while (next != head && next->value < value)
		{
			next = next->next;
		}
		if (next == head)
		{
			push_back(value);
		}
		else {
			if (next->prev == head)
			{
				push_front(value);
			}
			else {
				node *temp = new node;
				temp->value = value;
				temp->next = next;
				temp->prev = next->prev;
				next->prev = temp;
				temp->prev->next = temp;
			}
		}
	}
}

template <typename T>
void SortedLinkedList<T>::push_front(T value)
{
	node *temp = new node;
	temp->value = value;
	temp->next = head->next;
	temp->prev = head;
	temp->next->prev = temp;
	temp->prev->next = temp;
}

template <typename T>
T SortedLinkedList<T>::pop  ()const
{
	node *temp = head->next;
	temp->prev->next = temp->next;
	temp->next->prev = temp->prev;
	int value = temp->value;
	delete temp;
	return value;
}

template <typename T>
void SortedLinkedList<T>::push_back(T value)
{
	node *temp = new node;
	temp->value = value;
	temp->next = head;
	temp->prev = head->prev;
	temp->next->prev = temp;
	temp->prev->next = temp;
}

template <typename T>
T SortedLinkedList<T>::pop_back() 
{
	node *temp = head->prev;
	temp->prev->next = temp->next;
	temp->next->prev = temp->prev;
	int value = temp->value;
	delete temp;
	return value;
}

template <typename T>
int SortedLinkedList<T>::find(T value)
{
	node* temp = head->next;
	int result = 0;
	while (true)
	{
		if (temp->value == value)
		{
			result++;
		}
		temp = temp->next;
		if (temp == head || temp->value > value)
		{
			break;
		}
	}
	return result;
}

template <typename T>
int SortedLinkedList<T>::size() const
{
	int size = 0;
	node *current = head->next;
	while (current != head)
	{
		size++;
		current = current->next;
	} 
	return size;
}

template <typename T>
void SortedLinkedList<T>::print()
{
	node *current = head->next;
	while (current != head)
	{
		std::cerr << current->value<<" " ;	
		current = current->next;
	}
	std::cerr << std::endl;
}

template <typename T>
T SortedLinkedList<T>::getValue(int i)
{
	node *temp = head->next;
	int x = 0;
	do
	{
		if (x == i)
		{
			return temp->value;
		}
		temp = temp->next;
		x++;
	} while (temp != nullptr);
	return -1;
}

template <typename T>
void SortedLinkedList<T>::unique()
{
	node* next= head->next;
	while (next != head )
	{
		if (next->value==next->next->value)
		{
			next->next= next->next->next;
			next->next->next->prev = next;
		}
		else 
		{
			next = next->next;
		}
	}
}

template <typename T>
T SortedLinkedList<T>::erase(int i)
{
	node *temp = head->next;
	int x = 0;
	do
	{
		if (x == i)
		{
			int a = temp->value;
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
			return a;
		}
		temp = temp->next;
		x++;
	} while (temp != nullptr);
	return -1;
}

template <typename T>
void SortedLinkedList<T>::remove(T value)
{
	node* next = head->next;
	while (true)
	{
		if (next->value == value)
		{
			next->prev->next = next->next;
			next->next->prev = next->prev;
		}

		next = next->next;
		
		if (next == head || next->value > value)
		{
			break;
		}
	}
}

template <typename T>
SortedLinkedList<T> SortedLinkedList<T>::merge(const SortedLinkedList& a, SortedLinkedList& b)
{
	SortedLinkedList output;
	int sizea = a.size();
	int sizeb = b.size();
	int tempa = a.pop();
	int tempb = b.pop();

	std::cerr <<"length of arrays " <<sizea << " + "<<sizeb<<" = ";
	while(true)
	{
		if (tempa>tempb)
		{
			if (sizeb>0)
			{
				output.push_back(tempb);
				sizeb--;
				tempb = b.pop();
			}
			else
			{
				tempb = INT_MAX;
			}
		}
		else
		{
			if(sizea>0)
			{
				output.push_back(tempa);
				sizea--;
				tempa = a.pop();
			}
			else
			{
				tempa = INT_MAX;
			}
		}
		if (sizea==0&&sizeb==0)
		{
			break;
		}
	}
	std::cerr << output.size()<<std::endl;
	return output;
}



