#pragma once
template <typename T>
struct Node
{
	T value;
	Node<T>* left;
	Node<T>* right;
	int depth;
};

template <typename T>
class AVL
{
	Node<T>* root;
	int Size = 0;
	bool succesfullyDeleted = false;
	Node<T>* itemadded;

public:
	AVL();
	AVL(const AVL& source);
	AVL& operator =(const AVL& source);
	AVL(AVL&& source) noexcept;
	AVL& operator =(AVL&& source) noexcept;
	~AVL();

	Node<T>* insert(const T& value);
	bool remove(const T& value);
	Node<T>* find(T value);
	const Node<T>* find(T value) const;
	void deleteAll();

	int size();
	int depth();

private:
	Node<T>* addNode(const T& value);
	Node<T>* insert(Node<T>* parent, const T& value);
	Node<T>* remove(Node<T>* parent, const T& value);
	Node<T>* copy(Node<T>* parent, Node<T>* toCopy);
	Node<T>* find(Node<T>* nextNode, T value);
	const Node<T>* find(Node<T>* nextNode, T value) const;

	Node<T>* minNode(Node<T>* parent);
	int getBalance(Node<T>* node);
	int depth(Node<T>* node);

	Node<T>* rightRotate(Node<T>* value);
	Node<T>* leftRotate(Node<T>* value);

	void reset();
	void deleteAll(Node<T>* parent);
	int max(const int& a, const int& b);
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
Node<T>* AVL<T>::addNode(const T& value)
{
	Node<T>* node = new Node<T>;
	itemadded = node;
	node->value = value;
	node->left = nullptr;
	node->right = nullptr;
	node->depth = 1;
	return node;
}

template <typename T>
Node<T>* AVL<T>::insert(Node<T>* parent, const T& value)
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

	// Left Left case
	if (balance > 1 && value < parent->left->value)
		return rightRotate(parent);

	// Right Right case
	if (balance < -1 && value > parent->right->value)
		return leftRotate(parent);

	// Left Right case
	if (balance > 1 && value > parent->left->value)
	{
		parent->left = leftRotate(parent->left);
		return rightRotate(parent);
	}

	// Right Left case
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
	Node<T>* temp = parent;
	while (temp->left != nullptr)
	{
		temp = temp->left;
	}
	return temp;
}


template <typename T>
AVL<T>::AVL(): root(nullptr),Size(0)
{
}

template <typename T>
Node<T>* AVL<T>::copy(Node<T>* parent, Node<T>* toCopy)
{
	if (toCopy != nullptr)
	{
		parent = new Node<T>;
		parent->value = toCopy->value;
		parent->left = copy(parent->left, toCopy->left);
		parent->right = copy(parent->right, toCopy->right);
	}
	return parent;
}

template <typename T>
AVL<T>::AVL(const AVL<T>& source) : root(nullptr), Size(source.Size)
{
	root = copy(nullptr, source.root);
}

template <typename T>
AVL<T>::AVL(AVL<T>&& source) noexcept : root(source.root), Size(source.Size)
{
	source.reset();
}


template <typename T>
AVL<T>& AVL<T>::operator=(const AVL<T>& source)
{
	if (source != this)
	{
		deleteAll(root);
		root = copy(nullptr, source.root);
	}
	return this;
}

template <typename T>
AVL<T>& AVL<T>::operator=(AVL<T>&& source) noexcept
{
	if (source != this)
	{
		deleteAll(root);
		root = copy(nullptr, source.root);
	}
	return this;
}

template <typename T>
AVL<T>::~AVL()
{
	deleteAll();
	reset();
}

template <typename T>
int AVL<T>::getBalance(Node<T>* node)
{
	if (node == nullptr)
		return 0;
	return depth(node->left) - depth(node->right);
}

template <typename T>
Node<T>* AVL<T>::insert(const T& value)
{
	Size++;
	itemadded = nullptr;
	root = insert(root, value);
	return itemadded;
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
const Node<T>* AVL<T>::find(T value) const
{
	return find(root, value);
}

template <typename T>
void AVL<T>::deleteAll()
{
	deleteAll(root);
}

template <typename T>
const Node<T>* AVL<T>::find(Node<T>* nextNode, T value) const
{
	if (nextNode == nullptr || nextNode->value == value)
		return nextNode;

	if (nextNode->value < value)
		return find(nextNode->right, value);

	return find(nextNode->left, value);
}

template <typename T>
void AVL<T>::reset()
{
	root = nullptr;
	Size = 0;
	succesfullyDeleted = false;
	itemadded = nullptr;
}

template <typename T>
void AVL<T>::deleteAll(Node<T>* parent)
{
	if (parent != nullptr)
	{
		deleteAll(parent->left);
		deleteAll(parent->right);
		delete parent;
	}
}

template <typename T>
bool AVL<T>::remove(const T& value)
{
	succesfullyDeleted = false;
	root = remove(root, value);
	return succesfullyDeleted;
}


template <typename T>
Node<T>* AVL<T>::remove(Node<T>* parent, const T& value)
{
	if (parent == nullptr)
		return nullptr;

	if (value < parent->value)
		parent->left = remove(parent->left, value);

	else if (value > parent->value)
		parent->right = remove(parent->right, value);

	else
	{
		if ((parent->left == nullptr) || (parent->right == nullptr))
		{
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
			Node<T>* temp = minNode(parent->right);
			parent->value = temp->value;
			parent->right = remove(parent->right, temp->value);
		}
	}

	if (parent == nullptr)
		return nullptr;

	parent->depth = 1 + max(depth(parent->left), depth(parent->right));

	int balance = getBalance(parent);

	//Left Left case
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
