#pragma once
#include <vector>
#include <bitset>
#include <array>


template <typename T,size_t N = 128, bool stf = true>
class MemoryPool
{
	using address = std::pair<unsigned long long, unsigned long long>;

	std::vector 
	< 
		std::pair 
		<
			std::bitset<N>,
			std::unique_ptr 
				<std::array<char,N*sizeof T>>
		>
	>
	memory;
	address firstFree = address(0,0);
	
	address convert_to2_d(size_t index1D)
	{
		return address(index1D / N, index1D % N);
	}
	
public:

	

	void test();
};

template <typename T, size_t N, bool stf>
void MemoryPool<T, N, stf>::test()
{
	auto temp = convert_to2_d(100);
	std::cout << temp.first<<" "<<temp.second;
}

