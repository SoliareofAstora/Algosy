#include <stdlib.h>
#include <iostream>
#include "BST.h"
#include "AVL.h"

void testBST()
{

	BST tree = BST(10);
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
	tree.deleteNode(80);

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
		std::cerr << "nie ma takiej warto�ci\n";
	}
	else
	{
		std::cerr << "znaleziono\n";
	}
	tmp = tree.search(20);
	if (tmp == nullptr)
	{
		std::cerr << "nie ma takiej warto�ci\n";
	}
	else
	{
		std::cerr << "znaleziono\n";
	}
	tmp = tree.search(80);
	if (tmp == nullptr)
	{
		std::cerr << "nie ma takiej warto�ci\n";
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
}
void testAVL()
{
	AVL tree("mama");

	tree.insert("pawe�");	std::cerr << "p\n";
	tree.insert("abecadlo");	std::cerr << "c\n";
	tree.insert("tree"); std::cerr << "t\n";
	tree.insert("given"); std::cerr << "g\n";
	tree.insert("in");	std::cerr << "i\n";
	tree.insert("tata");	std::cerr << "a\n";
	std::cerr << tree.depth() << std::endl;


	tree.inorder();
	std::cerr << std::endl;
	tree.preorder();
	std::cerr << std::endl;
	tree.postorder();
	std::cerr << std::endl;
	Node* tmp;
	tmp = tree.search("mama");
	if (tmp == nullptr)
	{
		std::cerr << "nie ma takiej warto�ci\n";
	}
	else
	{
		std::cerr << "znaleziono\n";
	}
	tmp = tree.search("in");
	if (tmp == nullptr)
	{
		std::cerr << "nie ma takiej warto�ci\n";
	}
	else
	{
		std::cerr << "znaleziono\n";
	}
	tmp = tree.search("tree");
	if (tmp == nullptr)
	{
		std::cerr << "nie ma takiej warto�ci\n";
	}
	else
	{
		std::cerr << "znaleziono\n";
	}


	system("pause");
}

int main()
{

	//testBST();
	testAVL();
	return 0;
}
