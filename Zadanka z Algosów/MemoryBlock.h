#pragma once
#include <vector>
#include <bitset>
#include <algorithm>

template <typename T>
class MemoryBlock
{
	static const int N = 64;
	int firstFree = 0;
	std::vector<std::pair<char *, std::bitset<N>>> array_;
	static std::pair<size_t, size_t> get_2D_index(int i);
	void find_next_empty();

	std::pair<char *, std::bitset<MemoryBlock<T>::N>>* extend_array();
	std::pair<char *, std::bitset<MemoryBlock<T>::N>>* allocate_row(size_t i_first, bool erase);
	void erase_row(size_t i_first);
	void erase(std::pair<size_t, size_t> i);
public:

	std::pair<char*,int> allocate();
	T* get_value(int index);
	void erase(size_t index);
	T* operator[](int index);
};

template <typename T>
std::pair<size_t, size_t> MemoryBlock<T>::get_2D_index(int i)
{
	std::pair<size_t, size_t> out;
	out.second = i % N;
	out.first = (i - out.second)/N;
	
	return out;
}

template <typename T>
void MemoryBlock<T>::find_next_empty()
{
	std::pair<size_t, size_t> i = get_2D_index(firstFree);
	while (array_[i.first].second[i.second])
	{
		firstFree++;
		i = get_2D_index(firstFree);
		if (i.first >= array_.size())
		{
			extend_array();
		}
		if (array_[i.first].first == nullptr)
		{
			allocate_row(i.first, false);
		}
	}
}

template <typename T>
std::pair<char*, std::bitset<MemoryBlock<T>::N>>* MemoryBlock<T>::extend_array()
{
	array_.push_back(
		std::pair<char *, std::bitset<N>>(
			new char[sizeof(T) * N],
			std::bitset<N>())
	);
	return &array_.back();
}

template <typename T>
 std::pair<char*, std::bitset<MemoryBlock<T>::N>>* MemoryBlock<T>::allocate_row(size_t i_first, bool erase)
{
	if (erase)
	{
		erase_row(i_first);
	}

	if (array_[i_first].first == nullptr)
	{
		array_[i_first] = std::pair<char *, std::bitset<N>>(
			new char[sizeof(T) * N],
			std::bitset<N>()
		);
	}

	return &array_[i_first];
}

template <typename T>
void MemoryBlock<T>::erase_row(size_t i_first)
{
	if (array_[i_first].first == nullptr)
	{
		return;
	}

	for (int i = 0; i < N; i++)
	{
		T* prt = reinterpret_cast<T*>(array_[i_first].first + sizeof(T) * i);
		if (prt != nullptr)
		{
			prt->~T();
		}
		
	}
	delete[] array_[i_first].first;
}

template <typename T>
void MemoryBlock<T>::erase(std::pair<size_t, size_t> i)
{
	erase(i.first*N + i.second);
}

template <typename T>
void MemoryBlock<T>::erase(size_t index)
{
	firstFree = std::min(index, firstFree);
	const auto i = get_2D_index(index);
	if (array_[i.first].second[i.second])
		reinterpret_cast<T*>(array_[i.first].first + sizeof(T) * i.second)->~T();
}

template <typename T>
T* MemoryBlock<T>::operator[](int index)
{
	return get_value(index);
}


template <typename T>
std::pair<char*, int> MemoryBlock<T>::allocate()
{
	if (firstFree==-1)
	{
		//Out of space in this particular block
		return std::pair<char*, int>(nullptr,-1);
	}
	const auto i = get_2D_index(firstFree);
	if (i.first >= array_.size())
	{
		extend_array();
	}

	auto tmp = std::pair<char*, int>(array_[i.first].first + sizeof(T) * i.second, firstFree);
	array_[i.first].second[i.second] = true;	
	find_next_empty();
	return tmp;
}

template <typename T>
T* MemoryBlock<T>::get_value(int index)
{
	if (index==-1)
	{
		return nullptr;
	}
	const auto i = get_2D_index(index);
	return reinterpret_cast<T*>(array_[i.first].first + sizeof(T) * i.second);
}


//Pink Panter
//todo todo 
//todo
//todo todo todo todo todoooooo