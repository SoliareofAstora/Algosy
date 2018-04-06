#pragma once
#include "AVL.h"
template<typename T>
class Set
{
	avl<T> tree;

	Set();
	Set(const Set& source);
	Set& operator=(const Set &source);
	Set(Set &&source);
	Set & operator = (Set &&source);

private:
	BST<T> bst;

public:
	//lista inicjalizacyjna
	//	zwraca adres elementu kt�ry zosta� dodany
	T * insert(const T &value); //const referencja - przekazuje wska�nik do biektu zamiast go kopiowa� !!
	const T* find(const T &value) const; //Przekazywanie argument�w do funkcji za pomoc� const referencji 
	T* find(const T &value);
	bool remove(const T &value);

public:
	class iterator {
		////
	};
	iterator begin();
	iterator end();
};
template <typename T>
Set<T>::Set()
{
}

template <typename T>
Set<T>::Set(const Set& source)
{
}

template <typename T>
Set<T>& Set<T>::operator=(const Set& source)
{
}

template <typename T>
Set<T>::Set(Set&& source)
{
}

template <typename T>
Set<T>& Set<T>::operator=(Set&& source)
{
}

template <typename T>
T* Set<T>::insert(const T& value)
{
}

template <typename T>
const T* Set<T>::find(const T& value) const
{
}

template <typename T>
T* Set<T>::find(const T& value)
{
}

template <typename T>
bool Set<T>::remove(const T& value)
{
}

template <typename T>
typename Set<T>::iterator Set<T>::begin()
{
}

template <typename T>
typename Set<T>::iterator Set<T>::end()
{
}






/*
 *template<typename T>
 *korzysta� z unique pointer do node
 *public: 
 * Set();
 * Set(const Set& source);
 * Set& operator=(const Set &source);
 * Set(Set &&source):
 * Set& operator = (Set &&source):
 * 
 *private:
 *	 BST<T> bst;
 *	 
 *	 public:
 *		lista inicjalizacyjna
 *		zwraca adres elementu kt�ry zosta� dodany 
 *		T* insert(const T &value) //const referencja - przekazuje wska�nik do biektu zamiast go kopiowa� !!
 *		const T* find(const T &value) const; //Przekazywanie argument�w do funkcji za pomoc� const referencji 
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

