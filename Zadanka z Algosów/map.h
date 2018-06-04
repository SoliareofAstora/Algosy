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

	typedef typename avl<mapElement<K, T>>::iterator iterator;
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
	return value.first > right.value.first;
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
mapElement<K, T>* map<K, T>::find(K& key)
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
typename map<K, T>::iterator map<K, T>::begin()
{
	return tree_.begin();
}

template <typename K, typename T>
typename map<K, T>::iterator map<K, T>::end()
{
	return tree_.end();
}


