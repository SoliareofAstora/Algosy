#pragma once
#include <utility>
#include <vector>
#include "graph.hpp"

template <typename T, typename edge>
double path_length_heuristic(graph<T, edge>& graph, int a, int b)
{
	return graph.adjacency_matrix[a][b].label;
}

template <typename T, typename edge>
std::pair<double, std::vector<int>> astar(graph<T, edge>& graph_, int from_i, int des_i,
	std::function<double(graph<T, edge>& graph, int a, int b)> heuristic_distance)
{
	const int size = graph_.nrOfVertices();
	std::vector<bool> closedSet(size, false);
	std::vector<int> openSet(size, false);
	std::vector<int> cameFrom(size, -1);
	std::vector<double> gScore(size, DBL_MAX);
	std::vector<double> fscore(size, DBL_MAX);

	openSet[from_i] = true;
	gScore[from_i] = 0;
	if (graph_.connection(from_i, des_i))
	{
		fscore[from_i] = heuristic_distance(graph_, from_i, des_i);
	}

	while (!openSet.empty())
	{
		int current = 0;
		double minv = DBL_MAX;
		for (int i = 0; i < size; i++)
		{
			if (openSet[i])
			{
				if (fscore[i] <= minv)
				{
					minv = fscore[i];
					current = i;
				}
			}
		}


		if (current == des_i)
		{
			break;
		}

		openSet[current] = false;
		closedSet[current] = true;

		for (int i = 0; i < size; ++i)
		{
			if (graph_.connection(current,i))
			{
				if (closedSet[i])
				{
					continue;
				}
				if (!openSet[i])
				{
					openSet[i] = true;
				}
				double currentScore = gScore[current] + heuristic_distance(graph_, current, i);
				if (currentScore >=gScore[i])
				{
					continue;
				}
				cameFrom[i] = current;
				gScore[i] = currentScore;
				fscore[i] = currentScore;
			}
			
		}


	}

	std::vector<int> path;

	int current = des_i;
	

	while (cameFrom[current]!=-1)
	{
		path.push_back(current);
		current = cameFrom[current];
	}
	path.push_back(current);
	std::reverse(path.begin(),path.end());

	std::pair<double, std::vector<int>> out;

	out.first = fscore[des_i];
	out.second = path;
	return out;
}