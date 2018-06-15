#pragma once

template <typename T>
struct node
{
	T value;
	node<T>* left;
	node<T>* right;
	int depth;
};

template <typename T>
class avl 
{
	node<T>* root_;
	int size_ = 0;
public:
	avl();
	avl(const avl& source);
	avl& operator =(const avl& source);
	avl(avl&& source) noexcept;
	avl& operator =(avl&& source) noexcept;
	~avl();

	void insert(const T& value);
	const node<T>* find(T &value) const;
	node<T>* find(T &value);
	void remove(const T& value);
	void delete_all();
	node<T>* min_node();
	node<T>* root_node();

	int size();
	int depth();

	class iterator
	{
		avl<T>* tree;
		node<T>* current_;
	public:
		iterator();
		iterator(avl<T>* tree, node<T>* node);
		bool operator ==(const iterator& i);;
		bool operator !=(const iterator& i);
		iterator& operator++();
		iterator operator ++(int);
		T& operator*();

		node<T>* find_parent(node<T>* children);
		node<T>* in_order_successor(node<T>* n);
	};
	iterator begin();
	iterator end();

private:
	node<T>* create_node(const T& value);
	node<T>* insert(node<T>* parent, const T& value);
	node<T>* remove(node<T>* parent, const T& value);
	node<T>* copy(node<T>* parent, node<T>* toCopy);
	node<T>* find(node<T>* next_node, T &value);
	const node<T>* find(node<T>* next_node, T value) const;

	void reset();
	void delete_all(node<T>* parent);
	int max(const int& a, const int& b);
	
	node<T>* min_node(node<T>* parent);
	node<T>* max_node(node<T>* parent);
	int get_balance(node<T>* node);
	int depth(node<T>* node);
	node<T>* right_rotate(node<T>* n);
	node<T>* left_rotate(node<T>* n);


};

template <typename T>
avl<T>::avl() : root_(nullptr), size_(0)
{
}

template <typename T>
avl<T>::avl(const avl<T>& source) : root_(nullptr), size_(source.size_)
{
	root_ = copy(nullptr, source.root_);
}

template <typename T>
avl<T>& avl<T>::operator=(const avl<T>& source)
{
	if (source != this)
	{
		delete_all(root_);
		root_ = copy(nullptr, source.root_);
	}
	return this;
}

template <typename T>
avl<T>::avl(avl<T>&& source) noexcept : root_(source.root_), size_(source.size_)
{
	source.reset();
}


template <typename T>
avl<T>& avl<T>::operator=(avl<T>&& source) noexcept
{
	if (source != this)
	{
		delete_all(root_);
		root_ = copy(nullptr, source.root_);
	}
	return this;
}

template <typename T>
avl<T>::~avl()
{
	delete_all();
	reset();
}

template <typename T>
void avl<T>::insert(const T& value)
{
	size_++;
	root_ = insert(root_, value);
}

template <typename T>
const node<T>* avl<T>::find(T &value) const
{
	return find(root_, value);
}
template <typename T>
node<T>* avl<T>::find(T &value)
{
	return find(root_, value);
}

template <typename T>
void avl<T>::remove(const T& value)
{
	root_ = remove(root_, value);
}
template <typename T>
void avl<T>::delete_all()
{
	delete_all(root_);
}

template <typename T>
int avl<T>::size()
{
	return size_;
}

template <typename T>
int avl<T>::depth()
{
	return depth(root_);
}

template <typename T>
avl<T>::iterator::iterator()
{
	current_ = min_node(root_);
}

template <typename T>
avl<T>::iterator::iterator(avl<T>* tree ,node<T>* node):tree(tree), current_(node){}

template <typename T>
bool avl<T>::iterator::operator==(const iterator& i)
{
	return i.current_ == current_;
}

template <typename T>
bool avl<T>::iterator::operator!=(const iterator& i)
{
	return i.current_ != current_;
}

//pre
template <typename T>
typename avl<T>::iterator& avl<T>::iterator::operator++()
{
	current_ = in_order_successor(current_);
	return *this;
}

//post
template <typename T>
typename avl<T>::iterator avl<T>::iterator::operator++(int)
{
	iterator temp = iterator(tree,current_);
	current_ = in_order_successor(current_);
	return temp;
}

template <typename T>
T& avl<T>::iterator::operator*()
{
	return current_->value;
}

template <typename T>
node<T>* avl<T>::iterator::find_parent(node<T>* children)
{
	auto* current =tree->root_;
	
	while (!(current->left == children || current->right == children))
	{
		if (children->value > current->value)
		{
			current = current->right;
		}
		else
		{
			current = current->left;
		}
	}
	return current;
}

template <typename T>
node<T>* avl<T>::iterator::in_order_successor(node<T>* n)
{

	if (n->right != nullptr || n == tree->root_)
	{
		return tree->min_node(n->right);
	}
	node<T>* parent = find_parent(n);

	if (parent->right == n)
	{
		node<T>* temp;
		do
		{
			temp = parent;
			parent = find_parent(temp);
			if (parent->right == temp && parent == tree->root_)
			{
				return nullptr;
			}
		} while (parent->left != temp);
	}
	return parent;
}

template <typename T>
typename avl<T>::iterator avl<T>::begin()
{
	return iterator(this,min_node(root_));
}

template <typename T>
typename avl<T>::iterator avl<T>::end()
{
	return iterator(this,nullptr);
}

template <typename T>
node<T>* avl<T>::create_node(const T& value)
{
	node<T>* new_node = new node<T>;
	new_node->value = value;
	new_node->left = nullptr;
	new_node->right = nullptr;
	new_node->depth = 1;
	return new_node;
}

template <typename T>
node<T>* avl<T>::insert(node<T>* parent, const T& value)
{
	if (parent == nullptr)
		return create_node(value);

	if (value < parent->value)
		parent->left = insert(parent->left, value);
	else if (value > parent->value)
		parent->right = insert(parent->right, value);
	else
		return parent;

	parent->depth = 1 + max(depth(parent->left), depth(parent->right));

	int balance = get_balance(parent);

	// Left Left case
	if (balance > 1 && value < parent->left->value)
		return right_rotate(parent);

	// Right Right case
	if (balance < -1 && value > parent->right->value)
		return left_rotate(parent);

	// Left Right case
	if (balance > 1 && value > parent->left->value)
	{
		parent->left = left_rotate(parent->left);
		return right_rotate(parent);
	}

	// Right Left case
	if (balance < -1 && value < parent->right->value)
	{
		parent->right = right_rotate(parent->right);
		return left_rotate(parent);
	}
	return parent;
}

template <typename T>
node<T>* avl<T>::remove(node<T>* parent, const T& value)
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
			node<T>* temp = parent->left ? parent->left :
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
			node<T>* temp = min_node(parent->right);
			parent->value = temp->value;
			parent->right = remove(parent->right, temp->value);
		}
	}

	if (parent == nullptr)
		return nullptr;

	parent->depth = 1 + max(depth(parent->left), depth(parent->right));

	int balance = get_balance(parent);

	//Left Left case
	if (balance > 1 && get_balance(parent->left) >= 0)
		return right_rotate(parent);

	// Left Right Case
	if (balance > 1 && get_balance(parent->left) < 0)
	{
		parent->left = left_rotate(parent->left);
		return right_rotate(parent);
	}

	// Right Right Case
	if (balance < -1 && get_balance(parent->right) <= 0)
		return left_rotate(parent);

	// Right Left Case
	if (balance < -1 && get_balance(parent->right) > 0)
	{
		parent->right = right_rotate(parent->right);
		return left_rotate(parent);
	}

	return parent;
}

template <typename T>
node<T>* avl<T>::copy(node<T>* parent, node<T>* toCopy)
{
	if (toCopy != nullptr)
	{
		parent = new node<T>;
		parent->value = toCopy->value;
		parent->left = copy(parent->left, toCopy->left);
		parent->right = copy(parent->right, toCopy->right);
	}
	return parent;
}

template <typename T>
node<T>* avl<T>::find(node<T>* next_node, T &value)
{
	if (next_node == nullptr || next_node->value == value)
		return next_node;

	if (next_node->value < value)
		return find(next_node->right, value);

	return find(next_node->left, value);
}

template <typename T>
const node<T>* avl<T>::find(node<T>* next_node, T value) const
{
	if (next_node == nullptr || next_node->value == value)
		return next_node;

	if (next_node->value < value)
		return find(next_node->right, value);

	return find(next_node->left, value);
}

template <typename T>
void avl<T>::reset()
{
	root_ = nullptr;
	size_ = 0;
}

template <typename T>
void avl<T>::delete_all(node<T>* parent)
{
	if (parent != nullptr)
	{
		delete_all(parent->left);
		delete_all(parent->right);
		delete parent;
	}
}

template <typename T>
int avl<T>::max(const int& a, const int& b)
{
	return a > b ? a : b;
}

template <typename T>
node<T>* avl<T>::min_node()
{
	return min_node(root_);
}

template <typename T>
node<T>* avl<T>::root_node()
{
	return root_;
}


template <typename T>
node<T>* avl<T>::min_node(node<T>* parent)
{
	//TODO possible data leak
	node<T>* temp = parent;
	while (temp->left != nullptr)
	{
		temp = temp->left;
	}
	return temp;
}

template <typename T>
node<T>* avl<T>::max_node(node<T>* parent)
{
	//TODO possible data leak
	node<T>* temp = parent;
	while (temp->right != nullptr)
	{
		temp = temp->right;
	}
	return temp;
}

template <typename T>
int avl<T>::get_balance(node<T>* node)
{
	if (node == nullptr)
		return 0;
	return depth(node->left) - depth(node->right);
}

template <typename T>
int avl<T>::depth(node<T>* node)
{
	if (node == nullptr) return 0;
	return node->depth;
}

template <typename T>
node<T>* avl<T>::right_rotate(node<T>* n)
{
	node<T>* left = n->left;
	node<T>* left_right = left->right;

	left->right = n;
	n->left = left_right;

	n->depth = max(depth(n->left), depth(n->right)) + 1;
	left->depth = max(depth(left->left), depth(left->right)) + 1;

	return left;
}

template <typename T>
node<T>* avl<T>::left_rotate(node<T>* n)
{
	node<T>* right = n->right;
	node<T>* right_left = right->left;

	right->left = n;
	n->right = right_left;

	n->depth = max(depth(n->left), depth(n->right)) + 1;
	right->depth = max(depth(right->left), depth(right->right)) + 1;

	return right;
}

#pragma once
