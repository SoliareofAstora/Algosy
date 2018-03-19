#pragma once
#include <string>
#include<stdio.h>
#include<stdlib.h>



template<typename T>
struct Node
{
	T value;
	Node<T>*left;
	Node<T>*right;
	int depth;
};

template<typename T>
class AVL
{
	Node<T>* root;
	int Size = 0;

	int max(const int &a,const  int &b);
	Node<T>* newNode(const T &value);
	Node<T>* insert(Node<T>* nextNode,const T &value);
	Node<T>* rightRotate(Node<T>* value);
	Node<T>* leftRotate(Node<T>* value);

public:
	AVL();
	int size();
	int depth();
	int depth(Node<T>* node);

	int getBalance(Node<T>* node);
	void insert(const T &value);
	Node<T>* search(T key);
	Node<T>* search(Node<T>* nextNode, T key);
	
	/*
	void inorder()
	{
		inorder(root);
	}
	void inorder(Node<T>*nextNode)
	{
		if (nextNode != nullptr)
		{
			inorder(nextNode->left);
			printf("%s \n", nextNode->value.c_str());
			inorder(nextNode->right);
		}
	}
	void preorder()
	{
		preorder(root);
	}
	void preorder(Node<T>*nextNode)
	{
		if (nextNode != nullptr)
		{
			printf("%s \n", nextNode->value.c_str());
			preorder(nextNode->left);
			preorder(nextNode->right);
		}
	}
	void postorder()
	{
		postorder(root);
	}
	void postorder(Node<T>*nextNode)
	{
		if (nextNode != nullptr)
		{
			postorder(nextNode->right);
			postorder(nextNode->left);
			printf("%s \n", nextNode->value.c_str());
		}
	}
	*/
};

template <typename T>
int AVL<T>::size()
{
	return Size;
}

template <typename T>
int AVL<T>::depth()
{
	return depth(root);
}

template <typename T>
int AVL<T>::depth(Node<T>* node)
{
	if (node == nullptr) return 0;
	return node->depth;
}


template <typename T>
int AVL<T>::max(const int& a, const int& b)
{
	return a > b ? a : b;
}

template <typename T>
Node<T>* AVL<T>::newNode(const T &value)
{
	Node<T>* node = new Node<T>;
	node->value = value;
	node->left = nullptr;
	node->right = nullptr;
	node->depth = 1;
	return (node);
}

template <typename T>
Node<T>* AVL<T>::insert(Node<T>* nextNode,const T &value)
{
	if (nextNode == nullptr)
		return newNode(value);

	if (value < nextNode->value)
		nextNode->left = insert(nextNode->left, value);
	else if (value > nextNode->value)
		nextNode->right = insert(nextNode->right, value);
	else
		return nextNode;

	nextNode->depth = 1 + max(depth(nextNode->left), depth(nextNode->right));

	int balance = getBalance(nextNode);

	// Left Left 
	if (balance > 1 && value < nextNode->left->value)
		return rightRotate(nextNode);

	// Right Right 
	if (balance < -1 && value > nextNode->right->value)
		return leftRotate(nextNode);

	// Left Right 
	if (balance > 1 && value > nextNode->left->value)
	{
		nextNode->left = leftRotate(nextNode->left);
		return rightRotate(nextNode);
	}

	// Right Left 
	if (balance < -1 && value < nextNode->right->value)
	{
		nextNode->right = rightRotate(nextNode->right);
		return leftRotate(nextNode);
	}
	return nextNode;
}

template <typename T>
Node<T>* AVL<T>::rightRotate(Node<T>* node)
{
	Node<T>* left = node->left;
	Node<T>* left_right = left->right;

	left->right = node;
	node->left = left_right;

	node->depth = max(depth(node->left), depth(node->right)) + 1;
	left->depth = max(depth(left->left), depth(left->right)) + 1;

	return left;
}

template <typename T>
Node<T>* AVL<T>::leftRotate(Node<T>* node)
{
	Node<T>* right = node->right;
	Node<T>* right_left = right->left;

	right->left = node;
	node->right = right_left;

	node->depth = max(depth(node->left), depth(node->right)) + 1;
	right->depth = max(depth(right->left), depth(right->right)) + 1;

	return right;
}

template <typename T>
AVL<T>::AVL(): root(nullptr)
{
}

template <typename T>
int AVL<T>::getBalance(Node<T>* node)
{
	if (node == nullptr)
		return 0;
	return depth(node->left) - depth(node->right);
}

template <typename T>
void AVL<T>::insert(const T &value)
{
	Size++;
	root = insert(root, value);
}

template <typename T>
Node<T>* AVL<T>::search(T key)
{
	return search(root, key);
}

template <typename T>
Node<T>* AVL<T>::search(Node<T>* nextNode, T key)
{
	if (nextNode == nullptr || nextNode->value == key)
		return nextNode;

	if (nextNode->value < key)
		return search(nextNode->right, key);

	return search(nextNode->left, key);
}
