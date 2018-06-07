
#include "betterAVL.h"
#include "avl.h"



int main(int argc, char* argv[])
{
	avl<int> avl1;
	AVL<int> avl2;
	int a = 10;
	avl2.insert(a);
	std::cout << "\n";
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