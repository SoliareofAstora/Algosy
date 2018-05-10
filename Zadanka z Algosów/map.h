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

Opiszê Ci, co straci³eœ : generalnie na pocz¹tku opowiada³ o s³owniku
(po ang.map).Wiadomo, elementy s¹ przechowywane jako pary klucza i wartoœci, 
a szuka siê po kluczach, które musz¹ byæ unikatowe.

Na zad.dom.które liczy siê do kolokwium mamy na max.za 
2 tyg.zaimplementowaæ tak¹ mapê na naszym drzewie BST, 
które robiliœmy do zbioru.Mo¿na skorzystaæ z 
std::pair do tworzenia elementów.Najlepiej ¿eby to by³o to samo drzewo 
z iteratorami i chodzi o to by jak najmniej zmieniaæ funkcje z tego drzewa.
Jako przyk³ad zastanawialiœmy siê, jak zrobiæ Find'a bez zmiany funkcji z BST: 
Trzeba upakowaæ parê w klasê i przeci¹¿yæ operator porównania :
	class TreeData {
	std::pair<K, V> p;
	bool operator==(const TreeData & td) {
		return p.first == td.first;
	}
};

Jakby coœ by³o niejasne to pisz : )
Pozdrawiam,
Kasia*/


