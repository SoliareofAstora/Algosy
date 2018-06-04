#pragma once
#include <utility>
#include <vector>
#include "graph.hpp"

template <typename T, typename edge>
std::pair<double,std::vector<int>>astar(graph<T,edge>& graph,int from_i, int des_i,std::function<double(int a, int b)> f)
{
	std::pair<double, std::vector<int>> out;
	out.first = f(from_i, des_i);
	return out;
}
