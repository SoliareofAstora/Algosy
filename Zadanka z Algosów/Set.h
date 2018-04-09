#pragma once
#include "avl.h"

template<typename T>
class set
{
	avl<T> tree_;

	set();
	set(const set& source);
	set& operator=(const set &source);
	set(set &&source) noexcept;
	set & operator = (set &&source) noexcept;

public:
	//lista inicjalizacyjna
	//	zwraca adres elementu który zosta³ dodany
	void insert(const T &value); //const referencja - przekazuje wskaŸnik do biektu zamiast go kopiowaæ !!
	const T* find(const T &value) const; //Przekazywanie argumentów do funkcji za pomoc¹ const referencji 
	T* find(const T &value);
	void remove(const T &value);

	class iterator 
	{
		bool operator ==(const iterator& i);;
		bool operator !=(const iterator& i);
		iterator& operator++();
		iterator operator ++(int);
		T& operator*();

	};
	iterator begin();
	iterator end();
};
template <typename T>
set<T>::set()
{
}

template <typename T>
set<T>::set(const set& source)
{
}

template <typename T>
set<T>& set<T>::operator=(const set& source)
{
}

template <typename T>
set<T>::set(set&& source) noexcept
{
}

template <typename T>
set<T>& set<T>::operator=(set&& source) noexcept
{
}

template <typename T>
void set<T>::insert(const T& value)
{
	tree_.insert(value);
}

template <typename T>
const T* set<T>::find(const T& value) const
{
	return tree_.find(value);
}

template <typename T>
T* set<T>::find(const T& value)
{
	return tree_.find(value);
}

template <typename T>
void set<T>::remove(const T& value)
{
	tree_.remove(value);
}

template <typename T>
bool set<T>::iterator::operator==(const iterator& i)
{
	return this == i;
}

template <typename T>
bool set<T>::iterator::operator!=(const iterator& i)
{
	return !(this == i);
}

template <typename T>
typename set<T>::iterator& set<T>::iterator::operator++()
{
}

template <typename T>
typename set<T>::iterator set<T>::iterator::operator++(int)
{
}

template <typename T>
T& set<T>::iterator::operator*()
{

}

template <typename T>
typename set<T>::iterator set<T>::begin()
{

}

template <typename T>
typename set<T>::iterator set<T>::end()
{
}






/*
*template<typename T>
*korzystaæ z unique pointer do node
*public:
* set();
* set(const set& source);
* set& operator=(const set &source);
* set(set &&source):
* set& operator = (set &&source):
*
*private:
*	 BST<T> bst;
*
*	 public:
*		lista inicjalizacyjna
*		zwraca adres elementu który zosta³ dodany
*		T* insert(const T &value) //const referencja - przekazuje wskaŸnik do biektu zamiast go kopiowaæ !!
*		const T* find(const T &value) const; //Przekazywanie argumentów do funkcji za pomoc¹ const referencji
*		T* find (const T &value)
*		bool remove(const T &value)
*
*	public:
*		class iterator{
*			...
*		}
*		iterator begin()
*		iterator end()
*
*
*
*
*/

#pragma once
