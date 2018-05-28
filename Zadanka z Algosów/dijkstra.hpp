#pragma once
#include <utility>
#include "graph.hpp"


template <typename T, typename edge>
std::pair<double, std::vector<int>> dijkstra(graph<T,edge>& graph, int from_i, int des_i)
{
	int size = graph.nrOfVertices();

	std::vector<bool> unvisited(size,true);
	std::vector<double> distance(size,DBL_MAX);
	std::vector<int> path(size,-1);

	distance[from_i] = 0;

	for (int j = 0; j < size; ++j)
	{
		if (!unvisited[des_i])
		{
			break;
		}
		double minv = DBL_MAX;
		int u = -1;

		for (int i = 0; i < size; i++)
		{
			if (unvisited[i])
			{
				if (distance[i] <= minv)
				{
					minv = distance[i];
					u = i;
				}
			}
		}

		unvisited[u] = false;

		for (int i = 0; i < size; i++)
		{
			if (unvisited[i])
			{
				if (graph.connection(u, i))
				{
					minv = distance[u] + *graph.edgeLabel(u, i);
					if (minv < distance[i])
					{
						distance[i] = minv;
						path[i] = u;
					}
				}
			}
		}
	}

	std::vector<int> S;
	int u = des_i;
	while (path[u]!=-1)
	{
		S.push_back(u);
		u = path[u];
	}
	S.push_back(u);
	std::reverse(S.begin(), S.end());

	std::pair<double, std::vector<int>> out;
	out.first = distance[des_i];
	out.second = S;
	return out;
};
