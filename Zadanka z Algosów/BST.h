#pragma once

struct node
{
	int key;
	node *left, *right;
};
/*
insert(x) - wstawia element 'x' do drzewa
search(x), searchRecursive(x) - sprawdza czy element nale¿y do drzewa, zwraca wskaŸnik do wêz³a lub nullptr.Napisaæ wersjê iteracyjn¹ i rekurencyjn¹
size() - zwraca liczbê wêz³ów
minimum() - zwraca wartoœæ najmniejszego elementu
maximum() - zwraca wartoœæ najwiêkszego elementu
depth() - zwraca wysokoœæ drzewa
*/
class BST
{
public:
	node * root;
	int Size = 0;

	BST() :root(NULL) {};
	BST(int item)
	{
		root = newNode(item);
	}

	int size()
	{
		return Size;
	}

	struct node *newNode(int item)
	{
		Size++;
		struct node *temp = static_cast<struct node *>(malloc(sizeof(struct node)));
		temp->key = item;
		temp->left = temp->right = NULL;
		return temp;
	}



	/* displaying stuff*/
	void inorder()
	{
		inorder(root);
	}
	void inorder(struct node *newnode)
	{
		if (newnode != NULL)
		{
			inorder(newnode->left);
			printf("%d ", newnode->key);
			inorder(newnode->right);
		}
	}
	void preorder()
	{
		preorder(root);
	}
	void preorder(struct node *newnode)
	{
		if (newnode != NULL)
		{
			printf("%d ", newnode->key);
			preorder(newnode->left);
			preorder(newnode->right);
		}
	}
	void postorder()
	{
		postorder(root);
	}
	void postorder(struct node *newnode)
		{
			if (newnode != NULL)
			{
				postorder(newnode->right);
				postorder(newnode->left);
				printf("%d ", newnode->key);
			}
		}
	
	void insert(int key)
	{
		insert(root, key);
	}
	
	struct node* insert(struct node* node, int key)
	{
		if (node == NULL) return newNode(key);

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

	struct node* searchRecursive(struct node*root, int key)
	{
		if (root == NULL || root->key == key)
			return root;

		if (root->key < key)
			return searchRecursive(root->right, key);

		return searchRecursive(root->left, key);
	}

	struct node* search(int key)
	{
		return search(root, key);
	}

	struct node* search(struct node*root, int key)
	{
		if (root == NULL || root->key == key)
			return root;

		if (root->key < key)
			return searchRecursive(root->right, key);

		return searchRecursive(root->left, key);
	}

};