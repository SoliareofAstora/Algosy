#pragma once
#include <utility>
#include "graph.hpp"


template <typename T, typename edge>
std::pair<double, std::deque<int>> dijkstra(graph<T,edge>& graph, int from_i, int des_i)
{
	int size = graph.nrOfVertices();
	std::vector<int> unvisited;
	std::vector<double> distance;
	std::vector<int> path;
	unvisited.reserve(size);
	distance.reserve(size);
	path.reserve(size);
	for(int i = 0; i<size; i++)
	{
		unvisited.push_back(i);
		distance.push_back(999999999);
		path.push_back(-1);
	}
	distance[from_i] = 0;

	while (!unvisited.empty())
	{
		double minv = DBL_MAX;
		int u = -1;

		for (int i = 0; i < unvisited.size(); i++)
		{
			if (distance[unvisited[i]]<minv)
			{
				minv = distance[unvisited[i]];
				u = i;
			}
		}
		int temp = u;
		u = unvisited[temp];
		unvisited.erase(unvisited.begin() + temp);

		for (int i = 0; i < unvisited.size(); i++)
		{
			if (graph.connection(u,unvisited[i]))
			{
				minv = distance[u] + *graph.edgeLabel(u, unvisited[i]);
				if (minv<distance[unvisited[i]])
				{
					distance[unvisited[i]] = minv;
					path[unvisited[i]] = u;
				}
			}
		}
	}
	std::deque<int> S;
	int u = des_i;
	while (path[u]!=-1)
	{
		S.push_front(u);
		u = path[u];
	}
	S.push_front(u);


	std::pair<double, std::deque<int>> out;
	out.first = distance[des_i];
	out.second = S;
	return out;
};
