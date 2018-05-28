#include <iostream>
#include "graph.hpp"
#include <string>
#include "dijkstra.hpp"

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
	//zwraca sługość ścieżki oraz wektor zawierający indeksy punktów
	/*
	 *	usunąć rekurencję 
	 *	dodawać dane do wektorów od razu podczas deklarowania zmiennej 
	 *	visited zmienić na tablicę bool
	 *	AVL zmienić na implementacji listy tablic 
	 *	wyrzucić queue i zamiast tego push back na wektor potem odwrócenie elementów przy zwracaniu 
	 *

	1  function Dijkstra(Graph, source):
	2
	3      create vertex set Q
	4
	5      for each vertex v in Graph:             // Initialization
	6          dist[v] ← INFINITY                  // Unknown distance from source to v
	7          prev[v] ← UNDEFINED                 // Previous node in optimal path from source
	8          add v to Q                          // All nodes initially in Q (unvisited nodes)
	9
	10      dist[source] ← 0                       // Distance from source to source
	11
	12      while Q is not empty:
	13          u ← vertex in Q with min dist[u]    // Node with the least distance
	14                                              // will be selected first
	15          remove u from Q
	16
	17          for each neighbor v of u:           // where v is still in Q.
	18              alt ← dist[u] + length(u, v)
	19              if alt < dist[v]:               // A shorter path to v has been found
	20                  dist[v] ← alt
	21                  prev[v] ← u
	22
	23      return dist[], prev[]


	1  S ← empty sequence
	2  u ← target
	3  while prev[u] is defined:                  // Construct the shortest path with a stack S
	4      insert u at the beginning of S         // Push the vertex onto the stack
	5      u ← prev[u]                            // Traverse from target to source
	6  insert u at the beginning of S             // Push the source onto the stack

	*/

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
	
	std::cin.ignore();
    return 0;
}
