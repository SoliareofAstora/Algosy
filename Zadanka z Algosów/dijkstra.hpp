#pragma once
#include <utility>
#include "graph.hpp"

template <typename T, typename edge>
std::pair<edge, std::vector<T>> dijkstra(graph<T,edge>& graph, int from_i, int des_i)
{
	int size = graph.nrOfVertices();
	std::vector<int> unvisited;
	unvisited.reserve(size);
	std::vector<double> distance;
	distance.reserve(size);
	std::vector<std::vector<int>> path;
	path.reserve(size);
	for(int i = 0; i<size; i++)
	{
		unvisited.push_back(i);
		distance.push_back(DBL_MAX);
		path.emplace_back();
	}
	distance[from_i] = 0;

	while (!unvisited.empty())
	{
		
	}

	std::pair<edge, std::vector<T>> out;
	out.first = 100;
	out.second = std::vector<T>();
	out.second.push_back("a");
	out.second.push_back("a");
	out.second.push_back("a");
	out.second.push_back("a");
	return out;
};
