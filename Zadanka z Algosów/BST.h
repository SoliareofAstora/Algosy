#pragma once

struct node
{
	int key;
	node *left, *right;
};

class BST
{
	int max(int a, int b)
	{
		return a > b ? a : b;
	}
public:
	node * root;
	int Size = 0;

	BST(int item)
	{
		root = newNode(item);
	}

	int size()
	{
		return Size;
	}

	int depth()
	{
		int out = 0;
		return depth(root,out);
	}
	int depth( node* nextNode, int out)
	{
		if (nextNode == nullptr)
		{
			return out;
		}
		else
		{
			out++;
			int temp1 = depth(nextNode->left, out);
			int temp2 = depth(nextNode->right, out);
			return max(temp1, temp2);
		}
	}

	 node *newNode(int item)
	{
		Size++;
		 node *temp =new node;
		temp->key = item;
		temp->left = temp->right = nullptr;
		return temp;
	}

	int minimum()
	{
		return minimum(root);
	} 
	int maximum()
	{
		return maximum(root);
	}

	int minimum( node *nextNode)
	{
		if (nextNode->left==nullptr)
		{
			return nextNode->key;
		}
		return minimum(nextNode->left);
	}

	int maximum( node *nextNode)
	{
		if (nextNode->right == nullptr)
		{
			return nextNode->key;
		}
		return maximum(nextNode->right);
	}

	node* minimumNode( node *nextNode)
	{
		if (nextNode->right == nullptr)
		{
			return nextNode;
		}
		return minimumNode(nextNode->right);
	}
	
	void insert(int key)
	{
		insert(root, key);
	}
	
	 node* insert( node* node, int key)
	{
		if (node == nullptr) return newNode(key);

		if (key < node->key)
			node->left = insert(node->left, key);

		else if (key > node->key)
			node->right = insert(node->right, key);

		return node;
	}

	 node* deleteNode(int key)
	{
		return deleteNode(root, key);
	}

	 node* deleteNode( node* nextNode, int key)
	{
		if (nextNode == NULL) return nextNode;

		if (key < nextNode->key)
			nextNode->left = deleteNode(nextNode->left, key);

		else if (key > nextNode->key)
			nextNode->right = deleteNode(nextNode->right, key);

		else
		{
			if (nextNode->left == NULL)
			{
				 node *temp = nextNode->right;
				delete nextNode;
				return temp;
			}
			else if (nextNode->right == NULL)
			{
				 node *temp = nextNode->left;
				delete nextNode;
				return temp;
			}

			 node* temp = minimumNode(nextNode->right);

			nextNode->key = temp->key;

			nextNode->right = deleteNode(nextNode->right, temp->key);
		}
		return nextNode;
	}

	 node* search(int key)
	{
		return search(root, key);
	}

	 node* search( node*nextNode, int key)
	{
		if (nextNode == nullptr || nextNode->key == key)
			return nextNode;

		if (nextNode->key < key)
			return search(nextNode->right, key);

		return search(nextNode->left, key);
	}

	/*//notworking
	 node* searcht(int key)
	{
		 node* out = root;
		do
		{
			if (out->key == key)
				return out;
			if (out->key < key)
				out = out->right;
			if (out->key > key)
				out = out->left;

		} while (!(out == nullptr));
		return nullptr;
	}*/
	
	/* displaying stuff*/
	 void inorder()
	 {
		 inorder(root);
	 }
	 void inorder(node *nextNode)
	 {
		 if (nextNode != nullptr)
		 {
			 inorder(nextNode->left);
			 printf("%d ", nextNode->key);
			 inorder(nextNode->right);
		 }
	 }
	 void preorder()
	 {
		 preorder(root);
	 }
	 void preorder(node *nextNode)
	 {
		 if (nextNode != nullptr)
		 {
			 printf("%d ", nextNode->key);
			 preorder(nextNode->left);
			 preorder(nextNode->right);
		 }
	 }
	 void postorder()
	 {
		 postorder(root);
	 }
	 void postorder(node *nextNode)
	 {
		 if (nextNode != nullptr)
		 {
			 postorder(nextNode->right);
			 postorder(nextNode->left);
			 printf("%d ", nextNode->key);
		 }
	 }
};