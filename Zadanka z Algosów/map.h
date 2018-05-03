#pragma once
#include "avl.h"
#include <utility>

template  <typename K, typename T>
class map
{
	struct dataElement
	{
		std::pair<K, T> value;
		dataElement() = default;
		dataElement(std::pair<K, T> v):value(v){}
		dataElement(K k, T v) :value(std::pair<K, T>(k,v)) {}
		dataElement(K k)
		{
			value.first = k;
		}
		bool operator == (dataElement& right) const;
		bool operator > (dataElement& right) const;
		bool operator < (dataElement& right) const;
	};

	avl<dataElement> tree;
public:
	void insert(K key,T value)
	{
		tree.insert(dataElement(key, value));

	}

	T find(K key)
	{
		auto temp = dataElement(key);
		return tree.find(temp)->value.value.second;
	}


};


template <typename K, typename T>
bool map<K, T>::dataElement::operator==(dataElement& right) const
{
	return value.first == right.value.first ?  true :  false;
}

template <typename K, typename T>
bool map<K, T>::dataElement::operator>(dataElement& right) const
{
	return value.first > right.value.first ? true : false;
}


template <typename K, typename T>
bool map<K, T>::dataElement::operator<(dataElement& right) const
{
	return value.first < right.value.first ? true : false;
}



/*Hej!

Opisz� Ci, co straci�e� : generalnie na pocz�tku opowiada� o s�owniku
(po ang.map).Wiadomo, elementy s� przechowywane jako pary klucza i warto�ci, 
a szuka si� po kluczach, kt�re musz� by� unikatowe.

Na zad.dom.kt�re liczy si� do kolokwium mamy na max.za 
2 tyg.zaimplementowa� tak� map� na naszym drzewie BST, 
kt�re robili�my do zbioru.Mo�na skorzysta� z 
std::pair do tworzenia element�w.Najlepiej �eby to by�o to samo drzewo 
z iteratorami i chodzi o to by jak najmniej zmienia� funkcje z tego drzewa.
Jako przyk�ad zastanawiali�my si�, jak zrobi� Find'a bez zmiany funkcji z BST: 
Trzeba upakowa� par� w klas� i przeci��y� operator por�wnania :
	class TreeData {
	std::pair<K, V> p;
	bool operator==(const TreeData & td) {
		return p.first == td.first;
	}
};

Jakby co� by�o niejasne to pisz : )
Pozdrawiam,
Kasia*/


