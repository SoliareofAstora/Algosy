#pragma once
#include <vector>
#include <bitset>
#include <algorithm>
//dodaæ typedef address na std::pair<sizet,sizet>

//template <typename  T, size_t N_>
template <typename  T>
class MemoryBlock
{
	static const int N_ = 64;
	size_t firstFree_ = 0;//zamieniæ na parê 

	//zamienic miejscami 
	//vector< std:pair<std::bitset<N_> , std::uniquepointer <std::array<sizeof(T)*N_>>>>
	std::vector<std::pair<char *, std::bitset<N_>>> array_;
	static std::pair<size_t, size_t> get_2D_index(int i);
	void find_next_empty();

	std::pair<char *, std::bitset<MemoryBlock<T>::N_>>* extend_array();
	std::pair<char *, std::bitset<MemoryBlock<T>::N_>>* allocate_row(size_t i_first, bool erase);
	void erase_row(size_t i_first);
	void erase(std::pair<size_t, size_t> i);
	size_t size_ = 0;
public:
	// 3 functions to block out of vector range error. TODO make less
	bool check_if_free(int index);
	bool check_if_row_exist(int index);
	bool check_if_outOfArray(int index);

	size_t size();
	// returns pointer and index to element that should be allocated next
	std::pair<char*,int> allocate();
	T* get_value(int index) const;
	void erase(size_t index);
	void erase_all();
	T* operator[](int index) const;

	class iterator
	{
		MemoryBlock<T>* block;
		int current;
	public:
		iterator();
		iterator(MemoryBlock<T>* source, const int& current);
		bool operator ==(const iterator& i);;
		bool operator !=(const iterator& i);
		iterator& operator++();
		iterator operator ++(int);

		T& operator*()
		{	 
			return *(block->get_value(current));
		};

		void next();
	};
	iterator begin();
	iterator end();
};


//pozbyc sie 
template <typename T>
std::pair<size_t, size_t> MemoryBlock<T>::get_2D_index(int i)
{
	std::pair<size_t, size_t> out;
	out.second = i % N_;
	out.first = (i - i % N_)/N_;
	
	return out;

	//zinlajnowaæ 
	return {i%N_, i/N_};
}

//TODO branch prediction? 
/* przewiduje do którego IFA wskoczymy w tej albo w kolejnej iteracji 
 * co sie da usunac poza pêtle 
 */
template <typename T>
void MemoryBlock<T>::find_next_empty()
{
	std::pair<size_t, size_t> i = get_2D_index(firstFree_);
	while (array_[i.first].second[i.second])
	{
		firstFree_++;
		i = get_2D_index(firstFree_);
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
std::pair<char*, std::bitset<MemoryBlock<T>::N_>>* MemoryBlock<T>::extend_array()
{
	array_.push_back(
		std::pair<char *, std::bitset<N_>>(
			new char[sizeof(T) * N_],
			std::bitset<N_>())
	);
	return &array_.back();
}

//shrink to fit kasuje nulowe elementy ( zale¿y od u¿ytkownika )
template <typename T>
 std::pair<char*, std::bitset<MemoryBlock<T>::N_>>* MemoryBlock<T>::allocate_row(size_t i_first, bool erase)
{
	if (erase)
	{
		erase_row(i_first);
	}

	if (array_[i_first].first == nullptr)
	{
		array_[i_first] = std::pair<char *, std::bitset<N_>>(
			new char[sizeof(T) * N_],
			std::bitset<N_>()
		);
	}
	return &array_[i_first];
}

template <typename T>
void MemoryBlock<T>::erase_row(size_t i_first)
{
	if (array_[i_first].first != nullptr)
	{
		for (int i = 0; i < N_; i++)
		{
			//dodaæ ifa do bitsetu 
			T* prt = reinterpret_cast<T*>(array_[i_first].first + sizeof(T) * i);
			if (prt != nullptr)
			{
				prt->~T();
			}
		}
		delete[] array_[i_first].first;
	}

	auto* tmp = array_.back().first;
	while (tmp == nullptr)
	{
		array_.erase(array_.end() - 1);
		tmp = array_.back().first;
	}
}

template <typename T>
void MemoryBlock<T>::erase(std::pair<size_t, size_t> i)
{
	erase(i.first*N_ + i.second);
}

template <typename T>
void MemoryBlock<T>::erase(size_t index)
{
	const auto i = get_2D_index(index);
	if (array_[i.first].second[i.second])
	{
		firstFree_ = std::min(index, firstFree_);
		array_[i.first].second[i.second] = false;
		//plt->~T();
		size_--;
		//if bitset.any() zamist poni¿ej

		bool empty = true;
		for (int j = 0; j < N_; j++)
		{
			if (array_[i.first].second[j])
			{
				empty = false;
			}
		}
		if (empty)
		{
			erase_row(i.first);
		}
	}
}

template <typename T>
void MemoryBlock<T>::erase_all()
{
	//todo implement
}

template <typename T>
T* MemoryBlock<T>::operator[](int index) const
{
	return get_value(index);
}

template <typename T>
MemoryBlock<T>::iterator::iterator()
{
}

//TODO zamienic na konst referencje
//TODO zrobiæ osobny iterator dla enda i dla begina 
template <typename T>
MemoryBlock<T>::iterator::iterator(MemoryBlock<T>* source, const int& current) :block(source),current(current)
{
	--this->current;
	next();
}

template <typename T>
bool MemoryBlock<T>::iterator::operator==(const iterator& i)
{
	return block == i.block && current == i.current;
}

template <typename T>
bool MemoryBlock<T>::iterator::operator!=(const iterator& i)
{
	return block != i.block || current != i.current;
}

template <typename T>
typename MemoryBlock<T>::iterator& MemoryBlock<T>::iterator::operator++()
{
	next();
	return *this;
}

template <typename T>
typename MemoryBlock<T>::iterator MemoryBlock<T>::iterator::operator++(int)
{
	auto temp = iterator(block, current);
	next();
	return temp;
}

//TOOD poprawiæ optymalizacjê, usunaæ \ify 
template <typename T>
void MemoryBlock<T>::iterator::next()
{
	do
	{
		current++;
		if (block->check_if_outOfArray(current))
		{
			if (!block->check_if_row_exist(current))
			{
				current += block->N_;
			}
		}
		else
		{
			current = -1;
		}
	}
	while (!block->check_if_free(current));
}

template <typename T>
typename MemoryBlock<T>::iterator MemoryBlock<T>::begin()
{
	return iterator(this, 0);
}

template <typename T>
typename MemoryBlock<T>::iterator MemoryBlock<T>::end()
{
	return iterator(this, -1);
}


template <typename T>
bool MemoryBlock<T>::check_if_free(int index)
{
	if (index == -1)
	{
		return true;
	}
	const auto i = get_2D_index(index);
	return array_[i.first].second[i.second];
}

template <typename T>
bool MemoryBlock<T>::check_if_row_exist(int index)
{
	const auto i = get_2D_index(index);
	return array_[i.first].first!=nullptr;
}

template <typename T>
bool MemoryBlock<T>::check_if_outOfArray(int index)
{
	const auto i = get_2D_index(index);
	return i.first < array_.size();
}

template <typename T>
size_t MemoryBlock<T>::size()
{
	return size_;
}

// insert zwraca na element zalokowane 
/*
 * T t(i,j,k);
 * vector.insert(t); //const referencja (const T& t)
 * vector.insert(T(i,j,k); //move constructor
 * vector.emplace(i,j,k); //
 * vector.emplace(Args&&... a)
 * 
 * i,j,k mo¿na przesy³aæ 
 * Funkcja mo¿e przyjmowaæ wiele wartoœci do funkcji 
 * void fun(...){	
 * }
 * 
 * 
 * albo 
 * void fun(Args&&... a){
 * 
 * Ksi¹zki scotta mayersa 
 * Perfect forwarding 
 * T(std::forward(a))
 * 
 * Obczaiæ inline 
 */

// 
template <typename T>
std::pair<char*, int> MemoryBlock<T>::allocate()
{
	if (firstFree_==-1)
	{
		//Out of space in this particular block
		return std::pair<char*, int>(nullptr,-1);
	}
	const auto i = get_2D_index(firstFree_);
	if (i.first >= array_.size())
	{
		extend_array();
	}

	auto tmp = std::pair<char*, int>(array_[i.first].first + sizeof(T) * i.second, firstFree_);
	array_[i.first].second[i.second] = true;	
	find_next_empty();
	size_++;
	return tmp;
}

template <typename T>
T* MemoryBlock<T>::get_value(int index) const
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
//todo todo todo todo todooo