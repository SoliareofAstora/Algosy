#pragma once
#include <vector>
#include <future>
#include "avl.h"
#include <stack>
#include <queue>

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
public:
	std::vector<std::vector<edge_info>> adjacency_matrix;
	std::vector<T> vertices;

	graph();

	bool insertEdge(int from_index, int destination_index, edge name);
	bool insertEdge(int from_index,int destination_index, edge name, bool overwrite);
	void insertVertex(T value);
	void removeVertex(int index);
	void removeEdge(int from_index, int destination_index);
	
	size_t nrOfVertices();
	int nrOfEdges();
	void printNeighborhoodMatrix();

#pragma region Iterators

	typedef typename std::vector<T>::iterator VerticesIterator;
	VerticesIterator beginVertices();
	VerticesIterator endVertices();

	class EdgesIterator
	{
		graph<T,edge> * source_;
		std::pair<int, int> current_;
	public:
		EdgesIterator(graph<T, edge>* source,int first, int second);
		EdgesIterator(graph<T, edge>* source, std::pair<int, int> current);
		bool operator==(const EdgesIterator &i) const;
		bool operator!=(const EdgesIterator &i) const;
		EdgesIterator& operator++();
		EdgesIterator operator++(int);
		edge operator*();
		void findNextEdge();
	};
	EdgesIterator beginEdges();
	EdgesIterator endEdges();

	class DFSIterator
	{
		graph* source_;
		int current_;
		avl<int> visited_;
		std::stack<int> stack_;
	public:
		DFSIterator(graph* source, int start_at);
		bool operator==(const DFSIterator &i) const;
		bool operator!=(const DFSIterator &i) const;
		DFSIterator& operator++();
		DFSIterator operator++(int);
		T operator*();
		void findNextVertex();
	};
	DFSIterator beginDFS(int n);
	DFSIterator endDFS();
	
	class BFSIterator
	{
		graph* source_;
		int current_;
		int currentNeighbor_;
		avl<int> visited_;
		std::queue<int> queue_;
	public:
		BFSIterator(graph* source, int start_at);
		bool operator==(const BFSIterator &i) const;
		bool operator!=(const BFSIterator &i) const;
		BFSIterator& operator++();
		BFSIterator operator++(int);
		T operator*();
		void findNextVertex();
	};
	BFSIterator beginBFS(int start_at);
	BFSIterator endBFS();

#pragma endregion 

};

#pragma region Graph functions

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
	if (from_index >= vertices.size() ||destination_index >= vertices.size() ||from_index<0||destination_index<0)
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
	vertices.push_back(value);
	adjacency_matrix.push_back(std::vector<edge_info>());
	for(auto &v : adjacency_matrix)
	{
		v.push_back(edge_info());
	}
	adjacency_matrix[vertices.size()-1].resize(vertices.size());
}

template <typename T, typename edge>
void graph<T, edge>::removeVertex(int index)
{
	vertices.erase(vertices.begin()+index);
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
	return vertices.size();
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

#pragma endregion 

#pragma region VerticesIterator

template <typename T, typename edge>
typename graph<T, edge>::VerticesIterator graph<T, edge>::beginVertices()
{
	return vertices.begin();
}

template <typename T, typename edge>
typename graph<T, edge>::VerticesIterator graph<T, edge>::endVertices()
{
	return vertices.end();
}

#pragma endregion 

#pragma region EdgeIterator

template <typename T, typename edge>
graph<T, edge>::EdgesIterator::EdgesIterator(graph<T,edge>* source, int first, int second):source_(source),current_(first,second)
{
	if (first>=0)
	{
		findNextEdge();
	}
}

template <typename T, typename edge>
graph<T, edge>::EdgesIterator::EdgesIterator(graph<T, edge>* source, std::pair<int, int> current):source_(source),current_(current)
{
}

template <typename T, typename edge>
bool graph<T, edge>::EdgesIterator::operator==(const EdgesIterator& i) const
{
	return current_ == i.current_ && source_==i.source_;
}

template <typename T, typename edge>
bool graph<T, edge>::EdgesIterator::operator!=(const EdgesIterator& i) const
{
	return current_ != i.current_ || source_ != i.source_;
}

template <typename T, typename edge>
typename graph<T, edge>::EdgesIterator& graph<T, edge>::EdgesIterator::operator++()
{
	findNextEdge();
	return *this;
}

template <typename T, typename edge>
typename graph<T, edge>::EdgesIterator graph<T, edge>::EdgesIterator::operator++(int)
{
	EdgesIterator temp = EdgesIterator(source_, current_);
	findNextEdge();
	return temp;
}

template <typename T, typename edge>
edge graph<T, edge>::EdgesIterator::operator*()
{
	return source_->adjacency_matrix[current_.first][current_.second].name;
}

template <typename T, typename edge>
void graph<T, edge>::EdgesIterator::findNextEdge()
{
	do
	{
		do
		{
			if (++current_.second >= source_->vertices.size())
			{
				break;
			}
			if (source_->adjacency_matrix[current_.first][current_.second].connection)
			{
				return;
			}
		}
		while (current_.second+1<source_->vertices.size());
		current_.first++;
		current_.second = -1;
	}
	while (current_.first<source_->vertices.size());
	current_.first = -1;
}

template <typename T, typename edge>
typename graph<T, edge>::EdgesIterator graph<T, edge>::beginEdges()
{
	return EdgesIterator(this,0,-1);
} 

template <typename T, typename edge>
typename graph<T, edge>::EdgesIterator graph<T, edge>::endEdges()
{
	return EdgesIterator(this, -1, -1);
}

#pragma endregion 

#pragma region DFSIterator

template <typename T, typename edge>
graph<T, edge>::DFSIterator::DFSIterator(graph* source, int start_at):source_(source),current_(start_at)
{
	visited_.insert(current_);
	stack_.push(current_);
}

template <typename T, typename edge>
bool graph<T, edge>::DFSIterator::operator==(const DFSIterator& i) const
{
	return current_ == i.current_ && source_ == i.source_;
}

template <typename T, typename edge>
bool graph<T, edge>::DFSIterator::operator!=(const DFSIterator& i) const
{
	return current_ != i.current_ || source_ != i.source_;
}

template <typename T, typename edge>
typename graph<T, edge>::DFSIterator& graph<T, edge>::DFSIterator::operator++()
{
	findNextVertex();
	return *this;
}

template <typename T, typename edge>
typename graph<T, edge>::DFSIterator graph<T, edge>::DFSIterator::operator++(int)
{
	DFSIterator temp = DFSIterator(source_,current_);
	findNextVertex();
	return temp;
}

template <typename T, typename edge>
T graph<T, edge>::DFSIterator::operator*()
{
	return source_->vertices[current_];
}

template <typename T, typename edge>
void graph<T, edge>::DFSIterator::findNextVertex()
{

	for (int i = 0; i < source_->nrOfVertices(); i++)
	{
		if (source_->adjacency_matrix[current_][i].connection)
		{
			if (visited_.find(i)==nullptr)
			{
				current_ = i;
				visited_.insert(current_);
				stack_.push(current_);
				return;
			}
		}
	}
	if (stack_.empty())
	{
		current_ = -1;
		return;
	}
	current_ = stack_.top();
	stack_.pop();
	findNextVertex();
}

template <typename T, typename edge>
typename graph<T, edge>::DFSIterator graph<T, edge>::beginDFS(int start_at)
{
	if (start_at<0||start_at>=this->nrOfVertices())
	{
		return DFSIterator(this, -1);
	}
	return DFSIterator(this,start_at);
}

template <typename T, typename edge>
typename graph<T, edge>::DFSIterator graph<T, edge>::endDFS()
{
	return DFSIterator(this, -1);
}

#pragma endregion 


#pragma region BFSIterator

template <typename T, typename edge>
graph<T, edge>::BFSIterator::BFSIterator(graph* source, int start_at) :source_(source), current_(start_at), currentNeighbor_(-1)
{
	visited_.insert(start_at);
}

template <typename T, typename edge>
bool graph<T, edge>::BFSIterator::operator==(const BFSIterator& i) const
{
	return current_ == i.current_ && source_ == i.source_;
}

template <typename T, typename edge>
bool graph<T, edge>::BFSIterator::operator!=(const BFSIterator& i) const
{
	return current_ != i.current_ || source_ != i.source_;
}

template <typename T, typename edge>
typename graph<T, edge>::BFSIterator& graph<T, edge>::BFSIterator::operator++()
{
	findNextVertex();
	return *this;
}

template <typename T, typename edge>
typename graph<T, edge>::BFSIterator graph<T, edge>::BFSIterator::operator++(int)
{
	BFSIterator temp = BFSIterator(source_, current_);
	findNextVertex();
	return temp;
}

template <typename T, typename edge>
T graph<T, edge>::BFSIterator::operator*()
{
	return source_->vertices[currentNeighbor_==-1?current_:currentNeighbor_];
}

template <typename T, typename edge>
void graph<T, edge>::BFSIterator::findNextVertex()
{
	for (int i = currentNeighbor_+1; i < source_->nrOfVertices(); i++)
	{
		if (source_->adjacency_matrix[current_][i].connection)
		{
			if (visited_.find(i) == nullptr)
			{
				currentNeighbor_ = i;
				queue_.push(i);
				visited_.insert(i);
				return;
			}
		}
	}
	currentNeighbor_ = -1;
	if (queue_.empty())
	{
		current_ = -1;
		return;
	}
	current_ = queue_.front();
	queue_.pop();
	findNextVertex();
}

template <typename T, typename edge>
typename graph<T, edge>::BFSIterator graph<T, edge>::beginBFS(int start_at)
{
	if (start_at<0 || start_at >= this->nrOfVertices())
	{
		return BFSIterator(this, -1);
	}
	return BFSIterator(this, start_at);
}

template <typename T, typename edge>
typename graph<T, edge>::BFSIterator graph<T, edge>::endBFS()
{
	return BFSIterator(this, -1);
}

#pragma endregion 


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
