// C program to demonstrate insert operation in binary search tree
#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#include "BST.h"

// Driver Program to test above functions
int main()
{
	BST tree(10);
	tree.insert(50);
	tree.insert(30);
	tree.insert(20);
	tree.insert(40);
	tree.insert(70);
	tree.insert(60);
	tree.insert(80);

	// print inoder traversal of the BST
	tree.inorder();
	std::cerr << std::endl;
	tree.preorder();
	std::cerr << std::endl;
	tree.postorder();
	std::cerr << std::endl;

	node* tmp = nullptr;
	tmp = tree.search(10);
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
	std::cerr << tree.size<<std::endl;


	system("pause");


	return 0;
}