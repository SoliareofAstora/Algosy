#include <iostream>
#include "graph.hpp"
#include <string>
#include "dijkstra.hpp"
#include "astar.hpp"




using namespace std;

// https://www.sendspace.com/file/usgp9m

int main()
{
    graph<std::string, double> test_graph;

    for(std::size_t i = 0u; i < 6u; ++i)
    {
        test_graph.insertVertex("data " + std::to_string(i));
    }

    for(std::size_t i = 0u; i < test_graph.nrOfVertices(); ++i)
    {
        for(std::size_t j = 0u; j < test_graph.nrOfVertices(); ++j)
        {
            if((i + j) & 1u || i & 1u)
            {
                test_graph.insertEdge(i, j, ((i != j) ? (i+j)/2. : 0.));
            }
        }
    }
    test_graph.insertEdge(0, 2, 4.);
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
    for(auto v_it = test_graph.beginVertices(); v_it != test_graph.endVertices(); ++v_it)
    {
        std::cout << *v_it << ", ";
    }
    std::cout << std::endl << std::endl;
    std::cout << "Edges data:" << std::endl;
    for(auto e_it = test_graph.beginEdges(); e_it != test_graph.endEdges(); ++e_it)
    {
        std::cout << *e_it << ", ";
    }
    std::cout << std::endl << std::endl;
    std::cout << "DFS vertices data from (begin from 0):" << std::endl;
    for(auto dfs_it = test_graph.beginDFS(0); dfs_it != test_graph.endDFS(); ++dfs_it)
    {
        std::cout << *dfs_it << ", ";
    }
    std::cout << std::endl << std::endl;
    std::cout << "DFS vertices data (begin from 3):" << std::endl;
    for(auto dfs_it = test_graph.beginDFS(3); dfs_it != test_graph.endDFS(); ++dfs_it)
    {
        std::cout << *dfs_it << ", ";
    }
    std::cout << std::endl << std::endl;

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

	std::cout << "\ndijkstra\n";
	//4 24
    auto path = dijkstra<std::string, double>(test_graph, 2u, 4u);
    std::cout << "distance from 2 to 4: " << path.first << " - ";
    for(auto &v_id : path.second)
    {
        std::cout << v_id  << ", ";
    }
    std::cout << std::endl << std::endl;
	
	//4 120
    path = dijkstra<std::string, double>(test_graph, 1u, 0u);
    std::cout << "distance from 1 to 0: " << path.first << " - ";
    for(auto &v_id : path.second)
    {
        std::cout << v_id  << ", ";
    }
    std::cout << std::endl << std::endl;
	
	//5 320
    path = dijkstra<std::string, double>(test_graph, 3u, 0u);
    std::cout << "distance from 3 to 0: " << path.first << " - ";
    for(auto &v_id : path.second)
    {
        std::cout << v_id  << ", ";
    }
    std::cout << std::endl << std::endl;

	//6 321
    path = dijkstra<std::string, double>(test_graph, 3u, 1u);
    std::cout << "distance from 3 to 1: " << path.first << " - ";
    for(auto &v_id : path.second)
    {
        std::cout << v_id  << ", ";
    }
    std::cout << std::endl << std::endl;
	

	std::cout << "\nA star\n";
	//4 24
	path = astar<std::string, double>(test_graph, 2u, 4u,path_length_heuristic<std::string, double>);
	std::cout << "distance from 2 to 4: " << path.first << " - ";
	for (auto &v_id : path.second)
	{
		std::cout << v_id << ", ";
	}
	std::cout << std::endl << std::endl;

	//4 120
	path = astar<std::string, double>(test_graph, 1u, 0u, path_length_heuristic<std::string, double>);
	std::cout << "distance from 1 to 0: " << path.first << " - ";
	for (auto &v_id : path.second)
	{
		std::cout << v_id << ", ";
	}
	std::cout << std::endl << std::endl;

	//5 320
	path = astar<std::string, double>(test_graph, 3u, 0u, path_length_heuristic<std::string, double>);
	std::cout << "distance from 3 to 0: " << path.first << " - ";
	for (auto &v_id : path.second)
	{
		std::cout << v_id << ", ";
	}
	std::cout << std::endl << std::endl;

	//6 321
	path = astar<std::string, double>(test_graph, 3u, 1u, path_length_heuristic<std::string, double>);
	std::cout << "distance from 3 to 1: " << path.first << " - ";
	for (auto &v_id : path.second)
	{
		std::cout << v_id << ", ";
	}
	std::cout << std::endl << std::endl;
	std::cin.ignore();
    return 0;
}
