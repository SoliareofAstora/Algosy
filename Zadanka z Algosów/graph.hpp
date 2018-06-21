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
		edge label;
		bool connection;
		edge_info():connection(false){}
		edge_info(edge& label) :label(label), connection(true) {}
	};
public:
	std::vector<std::vector<edge_info>> adjacency_matrix;
	std::vector<T> vertices;
	graph();

#pragma region Iterators

	typedef typename std::vector<T>::iterator VerticesIterator;
	VerticesIterator beginVertices();
	VerticesIterator endVertices();

	VerticesIterator begin();
	VerticesIterator end();

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

	EdgesIterator insertEdge(int from_index, int destination_index, edge name);
	EdgesIterator insertEdge(int from_index, int destination_index, edge name, bool overwrite);
	VerticesIterator insertVertex(T value);
	VerticesIterator removeVertex(int index);
	EdgesIterator removeEdge(int from_index, int destination_index);

	T* vertexData(int index);
	edge* edgeLabel(int from_index, int destination_index);
	bool edgeExist(int from_index, int destination_index)const;
	size_t nrOfVertices() const;
	size_t nrOfEdges() const;
	void printNeighborhoodMatrix();
};

#pragma region Graph functions

template<typename T, typename edge>
graph<T, edge>::graph() = default;

template <typename T, typename edge>
typename graph<T,edge>::EdgesIterator graph<T, edge>::insertEdge(int from_index, int destination_index, edge name)
{
	return insertEdge(from_index, destination_index, name, false);
}

template <typename T, typename edge>
typename graph<T,edge>::EdgesIterator graph<T, edge>::insertEdge(int from_index, int destination_index, edge name, bool overwrite)
{
	if (from_index >= vertices.size() ||destination_index >= vertices.size() ||from_index<0||destination_index<0)
	{
		return endEdges();
	}
	if (!(adjacency_matrix[from_index][destination_index].connection)||overwrite)
	{
		adjacency_matrix[from_index][destination_index] = edge_info(name);
	}
	return EdgesIterator(this,from_index,destination_index);
}

template <typename T, typename edge>
typename graph<T, edge>::VerticesIterator graph<T, edge>::insertVertex(T value)
{
	vertices.push_back(value);
	adjacency_matrix.push_back(std::vector<edge_info>());
	for(auto &v : adjacency_matrix)
	{
		v.push_back(edge_info());
	}
	adjacency_matrix[vertices.size()-1].resize(vertices.size());
	return endVertices() - 1;
}

template <typename T, typename edge>
typename graph<T, edge>::VerticesIterator graph<T, edge>::removeVertex(int index)
{
	vertices.erase(vertices.begin()+index);
	for(auto &v : adjacency_matrix)
	{
		v.erase(v.begin() + index);
	}
	adjacency_matrix.erase(adjacency_matrix.begin() + index);

	return beginVertices() + index;
}

template <typename T, typename edge>
typename graph<T, edge>::EdgesIterator  graph<T, edge>::removeEdge(int from_index, int destination_index)
{
	adjacency_matrix[from_index][destination_index] = edge_info();
	return EdgesIterator(this, from_index, destination_index);
}

template <typename T, typename edge>
T* graph<T, edge>::vertexData(int index)
{
	if (index<0 || index >= this->nrOfVertices())
	{
		return nullptr;
	}
	return &vertices[index];
}

template <typename T, typename edge>
edge* graph<T, edge>::edgeLabel(int from_index, int destination_index)
{
	if (from_index<0 || from_index >= this->nrOfVertices()|| destination_index<0 || destination_index >= this->nrOfVertices())
	{
		return nullptr;
	}
	return &adjacency_matrix[from_index][destination_index].label;
}

template <typename T, typename edge>
bool graph<T, edge>::edgeExist(int from_index, int destination_index) const
{
	return adjacency_matrix[from_index][destination_index].connection;
}

template <typename T, typename edge>
size_t graph<T, edge>::nrOfVertices() const
{
	return vertices.size();
}

template <typename T, typename edge>
size_t graph<T, edge>::nrOfEdges() const
{
	size_t sum = 0;
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
			std::cout << temp<<" ";
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

template <typename T, typename edge>
typename graph<T, edge>::VerticesIterator graph<T, edge>::begin()
{
	return beginVertices();
}

template <typename T, typename edge>
typename graph<T, edge>::VerticesIterator graph<T, edge>::end()
{
	return endVertices();
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
	return source_->adjacency_matrix[current_.first][current_.second].label;
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
