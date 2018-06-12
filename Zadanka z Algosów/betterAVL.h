#pragma once
#include "MemoryBlock.h"

template<typename T>
class AVL
{
	template<typename T>
	struct node
	{
		T value;
		int left;
		int right;
		int parent;
		int depth;
		node(const T& input,int&parent):value(input),left(-1),right(-1),parent(parent),depth(0){}
	};



};


