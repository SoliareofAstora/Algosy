
#include "betterAVL.h"
#include "avl.h"
#include <iostream>


int main(int argc, char* argv[])
{
	
	avl<int> avl1;
	AVL<int> avl2;
	int a[] = {0,1,2};
	for (int i = 0; i < 12;i++)//sizeof(a)/sizeof(int); i++)
	{
		avl2.insert(i);
		avl1.insert(i);
	}
	//std::cout << avl2.find(2)->value << "\n";
	std::cout << "root: " << avl2.root_node()->value<<"\n";
	std::cout << "root: " << avl1.root_node()->value << "\n";
	for (auto v_it = avl2.begin_memory_iterator(); v_it != avl2.end_memory_iterator(); ++v_it)
	{
		auto value = *v_it;
	}
	/*
	for (int j = 0; j < 100; ++j)
	{		
		for (int i = 0; i < 10000; ++i)
		{
			avl1.insert(i);
		}
		for (int i = 0; i < 10000; ++i)
		{
			avl1.find(i);
		}
		for (int i = 0; i < 10000; ++i)
		{
			avl1.remove(i);
		}
	}
	*/
	std::cout << "DONE\n";
	system("PAUSE");
	return 0;
}

/*
// C++ program to illustrate the placement new operator
#include<iostream>
using namespace std;
 
int main()
{
    // buffer on stack
    unsigned char buf[sizeof(int)*2] ;
 
    // placement new in buf
    int *pInt = new (buf) int(3);
 
    int *qInt = new (buf + sizeof (int)) int(5);
    int *pBuf = (int*)(buf+0);
    int *qBuf = (int*) (buf + sizeof(int));
    cout << "Buff Addr             Int Addr" << endl;
    cout << pBuf <<"             " << pInt << endl;
    cout << qBuf <<"             " << qInt << endl;
    cout << "------------------------------" << endl;
    cout << "1st Int           2nd Int" << endl;
    cout << *pBuf << "                         "
         << *qBuf << endl;
 
    return 0;
}

 */