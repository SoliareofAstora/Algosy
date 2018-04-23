#pragma once
#include <vector>

template <typename T,typename edge> 
class map
{
	struct edge_info
	{
		edge name;
		bool connection;
		edge_info():connection(false){}
	};

	std::vector<std::vector<edge_info>> adjacency_matrix;
	std::vector<T> table;
	int size;
	
public:
	bool insert_edge(int& from_index,int& destination_index, bool& overwrite);
	bool insert_vertex(T& value);

	void printSize()
	{
		std::cout << size<<std::endl;
		std::cout << table.size() << std::endl;
		std::cout <<"matrix "<< adjacency_matrix.size()<<" "<< adjacency_matrix[0].size();
	}
	map():size(0){}
};


template <typename T, typename edge>
bool map<T, edge>::insert_edge(int& from_index, int& destination_index, bool& overwrite)
{
	if (from_index>=size||destination_index>=size)
	{
		return false;
	}



}

template <typename T, typename edge>
bool map<T, edge>::insert_vertex(T& value)
{

	table.push_back(value);

	adjacency_matrix.push_back();
	for(auto &v : adjacency_matrix)
	{
		v.push_back();
	}
	for (int i = 0; i < size; i++)
		adjacency_matrix[i].resize(size+1);

	size++;
	std::vector<edge_info>temp;
	temp.resize(size);
	adjacency_matrix.push_back(temp);


	return false;
}

