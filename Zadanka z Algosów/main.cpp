
#include "betterAVL.h"
#include "avl.h"
#include <iostream>
#include <vector>
#include <ctime>
#include "MemoryPool.h"
#include <bitset>

template<size_t N>
class tester
{
public:
	std::bitset<N> bitset_;

	void fun()
	{
		std::vector<double> temp;
		std::cout << N;
		
		clock_t begin = clock();

		bitset_.all();

		clock_t end = clock();
		temp.push_back(end - begin);

		begin = clock();

		bitset_.any();

		end = clock();
		temp.push_back(end - begin);

		begin = clock();

		bitset_.none();

		end = clock();
		temp.push_back(end - begin);
		begin = clock();

		bitset_.count();

		end = clock();
		temp.push_back(end - begin);
		begin = clock();

		bitset_.size();

		end = clock();
		temp.push_back(end - begin);

		int tmp = bitset_.size();
		begin = clock();

		for (int i = 0; i < tmp; ++i)
		{
			bitset_[i];
		}

		end = clock();
		temp.push_back(end - begin);


		for (auto element : temp)
		{
			std::cout <<","<< element;
		}
		std::cout << "\n";
	}
};

int main(int argc, char* argv[])
{

	MemoryPool<int> arr;
	MemoryPool<int> ar2;
	arr.test();

	std::vector<int> a;
	

	/*
	auto* a = new tester<10>();
	a->fun();
	delete a;
	
	auto* b = new tester<58540>();
	b->fun();
	delete b;
	auto* q = new tester<1000000>();
	q->fun();
	delete q;
	auto* e = new tester<1000654700>();
	e->fun();
	delete e;
	auto* r = new tester<100000000>();
	r->fun();
	delete r;
	auto* t = new tester<1036675420>();
	t->fun();
	delete t;
	auto* d = new tester<10000000>();
	d->fun();
	delete d;
	auto* s = new tester<1000000000>();
	s->fun();
	delete s;
	auto* x = new tester<404523918>();
	x->fun();
	delete x;
	auto* n = new tester<5728012>();
	n->fun();
	delete n;
	auto* m = new tester<764252400>();
	m->fun();
	delete m;
	

	*/












	/*
	 * Plik realizuj¹cy takie same zadania na obu drzewach. 
	 * Tworzy wektor danych, które nastêpnie szufluje. 
	 * Drzewa korzustaj¹ z identycznego zestawu danych. 
	 * 
	 * Czas wykonania jest zapisany w wektorach oldavl oraz newavl
	 * 
	 * Plik du¿o lepiej wygl¹da po uruchomieniu ;) 
	 */


	/*
	int n = 900000;
	int kropki = n / 5;
	std::cout << "generowanie "<< n <<" pomieszanych danych\n";
	std::pair<int, int> roots;
	std::vector<int> data(n);
	for (int i = 0; i < n; i++)
		data[i] = i;

	std::vector<double> oldavl;
	std::vector<double> newavl;

	std::random_shuffle(data.begin(), data.end());

	std::cout << "Na start wrzucamy dane, potem wszystkie je wyszukujemy i iterujemy inorder.\n";
	std::cout << "kasujemy pierwsza polowe, wyszukujemy pozostale, a na koniec dodajemy i kasujemy wszystko\n";

	std::cout << "\n Na start stare AVL\ndodawanie";
	int time = 0;
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
	roots.first = avl.root_node()->value;

	std::cout << oldavl[time++];
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
	std::cout << oldavl[time++];
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
	std::cout << oldavl[time++];
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
	std::cout << oldavl[time++];
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

	std::cout << oldavl[time++];
	std::cout << "\n dodawanie i kasowanie\n";
	tmp = 0;
	begin = clock();
	for (int i = 0; i < n; i++)
	{
		avl.insert(data[i]);
		tmp++;
		if (tmp>kropki*2)
		{
			tmp = 0;
			std::cout << ".";
		}
	}
	for (int i = 0; i < n; i++)
	{
		avl.remove(data[i]);
		tmp++;
		if (tmp>kropki*2)
		{
			tmp = 0;
			std::cout << ".";
		}
	}
	end = clock();
	oldavl.push_back(end - begin);
	std::cout << oldavl[time++];

	////////////////////////////////////////////////////////////////////

	////////////////////////////////////////////////////////////////////
	std::cout << "\n\n Teraz czas na nowe drzewo! Prosze zapiac pasy ;)\n dodawanie";
	time = 0;

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
	roots.second = newAVL.root_node()->value;
	std::cout << newavl[time++];
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
	std::cout << newavl[time++];
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
	std::cout << newavl[time++];

	std::cout << "\n kasowanie 1/2 - niestety dla wiecej niz 12 elementow cos nie dziala poprawnie.";
	tmp = 0;
	begin = clock();
	for (int i = 0; i < n / 2; i++)
	{
		//newAVL.remove(data[i]);
		tmp++;
		if (tmp>kropki / 2)
		{
			tmp = 0;
			std::cout << ".";
		}
	}
	end = clock();
	newavl.push_back(end - begin);
	std::cout << newavl[time++];

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
	std::cout << newavl[time++];


	std::cout << "\n dodawanie i kasowanie pominiemy, bo wiemy jak wolno dziala\n";
	tmp = 0;
	begin = clock();
	for (int i = 0; i < n; i++)
	{
	//	newAVL.insert(data[i]);
		tmp++;
		if (tmp>kropki*2)
		{
			tmp = 0;
			std::cout << ".";
		}
	}
	for (int i = 0; i < n; i++)
	{
	//	newAVL.remove(data[i]);
		tmp++;
		if (tmp>kropki*2)
		{
			tmp = 0;
			std::cout << ".";
		}
	}
	end = clock();
	newavl.push_back(end - begin);

	std::cout << newavl[time++];

	std::cout << "\n\n";

	std::cout << "ZESTAWIENIE:\n1. zadanie \n2. czas starego AVL na wskaxnikach i rekurencji \n3. czas nowego avl na memory pool i iteracje\n4. procentowa roznica \n\n";

	for (int i = 0; i < 3; i++)
	{
		switch (i)
		{
		case  0:
			std::cout << "dodawanie ";
			break;
		case 1:
			std::cout << "szukanie ";
			break;
		case 2:
			std::cout << "inorder ";
			break;
		default:
			std::cout << "nie wazne ";
		}
		std::cout<<"  " << oldavl[i] << "   " << newavl[i]<<"  "<<(int)(newavl[i]/oldavl[i]*100)<<" %"<<std::endl;
	}

	std::cout << "\nChcialbym rowniez zaznaczyc, ze struktura drzewa jest poprawna. \nMozna to poznac po tym, ze wartosc root jest identyczna\n";
	std::cout << roots.first << " " << roots.second;
	


	*/
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