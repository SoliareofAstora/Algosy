#pragma once
#include <vector>
#include <bitset>
#include <array>

/*
T - element type  
N - size of one block 
constIndex - keep elements under constant, once allocated index
*/
template <typename T,size_t N = 128, bool constIndex = false>
class MemoryPool
{
	using address = std::pair<size_t, size_t>;

	std::vector< 
		std::pair<
			std::bitset<N>,
			std::unique_ptr
				<std::array<char, N * sizeof T>>
			
		>	
	>
	memory;
	address firstFree = address(0,0);
	void find_next_empty();

	address index_2D_from_1D(size_t index1D)
	{
		return address(index1D / N, index1D % N);
	}
	
	class iterator
	{
		MemoryPool<T>* pool;
		address current;
	public:
		iterator();
		iterator(MemoryBlock<T>* source, const int& current);
		bool operator ==(const iterator& i);
		bool operator !=(const iterator& i);
		iterator& operator++();
		iterator operator ++(int);

		T& operator*()
		{
			return pool[current];
		};

		void next();
		void prev();
	};

public:

	void erase(size_t index1D);
	void erase(address index2D);


	void test();
	iterator operator [](address index);
	iterator begin();
	iterator end();
};

template <typename T, size_t N, bool constIndex>
void MemoryPool<T, N, constIndex>::find_next_empty()
{
	for (auto i = firstFree.first; i < memory.size(); i++)
	{
		//todo czy to oby na pewno ma sens
		if (!(memory[i].first.all()))
		{
			for (auto j = firstFree.second; j < N; j++)
			{   //TODO czy op³ada siê wrzucaæ tutaj wskaŸnik na bitset, 
				//zeby nie wyci¹gaæ wartoœci z wektora i pary.
				if (memory[i].first[j]==false)
				{
					firstFree = address(i, j);
					return;
				}
			}
			firstFree.second = 0;
		}
	}	

	firstFree = address(memory.size(), 0);
	memory.push_back(
		std::pair<std::bitset<N>,
		std::unique_ptr<std::array<char, N * sizeof T>>>
		(std::bitset<N>(),new char[N * sizeof T])
	);
}

template <typename T, size_t N, bool constIndex>
void MemoryPool<T, N, constIndex>::erase(size_t index1D)
{
	return erase(index_2D_from_1D(index1D));
}

template <typename T, size_t N, bool constIndex>
void MemoryPool<T, N, constIndex>::erase(address index2D)
{
	if (memory[index2D.first].first[index2D.second])
	{
		firstFree = std::min(index2D, firstFree);
		memory[index2D.first].first[index2D.second] = false;


		if (!constIndex)
		{
			if (memory[index2D.first].first.empty())
			{
				//memory.eras
			}
		}
	}
}

template <typename T, size_t N, bool stf>
void MemoryPool<T, N, stf>::test()
{
	auto temp = index_2D_from_1D(200000);
	std::cout << temp.first<<" "<<temp.second;

	for (auto i = 0; i < 7; ++i)
	{
		std::cout << i;
	}

	std::bitset<10> asdf;
	asdf[3] = true;
	std::cout<<asdf.any();
	std::string txt;

	if (asdf[9])
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
 *element access
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
