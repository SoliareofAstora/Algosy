#pragma once
#include "avl.h"


template  <typename K, typename T>
struct mapElement
{
	std::pair<K, T> value;
	mapElement() = default;
	mapElement(std::pair<K, T>& p) :value(p) {}
	mapElement(K& k, T& v) :value(k, v) {}
	bool operator == (const mapElement& right) const;
	bool operator > (const mapElement& right) const;
	bool operator < (const mapElement& right) const;
};

template  <typename K, typename T>
class map
{


	avl<mapElement<K, T>> tree_;
public:
	void insert(K& key, T& value);
	mapElement<K, T>* find(K& key);
	void remove(K& key);

	class iterator
	{
		mapElement<K, T>* current_;
	public:
		iterator();
		iterator(mapElement<K, T>* element);
		bool operator ==(const iterator& i);;
		bool operator !=(const iterator& i);
		iterator& operator++();
		iterator operator ++(int);
		T& operator*();
	};
	iterator begin();
	iterator end();
};


template <typename K, typename T>
bool mapElement<K, T>::operator==(const mapElement<K, T>& right) const
{
	return value.first == right.value.first;
}

template <typename K, typename T>
bool mapElement<K, T>::operator>(const mapElement<K, T>& right) const
{
	return value.first > right.value.first ? true : false;
}


template <typename K, typename T>
bool mapElement<K, T>::operator<(const mapElement<K, T>& right) const
{
	return value.first < right.value.first;
}

template <typename K, typename T>
void map<K, T>::insert(K& key, T& value)
{
	if (find(key) == nullptr)
		tree_.insert(mapElement<K,T>(key, value));
}

template <typename K, typename T>
typename mapElement<K, T>* map<K, T>::find(K& key)
{
	mapElement<K, T> temp = mapElement<K, T>();
	temp.value.first = key;
	return &tree_.find(temp)->value;
}

template <typename K, typename T>
void map<K, T>::remove(K& key)
{
	mapElement<K, T> temp = mapElement<K, T>();
	temp.value.first = key;
	tree_.remove(temp);
}



template <typename K, typename T>
map<K, T>::iterator::iterator()
{
}

template <typename K, typename T>
map<K, T>::iterator::iterator(mapElement<K, T>* node):current_(node)
{
}

template <typename K, typename T>
bool map<K, T>::iterator::operator==(const iterator& i)
{
	return i.current_ == current_;
}

template <typename K, typename T>
bool map<K, T>::iterator::operator!=(const iterator& i)
{
	return i.current_ != current_;
}

template <typename K, typename T>
typename map<K, T>::iterator& map<K, T>::iterator::operator++()
{
	return *this;
}

template <typename K, typename T>
typename map<K, T>::iterator map<K, T>::iterator::operator++(int step)
{
	return this;
}

template <typename K, typename T>
T& map<K, T>::iterator::operator*()
{
	return current_->value.second;
}


template <typename K, typename T>
typename map<K, T>::iterator map<K, T>::begin()
{
	return iterator(tree_.min_node()->value);
}

template <typename K, typename T>
typename map<K, T>::iterator map<K, T>::end()
{
	return iterator(nullptr);
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


