#pragma once
#include <vector>
#include <bitset>
#include <array>

/*
T - data type  
N - size of one memory block 
constIndex - keep elements under once allocated constant index 
*/
template <typename T,size_t N = 128, bool constIndex = false>
class MemoryPool
{
	typedef std::pair<unsigned long long, unsigned long long> address;
	static address max(){ return address(std::numeric_limits<size_t>::max(), std::numeric_limits<size_t>::max()); }
	
	//vector< pair< controller, memory block>>
	std::vector< 
		std::pair<
			std::bitset<N>,
			std::unique_ptr
				<std::array<char, N * sizeof T>>
		>	
	>memory_;
	void extend_memory();


	address size_ = address(0,0);
	address firstFree_ = address(0,0);
	void find_next_free();

	static address index_1D_to_2D(size_t& index1D)
	{
		return address(index1D / N, index1D % N);
	}
	static size_t index_2D_to_1D(address& index2D)
	{
		return index2D.first*N + index2D.second;
	}

	static void increaseAddress(address& address)
	{
		if (address.second==N-1)
		{
			++address.first;
			address.second = 0;
		}
		else
		{
			++address.second;
		}
	}
	static void decreaseAddress(address& address)
	{
		if (address.second == 0)
		{
			--address.first;
			address.second = N - 1;
		}
		else
		{
			--address.second;
		}
	}
	void find_next(address& index);
	void find_prev(address& index);
	void find_next(address& index, size_t n);
	void find_prev(address& index, size_t n);

	class iterator
	{
		MemoryPool* pool;
		address current;
	public:
		address get_index() const { return current; }
		iterator();
		iterator(MemoryPool* source, const address& current);

		bool operator == (const iterator& i);
		bool operator != (const iterator& i);
		bool operator > (const iterator& i);
		bool operator >= (const iterator& i);
		bool operator< (const iterator& i);
		bool operator <= (const iterator& i);

		iterator& operator++();
		iterator& operator--();

		iterator operator ++(int);
		iterator operator --(int);

		iterator& operator+(const size_t& i);
		iterator& operator-(const size_t& i);

		iterator& operator-=(const size_t& i);
		iterator& operator+=(const size_t& i);

		T& operator*()
		{
			return *(pool->operator[](current));
		};
	};

public:
	iterator insert(T &&el);
	void erase(size_t index1D);
	void erase(address index2D);
	void clear();
	void shrink_to_fit();
	T* operator [](size_t index);
	T* operator [](address index);
	T* at(size_t index);
	T* at(address index);

	size_t capacity() { return memory_.size()*N; }
	size_t size() { return index_2D_to_1D(size_); }
	address pair_size() const { return size_; }
	static size_t block_size() { return N; }
	void reserve(const size_t n);

	iterator make_iterator(const T* ptr);
	iterator begin();
	iterator end();

	void test();
};

template <typename T, size_t N, bool constIndex>
void MemoryPool<T, N, constIndex>::extend_memory()
{
	memory_.push_back(
		std::pair<
		std::bitset<N>,
		std::unique_ptr<std::array<char, N * sizeof T>>>
		(std::bitset<N>(), std::make_unique<std::array<char, N * sizeof T>>())
	);
}

template <typename T, size_t N, bool constIndex>
void MemoryPool<T, N, constIndex>::find_next_free()
{
	for (auto i = firstFree_.first; i < memory_.size(); i++)
	{
		auto* bitset = &memory_[i].first;
		bitset->flip();
		if (bitset->any())
		{
			for (size_t j = firstFree_.second; j < N; j++)
			{
				if (bitset->test(j))
				{
					bitset->flip();
					firstFree_ = address(i, j);

					if (!memory_[i].second)
					{
						memory_[i].second = std::make_unique<std::array<char, N * sizeof T>>();
					}
					return;
				}
			}
		}
		firstFree_.second = 0;
		bitset->flip();
	}

	firstFree_ = address(memory_.size(), 0);
	extend_memory();
}

template <typename T, size_t N, bool constIndex>
void MemoryPool<T, N, constIndex>::find_next(address& index)
{
	find_next(index, 1);
}

template <typename T, size_t N, bool constIndex>
void MemoryPool<T, N, constIndex>::find_prev(address& index)
{
	find_prev(index, 1);
}

template <typename T, size_t N, bool constIndex>
void MemoryPool<T, N, constIndex>::find_next(address& index, size_t n)
{
	size_t counter = 0;
	for (auto i = index.first; i < memory_.size(); i++)
	{
		auto* bitset = &memory_[i].first;
		if (bitset->any())
		{
			for (size_t j = index.second; j < N; j++)
			{
				if (bitset->test(j))
				{
					counter++;
					if (counter > n)
					{
						index = address(i, j);
						return;
					}
				}
			}
		}
		index.second = 0;
	}
	index = max();
}

template <typename T, size_t N, bool constIndex>
void MemoryPool<T, N, constIndex>::find_prev(address& index, size_t n)
{
	size_t counter = 0;
	if (index.first>memory_.size())
	{
		index = address(memory_.size() - 1, N - 1);
		counter++;
	}
	for (auto i = index.first; i < memory_.size(); i--)
	{
		auto* bitset = &memory_[i].first;
		if (bitset->any())
		{
			for (size_t j = index.second; j < N; j--)
			{
				if (bitset->test(j))
				{
					counter++;
					if (counter > n)
					{
						index = address(i, j);
						return;
					}
				}
			}
		}
		index.second = N - 1;
	}
	index = max();
}

template <typename T, size_t N, bool constIndex>
MemoryPool<T, N, constIndex>::iterator::iterator()
	:pool(nullptr),current(MemoryPool::max())
{
}

template <typename T, size_t N, bool constIndex>
MemoryPool<T, N, constIndex>::iterator::iterator(MemoryPool* source, const address& current)
	:pool(source),current(current)
{
}

template <typename T, size_t N, bool constIndex>
bool MemoryPool<T, N, constIndex>::iterator::operator==(const iterator& i)
{
	return pool == i.pool && current == i.current;
}

template <typename T, size_t N, bool constIndex>
bool MemoryPool<T, N, constIndex>::iterator::operator!=(const iterator& i)
{
	return pool != i.pool || current != i.current;
}

template <typename T, size_t N, bool constIndex>
bool MemoryPool<T, N, constIndex>::iterator::operator>(const iterator& i)
{
	return current > i.current;
}

template <typename T, size_t N, bool constIndex>
bool MemoryPool<T, N, constIndex>::iterator::operator>=(const iterator& i)
{
	return current >= i.current;
}

template <typename T, size_t N, bool constIndex>
bool MemoryPool<T, N, constIndex>::iterator::operator<(const iterator& i)
{
	return current < i.current;
}

template <typename T, size_t N, bool constIndex>
bool MemoryPool<T, N, constIndex>::iterator::operator<=(const iterator& i)
{
	return current <= i.current;
}

template <typename T, size_t N, bool constIndex>
typename MemoryPool<T, N, constIndex>::iterator& MemoryPool<T, N, constIndex>::iterator::operator++()
{
	pool->find_next(current);
	return *this;
}

template <typename T, size_t N, bool constIndex>
typename MemoryPool<T, N, constIndex>::iterator& MemoryPool<T, N, constIndex>::iterator::operator--()
{
	pool->find_prev(current);
	return *this;
}

template <typename T, size_t N, bool constIndex>
typename MemoryPool<T, N, constIndex>::iterator MemoryPool<T, N, constIndex>::iterator::operator++(int)
{
	auto tmp = iterator(pool, current);
	pool->find_next(current);
	return tmp;
}

template <typename T, size_t N, bool constIndex>
typename MemoryPool<T, N, constIndex>::iterator MemoryPool<T, N, constIndex>::iterator::operator--(int)
{
	auto tmp = iterator(pool, current);
	pool->find_prev(current);
	return tmp;
}

template <typename T, size_t N, bool constIndex>
typename MemoryPool<T, N, constIndex>::iterator& MemoryPool<T, N, constIndex>::iterator::operator+(const size_t& i)
{
	pool->find_next(current, i);
	return *this;
}

template <typename T, size_t N, bool constIndex>
typename MemoryPool<T, N, constIndex>::iterator& MemoryPool<T, N, constIndex>::iterator::operator-(const size_t& i)
{
	pool->find_prev(current, i);
	return *this;
}

template <typename T, size_t N, bool constIndex>
typename MemoryPool<T, N, constIndex>::iterator& MemoryPool<T, N, constIndex>::iterator::operator-=(const size_t& i)
{
	std::cout << i << " ";
	pool->find_prev(current, i);
	return *this;
}

template <typename T, size_t N, bool constIndex>
typename MemoryPool<T, N, constIndex>::iterator& MemoryPool<T, N, constIndex>::iterator::operator+=(const size_t& i)
{
	pool->find_next(current, i);
	return *this;
}

template <typename T, size_t N, bool constIndex>
typename MemoryPool<T, N, constIndex>::iterator MemoryPool<T, N, constIndex>::insert(T&& el)
{
	find_next_free();
	auto tmp = new(&memory_[firstFree_.first].second.operator*()[firstFree_.second * sizeof T])T(std::forward<T>(el));
	memory_[firstFree_.first].first.set(firstFree_.second);
	increaseAddress(size_);
	return iterator(this, firstFree_);
}

template <typename T, size_t N, bool constIndex>
void MemoryPool<T, N, constIndex>::erase(size_t index1D)
{
	return erase(index_1D_to_2D(index1D));
}


//todo return iterator and use iterator instead of address
template <typename T, size_t N, bool constIndex>
void MemoryPool<T, N, constIndex>::erase(address index2D)
{
	if (index2D.first >= memory_.size() || index2D.second >= N)
	{
		std::cerr << "Erase index out of range";
		return; //iterator do zerowego
	}
	if (!memory_[index2D.first].first.test(index2D.second))
	{
		std::cerr << "Trying to delete empty ptr";
	}

//T deletedElement;

	(reinterpret_cast<T*>(&memory_[index2D.first].second.operator*()[index2D.second * sizeof T]))->~T();

	decreaseAddress(size_);

	if (constIndex)
	{
		memory_[index2D.first].first.reset(index2D.second);
		firstFree_ = std::min(index2D, firstFree_);
	}
	else
	{
		//moving last ptr in place of deleted ptr
		if (index2D != size_)
		{
			*(reinterpret_cast<T*>(&memory_[index2D.first].second.operator*()[index2D.second * sizeof T]))
				= std::move(*reinterpret_cast<T*>(&memory_[size_.first].second.operator*()[size_.second * sizeof T]));
		}
		memory_[size_.first].first.reset(size_.second);
		firstFree_ = size_;
	}
	return; //iterator(deletedElement)
}

template <typename T, size_t N, bool constIndex>
void MemoryPool<T, N, constIndex>::clear()
{
	for (auto rit = memory_.rbegin(); rit != memory_.rend(); ++rit) 
	{
		const size_t count = (*rit).first.count();
		if (count > 0)
		{
			if (count == N)
			{
				for (size_t i = 0; i < N; i++)
				{
					(reinterpret_cast<T*>(&(*rit).second.operator*()[i * sizeof T]))->~T();
				}
			}
			else
			{
				size_t idx = 0;
				for (size_t i = 0; i < count; i++)
				{
					while (!(*rit).first.test(i + idx))
					{
						++idx;
					}
					(reinterpret_cast<T*>(&(*rit).second.operator*()[i * sizeof T]))->~T();
				}
			}
		}
		memory_.pop_back();
	}
	memory_.shrink_to_fit();
	size_ = address(0, 0);
	firstFree_ = address(0, 0);
}

template <typename T, size_t N, bool constIndex>
void MemoryPool<T, N, constIndex>::shrink_to_fit()
{
	if (constIndex)
	{
		for(auto &pair: memory_)
		{
			if (pair.first.none())
			{
				pair.second.reset(nullptr);
			}
		}
	}
	else
	{
		auto begin = memory_.end();
		while ((--begin).operator*().first.none())
		{
		}
		memory_.erase(++begin, memory_.end());
	}
	memory_.shrink_to_fit();
}

template <typename T, size_t N, bool constIndex>
T* MemoryPool<T, N, constIndex>::operator[](size_t index)
{
	return this->operator[](index_1D_to_2D(index));
}

template <typename T, size_t N, bool constIndex>
T* MemoryPool<T, N, constIndex>::operator[](address index)
{
	return reinterpret_cast<T*>(&memory_[index.first].second.operator*()[index.second * sizeof T]);
}

template <typename T, size_t N, bool constIndex>
T* MemoryPool<T, N, constIndex>::at(size_t index)
{
	return at(index_1D_to_2D(index));
}

template <typename T, size_t N, bool constIndex>
T* MemoryPool<T, N, constIndex>::at(address index)
{
	if (index >= size_) return nullptr;
	if (!memory_[index.first].first.test(index.second)) return nullptr;
	return reinterpret_cast<T*>(&memory_[index.first].second.operator*()[index.second * sizeof T]);
}

template <typename T, size_t N, bool constIndex>
void MemoryPool<T, N, constIndex>::reserve(const size_t n)
{
	size_t tmp = (n-1) / N - memory_.size() + 1;
	for (size_t i = 0; i < tmp; ++i)
	{
		extend_memory();
	}

}

template <typename T, size_t N, bool constIndex>
typename MemoryPool<T, N, constIndex>::iterator MemoryPool<T, N, constIndex>::make_iterator(const T* ptr)
{
	for (size_t i = 0; i<memory_.size();i++)
	{
		const auto distance = ptr - reinterpret_cast<T*>(&memory_[i].second.operator*().front());
		if (distance<N && distance >=0)
		{
			return iterator(this, address(i, distance));
		}
	}
	return iterator();
}

template <typename T, size_t N, bool constIndex>
typename MemoryPool<T, N, constIndex>::iterator MemoryPool<T, N, constIndex>::begin()
{
	address first = address(0, 0);
	find_next(first,0);
	return iterator(this, first);
}

template <typename T, size_t N, bool constIndex>
typename MemoryPool<T, N, constIndex>::iterator MemoryPool<T, N, constIndex>::end()
{

	return iterator(this, max());
}

template <typename T, size_t N, bool stf>
void MemoryPool<T, N, stf>::test()
{
	for (int i = 0; i < 1000; i++)
	{
		int a = i;
		insert(std::move(a));
	}
	int i = 1;
	erase(i);
	//clear();
	make_iterator(this->operator[](400));
	std::string txt;
	std::cout << this->operator[](1);

	if (this->operator[](1))
	{
		txt = "true";
	}
	else
	{
		txt = "false";
	}
	std::cout << "\n\n" << txt;
}




/*
 *constructor
 *deconstructor
 *operator =
 *
 *Iteratory:
 *	begin
 *	end
 *	rbegin //reverse
 *	rend
 *
 *const Iteratory:
 *	cbegin
 *	cend
 *	crbegin
 *	crend
 *	
 *Capacity:
 *	Size
 *	Max_size
 *	empty
 *	resize
 *	shrink to fit
 *	capacity
 *	reserve
 *	
 *ptr access
 *	front
 *	back 
 *	operator []
 *	at
 *	
 *modifiers
 *	assign
 *	emplace
 *	emplace_hint
 *	insert
 *	erase
 *	enplace_back
 *	push_back
 *	pop_back
 *	clear
 *	swap
 *	
 *Operations
 *	count
 *	find
 *	equal_range
 *	lower_bound
 *	upper bound
 *	
 *list operators
 *	splice
 *	remove
 *	remove_if
 *	unique
 *	merge
 *	sort
 *	reverse
 *	
 *observers
 *	get_allocator
 *	data
 *	
 *Buckets
 *	busket
 *	bucket_count
 *	bucket_size
 *	max_bucket_count
 *	
 *hash policy
 *	rehash
 *	load_factor
 *	max_load_factor

 */
