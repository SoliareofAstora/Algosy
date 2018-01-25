// C program to demonstrate insert operation in binary search tree
#include <stdlib.h>
#include <iostream>
#include "BST.h"

// Driver Program to test above functions
int main()
{
	BST tree=BST(10);
	tree.insert(35);
	std::cerr << tree.depth() << std::endl;
	tree.insert(50);
	tree.insert(30);
	tree.insert(20);
	std::cerr << tree.depth() << std::endl;
	tree.insert(40);
	tree.insert(70);
	tree.insert(60);
	std::cerr << tree.depth() << std::endl;
	tree.insert(80);
	tree.insert(51);
	std::cerr << tree.depth() << std::endl;

	// print inoder traversal of the BST
	tree.inorder();
	std::cerr << std::endl;
	tree.preorder();
	std::cerr << std::endl;
	tree.postorder();
	std::cerr << std::endl;

	node* tmp = nullptr;
	tmp = tree.search(30);
	if (tmp == nullptr)
	{
		std::cerr <<"nie ma takiej wartoœci\n";
	}
	else
	{
		std::cerr << "znaleziono\n";
	}
	tmp = tree.search(20);
	if (tmp == nullptr)
	{
		std::cerr << "nie ma takiej wartoœci\n";
	}
	else
	{
		std::cerr << "znaleziono\n";
	}
	tmp = tree.search(80);
	if (tmp == nullptr)
	{
		std::cerr << "nie ma takiej wartoœci\n";
	}
	else
	{
		std::cerr << "znaleziono\n";
	}

	std::cerr << tree.depth() << std::endl;
	std::cerr << tree.size() << std::endl;
	std::cerr << tree.minimum() << std::endl;
	std::cerr << tree.maximum() << std::endl;


	system("pause");


	return 0;
}