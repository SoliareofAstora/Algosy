#include <iostream>
#include "graph.hpp"
#include <string>

int main()
{
	graph<std::string, std::string> test_graph;

	for (int i = 0u; i < 6u; ++i)
	{
		test_graph.insertVertex("data " + std::to_string(i));
	}

	for (int i = 0u; i < test_graph.nrOfVertices(); ++i)
	{
		for (int j = 0u; j < test_graph.nrOfVertices(); ++j)
		{
			if ((i + j) & 1u || i & 1u)
			{
				test_graph.insertEdge(i, j, "label " + std::to_string(i) + " " + std::to_string(j));
			}
		}
	}
	test_graph.insertEdge(0, 2, "label 0 2");
	test_graph.removeVertex(1);
	test_graph.removeEdge(2, 2);
	test_graph.removeEdge(2, 3);
	test_graph.removeEdge(4, 3);
	std::cout << "Nr of vertices: " << test_graph.nrOfVertices() << std::endl;
	std::cout << "Nr of edges: " << test_graph.nrOfEdges() << std::endl;
	std::cout << std::endl;
	test_graph.printNeighborhoodMatrix();
	std::cout << std::endl;


	std::cout << "Vertices data:" << std::endl;
	for (auto v_it = test_graph.beginVertices(); v_it != test_graph.endVertices(); ++v_it)
	{
		std::cout << *v_it << ", ";
	}
	std::cout << "\n\n";


	std::cout << "Edges data:" << std::endl;
	for (auto e_it = test_graph.beginEdges(); e_it != test_graph.endEdges(); ++e_it)
	{
		std::cout << *e_it << "\n";
	}
	std::cout << "\n\n";

	
	std::cout << "DFS vertices data from (begin from 0):" << std::endl;
	for (auto dfs_it = test_graph.beginDFS(0); dfs_it != test_graph.endDFS(); ++dfs_it)
	{
		std::cout << *dfs_it << ", ";
	}
	std::cout << "\n\n";
	std::cout << "DFS vertices data (begin from 3):" << std::endl;
	for (auto dfs_it = test_graph.beginDFS(3); dfs_it != test_graph.endDFS(); ++dfs_it)
	{
		std::cout << *dfs_it << ", ";
	}
	std::cout << "\n\n";
	
	
	std::cout << "BFS vertices data from (begin from 0):" << std::endl;
	for (auto bfs_it = test_graph.beginBFS(0); bfs_it != test_graph.endBFS(); ++bfs_it)
	{
		std::cout << *bfs_it << ", ";
	}
	std::cout << "\n\n";
	std::cout << "BFS vertices data (begin from 3):" << std::endl;
	for (auto bfs_it = test_graph.beginBFS(3); bfs_it != test_graph.endBFS(); ++bfs_it)
	{
		std::cout << *bfs_it << ", ";
	}
	std::cout << "\n\n";
	
	char a;
	std::cin >> a;
	return 0;
}
