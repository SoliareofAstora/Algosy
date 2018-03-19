#include <iostream>
#include "AVL.h"
int main(int argc, char* argv[])
{
	AVL<int> avl;
	avl.insert(10);
	avl.insert(9);
	avl.insert(14);
	avl.insert(11);
	avl.insert(16);
	if (avl.search(10)!=nullptr)
	{
		std::cout << "znaleziono";
	}
	else { std::cout << "nie znaleziono"; }

	char b;
	std::cin>>b;
	return 0;
}
