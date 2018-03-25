#pragma once
#include <iostream>
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
	bool succesfullyDeleted = false;

	int max(const int &a,const  int &b);
	Node<T>* addNode(const T &value);
	Node<T>* insert(Node<T>* parent,const T &value);
	Node<T>* rightRotate(Node<T>* value);
	Node<T>* leftRotate(Node<T>* value);
	Node<T>* minNode(Node<T>* parent);
	Node<T>* remove(Node<T>* parent, const T &value);

public:
	AVL();
	AVL(const AVL& source);
	AVL& operator =(const AVL&source);
	AVL(AVL&& source);
	AVL& operator =(AVL&&source);
	
	int size();
	int depth();
	int depth(Node<T>* node);

	int getBalance(Node<T>* node);
	void insert(const T &value);
	Node<T>* find(T value);
	Node<T>* find(Node<T>* nextNode, T value);
	bool remove(const T &value);
	
	/*
	void inorder()
	{
		inorder(root);
	}
	void inorder(Node<T>*parent)
	{
		if (parent != nullptr)
		{
			inorder(parent->left);
			printf("%s \n", parent->value.c_str());
			inorder(parent->right);
		}
	}
	void preorder()
	{
		preorder(root);
	}
	void preorder(Node<T>*parent)
	{
		if (parent != nullptr)
		{
			printf("%s \n", parent->value.c_str());
			preorder(parent->left);
			preorder(parent->right);
		}
	}
	void postorder()
	{
		postorder(root);
	}
	void postorder(Node<T>*parent)
	{
		if (parent != nullptr)
		{
			postorder(parent->right);
			postorder(parent->left);
			printf("%s \n", parent->value.c_str());
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
Node<T>* AVL<T>::addNode(const T &value)
{
	Node<T>* node = new Node<T>;
	node->value = value;
	node->left = nullptr;
	node->right = nullptr;
	node->depth = 1;
	return node;
}

template <typename T>
Node<T>* AVL<T>::insert(Node<T>* parent,const T &value)
{

	if (parent == nullptr)
		return addNode(value);

	if (value < parent->value)
		parent->left = insert(parent->left, value);
	else if (value > parent->value)
		parent->right = insert(parent->right, value);
	else
		return parent;

	parent->depth = 1 + max(depth(parent->left), depth(parent->right));

	int balance = getBalance(parent);

	// Left Left 
	if (balance > 1 && value < parent->left->value)
		return rightRotate(parent);

	// Right Right 
	if (balance < -1 && value > parent->right->value)
		return leftRotate(parent);

	// Left Right 
	if (balance > 1 && value > parent->left->value)
	{
		parent->left = leftRotate(parent->left);
		return rightRotate(parent);
	}

	// Right Left 
	if (balance < -1 && value < parent->right->value)
	{
		parent->right = rightRotate(parent->right);
		return leftRotate(parent);
	}

	return parent;
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
Node<T>* AVL<T>::minNode(Node<T>* parent)
{
	Node<T> *temp = parent;

	while (temp->right!= nullptr)
	{
		temp = temp->left;
	}
	return temp;
}


template <typename T>
AVL<T>::AVL(): root(nullptr)
{
}

template <typename T>
AVL<T>::AVL(const AVL<T>& source):root(source.root),Size(source.Size)
{
}

template <typename T>
AVL<T>::AVL(AVL<T>&& source): root(source.root), Size(source.Size)
{
}

template <typename T>
AVL<T>& AVL<T>::operator=(AVL<T>&& source)
{
	return {};
}

template <typename T>
AVL<T>& AVL<T>::operator=(const AVL<T>& source)
{
	return {};
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
Node<T>* AVL<T>::find(T value)
{
	return find(root, value);
}

template <typename T>
Node<T>* AVL<T>::find(Node<T>* nextNode, T value)
{
	if (nextNode == nullptr || nextNode->value == value)
		return nextNode;

	if (nextNode->value < value)
		return find(nextNode->right, value);

	return find(nextNode->left, value);
}

template <typename T>
bool AVL<T>::remove(const T& value)
{
	succesfullyDeleted = false;
	root = remove(root, value);
	return succesfullyDeleted;
}


template <typename T>
Node<T>* AVL<T>::remove(Node<T>* parent,const  T &value)
{
	if (parent == nullptr)
		return nullptr;

	if (value < parent->value)
		parent->left = remove(parent->left, value);

	else if (value > parent->value)
		parent->right = remove(parent->right, value);

	else
	{
		
		// node with only one child or no child
		if ((parent->left == nullptr) || (parent->right == nullptr))
		{
			std::cout << "kasujemy niepe³ny wêze³\n";
			Node<T>* temp = parent->left ? parent->left :
				parent->right;

			if (temp == nullptr)
			{
				temp = parent;
				parent = nullptr;
			}
			else
				*parent = *temp; 
			delete temp;
		}
		else
		{
			std::cout << "kasujemy pe³ny node \n";
			Node<T>* temp = minNode(parent->right);

			parent->value = temp->value;

			parent->right = remove(parent->right, temp->value);
		}
	}

	std::cout << "kasowanie skoñczone\n";
	if (parent == nullptr)
		return nullptr;

	parent->depth = 1 + max(depth(parent->left),depth(parent->right));

	int balance = getBalance(parent);

	// Left Left Case
	if (balance > 1 && getBalance(parent->left) >= 0)
		return rightRotate(parent);

	// Left Right Case
	if (balance > 1 && getBalance(parent->left) < 0)
	{
		parent->left = leftRotate(parent->left);
		return rightRotate(parent);
	}

	// Right Right Case
	if (balance < -1 && getBalance(parent->right) <= 0)
		return leftRotate(parent);

	// Right Left Case
	if (balance < -1 && getBalance(parent->right) > 0)
	{
		parent->right = rightRotate(parent->right);
		return leftRotate(parent);
	}

	return parent;
}