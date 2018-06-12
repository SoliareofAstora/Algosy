#pragma once
#include <vector>
#include <bitset>

template <typename T>
class MemoryBlock
{

	static const int N = 64;
	int firstFree = 0;
	std::vector<std::pair<char *, std::bitset<N>>> array_;
	std::pair<size_t, size_t> get_2D_index(int i);
	void find_next_empty();

public:
	std::pair<char *, std::bitset<N>>* extend_array()
	{
		//TODO nie wiem dlaczego to nie chce wskoczyæ poza classscope 
//Error	C2244	'MemoryBlock<T>::extend_array': unable to match function definition to an existing declaration
		array_.push_back(
			std::pair<char *, std::bitset<N>>(
				new char[sizeof(T) * N],
				std::bitset<N>())
		);
		return &array_.back();
	}
	std::pair<char*,int> alloc();
	T* get_value(int index);
};

template <typename T>
std::pair<size_t, size_t> MemoryBlock<T>::get_2D_index(int i)
{
	std::pair<size_t, size_t> out;
	out.first = i % N;
	out.second = i - N * out.first;
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
	}
}

/*//Error	C2244	'MemoryBlock<T>::extend_array': unable to match function definition to an existing declaration
template <typename T>
std::pair<char*, std::bitset<MemoryBlock<T>::N>>* MemoryBlock<T>::extend_array()
{
	//TODO nie wiem dlaczego to nie chce wskoczyæ poza classscope 

	array_.push_back(
		std::pair<char *, std::bitset<N>>(
			new char[sizeof(T) * N],
			std::bitset<N>())
	);
	return &array_.back();
}*/


template <typename T>
std::pair<char*, int> MemoryBlock<T>::alloc()
{
	if (firstFree==-1)
	{
		//Out of space in this particular block
		return std::pair<char*, int>(nullptr,-1);
	}
	std::pair<size_t, size_t> i = get_2D_index(firstFree);
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
	std::pair<size_t, size_t> i = get_2D_index(index);
	return static_cast<T*>(array_[i.first].first + sizeof(T) * i.second);
}




