#include <iostream>
#include "avl.h"
int main(int argc, char* argv[])
{
	avl<int> AvlTree;
	AvlTree.insert(10);
	AvlTree.insert(11);
	AvlTree.insert(12);
	AvlTree.insert(13);
	AvlTree.insert(14);
	AvlTree.insert(15);
	int temp = 13;
	if (AvlTree.find(temp)!=nullptr)
	{
		std::cout << "znaleziono\n";
	}
	else { std::cout << "nie znaleziono!!\n"; }

	avl<int> avl2=std::move(AvlTree);
	if (avl2.find(temp) != nullptr)
	{
		std::cout << "znaleziono\n";
	}
	else { std::cout << "nie znaleziono!!!\n"; }

	char b;
	std::cin>>b;
	return 0;
}
