#pragma once
#include <string>
#include<stdio.h>
#include<stdlib.h>

struct Node
{
	std::string key;
	 Node *left;
	 Node *right;
	int depth;
};

class AVL
{
public:
	int max(int a, int b)
	{
		return a > b ? a : b;
	}
	std::string max(std::string a, std::string b)
	{
		return a.compare(b) > 0 ? a : b;
	}
	bool equals(std::string a, std::string b)
	{
		return a.compare(b) == 0;
	}

	Node * root;
	int Size = 0;

	AVL(std::string item)
	{
		root = newNode(item);
	}

	int size()
	{
		return Size;
	}

	int depth()
	{
		return depth(root);
	}

	int depth(Node *node)
	{
		if (node == NULL) return 0;
		return node->depth;
	}

	Node* newNode(std::string key)
	{
		Node* node = new Node;
		node->key = key;
		node->left = NULL;
		node->right = NULL;
		node->depth = 1;
		return(node);
	}
	Node* insert(Node* nextNode, std::string  key)
	{
		if (nextNode == NULL)
			return newNode(key);

		if (key < nextNode->key)
			nextNode->left = insert(nextNode->left, key);
		else if (key > nextNode->key)
			nextNode->right = insert(nextNode->right, key);
		else
			return nextNode;

		nextNode->depth = 1 + max(depth(nextNode->left), depth(nextNode->right));

		int balance = getBalance(nextNode);

		// Left Left 
		if (balance > 1 && key < nextNode->left->key)
			return rightRotate(nextNode);

		// Right Right 
		if (balance < -1 && key > nextNode->right->key)
			return leftRotate(nextNode);

		// Left Right 
		if (balance > 1 && key > nextNode->left->key)
		{
			nextNode->left = leftRotate(nextNode->left);
			return rightRotate(nextNode);
		}

		// Right Left 
		if (balance < -1 && key < nextNode->right->key)
		{
			nextNode->right = rightRotate(nextNode->right);
			return leftRotate(nextNode);
		}

		return nextNode;
	}
	Node *rightRotate(Node *node)
	{
		std::cerr << "rotate right\n";
		Node *left = node->left;
		Node *left_right = left->right;

		left->right = node;
		node->left = left_right;

		node->depth = max(depth(node->left), depth(node->right)) + 1;
		left->depth = max(depth(left->left), depth(left->right)) + 1;

		return left;
	}

	Node *leftRotate(Node *node)
	{
		std::cerr << "rotate left\n";
		Node *right = node->right;
		Node *right_left = right->left;

		right->left = node;
		node->right = right_left;

		node->depth = max(depth(node->left), depth(node->right)) + 1;
		right->depth = max(depth(right->left), depth(right->right)) + 1;

		return right;
	}

	int getBalance(Node *node)
	{
		if (node == NULL)
			return 0;
		return depth(node->left) - depth(node->right);
	}

	void insert(std::string  key)
	{
		Size++;
		insert(root, key);
	}


	Node* search(std::string key)
	{
		return search(root, key);
	}

	Node* search(Node*nextNode, std::string key)
	{
		if (nextNode == nullptr || equals(nextNode->key,key))
			return nextNode;

		if (nextNode->key.compare(key)<0)
			return search(nextNode->right, key);

		return search(nextNode->left, key);
	}

	void inorder()
	{
		inorder(root);
	}
	void inorder(Node *nextNode)
	{
		if (nextNode != NULL)
		{
			inorder(nextNode->left);
			printf("%s \n", nextNode->key.c_str());
			inorder(nextNode->right);
		}
	}
	void preorder()
	{
		preorder(root);
	}
	void preorder(Node *nextNode)
	{
		if (nextNode != NULL)
		{
			printf("%s \n", nextNode->key.c_str());
			preorder(nextNode->left);
			preorder(nextNode->right);
		}
	}
	void postorder()
	{
		postorder(root);
	}
	void postorder(Node *nextNode)
	{
		if (nextNode != NULL)
		{
			postorder(nextNode->right);
			postorder(nextNode->left);
			printf("%s \n", nextNode->key.c_str());
		}
	}
};