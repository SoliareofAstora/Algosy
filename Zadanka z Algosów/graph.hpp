#pragma once
#include <vector>
#include <future>

template <typename T,typename edge> 
class graph
{
	struct edge_info
	{
		edge name;
		bool connection;
		edge_info():connection(false){}
		edge_info(edge& name) :name(name), connection(true) {}
	};

	std::vector<std::vector<edge_info>> adjacency_matrix;
	std::vector<T> table;
	
public:
	graph();

	bool insertEdge(int from_index, int destination_index, edge name);
	bool insertEdge(int from_index,int destination_index, edge name, bool overwrite);
	void insertVertex(T value);
	void removeVertex(int index);
	void removeEdge(int from_index, int destination_index);

	size_t nrOfVertices();
	int nrOfEdges();
	void printNeighborhoodMatrix();



	VerticesIterator beginVertices();
	VerticesIterator endVertices();


};

template<typename T, typename edge>
graph<T, edge>::graph() = default;

template <typename T, typename edge>
bool graph<T, edge>::insertEdge(int from_index, int destination_index, edge name)
{
	return insertEdge(from_index, destination_index, name, false);
}

template <typename T, typename edge>
bool graph<T, edge>::insertEdge(int from_index, int destination_index, edge name, bool overwrite)
{
	if (from_index >= table.size() ||destination_index >= table.size() ||from_index<0||destination_index<0)
	{
		return false;
	}
	if (!(adjacency_matrix[from_index][destination_index].connection)||overwrite)
	{
		adjacency_matrix[from_index][destination_index] = edge_info(name);
	}
	return true;
}

template <typename T, typename edge>
void graph<T, edge>::insertVertex(T value)
{
	table.push_back(value);
	adjacency_matrix.push_back(std::vector<edge_info>());
	for(auto &v : adjacency_matrix)
	{
		v.push_back(edge_info());
	}
	adjacency_matrix[table.size()-1].resize(table.size());
}

template <typename T, typename edge>
void graph<T, edge>::removeVertex(int index)
{
	table.erase(table.begin()+index);
	for(auto &v : adjacency_matrix)
	{
		v.erase(v.begin() + index);
	}
	adjacency_matrix.erase(adjacency_matrix.begin() + index);
}

template <typename T, typename edge>
void graph<T, edge>::removeEdge(int from_index, int destination_index)
{
	adjacency_matrix[from_index][destination_index] = edge_info();
}

template <typename T, typename edge>
size_t graph<T, edge>::nrOfVertices()
{
	return table.size();
}

template <typename T, typename edge>
int graph<T, edge>::nrOfEdges()
{
	int sum = 0;
	for (auto &vector : adjacency_matrix)
	{
		for (auto &element : vector)
		{
			if (element.connection)
			{
				sum++;
			}
		} 
	}
	return sum;
}

template <typename T, typename edge>
void graph<T, edge>::printNeighborhoodMatrix()
{
	for (auto &v : adjacency_matrix)
	{
		for (auto &a : v)
		{
			std::string temp = a.connection == true ? "1" : "0";
			std::cout <<temp<<" ";
		}
		std::cout << "\n";
	}
	std::cout << "\n";
}

/*

poni¿ej kod który przerabialiœmy

public:
    class VerticesIterator
    {
      public:
        VerticesIterator(Graph<V,E> &graph, std::size_t current_vertex_id = 0u);
      public:
        bool operator==(const VerticesIterator &vi) const;
        bool operator!=(const VerticesIterator &vi) const { return !(*this == vi);}
        VerticesIterator& operator++();
        VerticesIterator operator++(int);
        V& operator*();
    };
    class EdgesIterator
    {
      private:
        EdgesIterator(Graph<V,E> &graph, std::size_t nm_row, std::size_t mn_col);
      public:
        bool operator==(const EdgesIterator &ei) const;
        bool operator!=(const EdgesIterator &ei) const { return !(*this == ei);}
        EdgesIterator& operator++();
        EdgesIterator operator++(int);
        E& operator*();
    };


i metody:
    std::size_t nrOfVertices() const;
    std::size_t nrOfEdges() const;
    void printNeighborhoodMarix() const;
    VerticesIterator beginVertices();
    VerticesIterator endVertices();
    EdgesIterator beginEdges();
    EdgesIterator endEdges();

*/
