
#include "betterAVL.h"
#include "avl.h"
#include <iostream>
#include <vector>
#include <ctime>


int main(int argc, char* argv[])
{
	int n = 500000;
	int kropki = n / 50;
	std::cout << "generowanie "<< n <<" danych...";

	std::vector<int> data(n);
	for (int i = 0; i < n; i++)
		data[i] = i;

	std::vector<double> oldavl;
	std::vector<double> newavl;
	std::cout << "mieszanie danych\n";
	std::random_shuffle(data.begin(), data.end());

	std::cout << "Na start wrzucamy dane, potem wszystkie je wyszukujemy i iterujemy inorder.\n";
	std::cout << "kasujemy pierwsza polowe, wyszukujemy pozostale, dodajemy i kasujemy wszystko\n";
	std::cout << "\n Na start stare AVL\ndodawanie";

	avl<int> avl;
	int tmp = 0;
	clock_t begin = clock();
	for (int i = 0; i < n; i++)
	{
		avl.insert(data[i]);
		tmp++;
		if (tmp>kropki)
		{
			tmp = 0;
			std::cout << ".";
		}
	}
	clock_t end = clock();
	oldavl.push_back(end - begin);

	std::cout << oldavl[0];
	std::cout << "\n szukanie";
	tmp = 0;
	begin = clock();
	for (int i = 0; i < n; i++)
	{
		avl.find(data[i]);
		tmp++;
		if (tmp>kropki)
		{
			tmp = 0;
			std::cout << ".";
		}
	}
	end = clock();
	oldavl.push_back(end - begin);

	std::cout << "\n inorder";
	tmp = 0;
	begin = clock();
	for (auto &a : avl)
	{
		tmp++;
		if (tmp > kropki)
		{
			tmp = 0;
			std::cout << ".";
		}
	}
	end = clock();
	oldavl.push_back(end - begin);

	std::cout << "\n kasowanie 1/2";
	tmp = 0;
	begin = clock();
	for (int i = 0; i < n/2; i++)
	{
		avl.remove(data[i]);
		tmp++;
		if (tmp>kropki/2)
		{
			tmp = 0;
			std::cout << ".";
		}
	}
	end = clock();
	oldavl.push_back(end - begin);

	std::cout << "\n szukanie 1/2";
	tmp = 0;
	begin = clock();
	for (int i = n/2; i < n; i++)
	{
		avl.find(data[i]);
		tmp++;
		if (tmp>kropki / 2)
		{
			tmp = 0;
			std::cout << ".";
		}
	}
	end = clock();
	oldavl.push_back(end - begin);


	std::cout << "\n dodawanie i kasowanie\n";
	tmp = 0;
	begin = clock();
	for (int i = 0; i < n; i++)
	{
		avl.insert(data[i]);
		tmp++;
		if (tmp>kropki)
		{
			tmp = 0;
			std::cout << ".";
		}
	}
	std::cout << "\n";
	for (int i = 0; i < n; i++)
	{
		avl.remove(data[i]);
		tmp++;
		if (tmp>kropki)
		{
			tmp = 0;
			std::cout << ".";
		}
	}
	end = clock();
	oldavl.push_back(end - begin);


	////////////////////////////////////////////////////////////////////
	std::cout << "\n Teraz czas na nowe drzewo! Prosze zapiac pasy i nacisnac przycisk\n";

	AVL<int> newAVL;
	tmp = 0;
	begin = clock();
	for (int i = 0; i < n; i++)
	{
		newAVL.insert(data[i]);
		tmp++;
		if (tmp>kropki)
		{
			tmp = 0;
			std::cout << ".";
		}
	}
	end = clock();
	newavl.push_back(end - begin);
	std::cout << newavl[0];
	std::cout << "\n szukanie";
	tmp = 0;
	begin = clock();
	for (int i = 0; i < n; i++)
	{
		newAVL.find(data[i]);
		tmp++;
		if (tmp>kropki)
		{
			tmp = 0;
			std::cout << ".";
		}
	}
	end = clock();
	newavl.push_back(end - begin);

	std::cout << "\n inorder";
	tmp = 0;
	begin = clock();
	for (auto &a : newAVL)
	{
		tmp++;
		if (tmp > kropki)
		{
			tmp = 0;
			std::cout << ".";
		}
	}
	end = clock();
	newavl.push_back(end - begin);

	std::cout << "\n kasowanie 1/2";
	tmp = 0;
	begin = clock();
	for (int i = 0; i < n / 2; i++)
	{
		newAVL.remove(data[i]);
		tmp++;
		if (tmp>kropki / 2)
		{
			tmp = 0;
			std::cout << ".";
		}
	}
	end = clock();
	newavl.push_back(end - begin);

	std::cout << "\n szukanie 1/2";
	tmp = 0;
	begin = clock();
	for (int i = n / 2; i < n; i++)
	{
		newAVL.find(data[i]);
		tmp++;
		if (tmp>kropki / 2)
		{
			tmp = 0;
			std::cout << ".";
		}
	}
	end = clock();
	newavl.push_back(end - begin);


	std::cout << "\n dodawanie i kasowanie\n";
	tmp = 0;
	begin = clock();
	for (int i = 0; i < n; i++)
	{
		newAVL.insert(data[i]);
		tmp++;
		if (tmp>kropki)
		{
			tmp = 0;
			std::cout << ".";
		}
	}
	std::cout << "\n";
	for (int i = 0; i < n; i++)
	{
		newAVL.remove(data[i]);
		tmp++;
		if (tmp>kropki)
		{
			tmp = 0;
			std::cout << ".";
		}
	}
	end = clock();
	newavl.push_back(end - begin);


	std::cout << "\n\nDONE\n";
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