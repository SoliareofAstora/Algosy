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

	BST(){};
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
	int depth(struct node* nextNode, int out)
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

	struct node *newNode(int item)
	{
		Size++;
		struct node *temp = static_cast<struct node *>(malloc(sizeof(struct node)));
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

	int minimum(struct node *nextNode)
	{
		if (nextNode->left==nullptr)
		{
			return nextNode->key;
		}
		return minimum(nextNode->left);
	}

	int maximum(struct node *nextNode)
	{
		if (nextNode->right == nullptr)
		{
			return nextNode->key;
		}
		return maximum(nextNode->right);
	}

	/* displaying stuff*/
	void inorder()
	{
		inorder(root);
	}
	void inorder(struct node *nextNode)
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
	void preorder(struct node *nextNode)
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
	void postorder(struct node *nextNode)
	{
		if (nextNode != nullptr)
		{
			postorder(nextNode->right);
			postorder(nextNode->left);
			printf("%d ", nextNode->key);
		}
	}
	
	void insert(int key)
	{
		insert(root, key);
	}
	
	struct node* insert(struct node* node, int key)
	{
		if (node == nullptr) return newNode(key);

		if (key < node->key)
			node->left = insert(node->left, key);

		else if (key > node->key)
			node->right = insert(node->right, key);

		return node;
	}

	struct node* searchRecursive(int key)
	{
		return searchRecursive(root, key);
	}

	struct node* searchRecursive(struct node*nextNode, int key)
	{
		if (nextNode == nullptr || nextNode->key == key)
			return nextNode;

		if (nextNode->key < key)
			return searchRecursive(nextNode->right, key);

		return searchRecursive(nextNode->left, key);
	}

	struct node* search(int key)
	{
		node* out = root;
		do
		{
			
		} while (false);
		return nullptr;
	}
};