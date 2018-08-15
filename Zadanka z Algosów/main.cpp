
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
		bool alle;
		clock_t begin = clock();

		alle = bitset_.all();

		clock_t end = clock();
		temp.push_back(end - begin);

		begin = clock();

		bool all=false;

		size_t size = bitset_.size();
		std::string str = bitset_.to_string();
		for (auto i = str.begin();i != str.end(); i++)
		{
			if (*i=='1')
			{
				all = true;
			}
		}

		end = clock();
		temp.push_back(end - begin);


		begin = clock();

		size_t idx = 0;
		while (idx < bitset_.size() && !bitset_.test(idx)) {
			++idx;
		}

		/*if (idx < b1.size()) {
			std::cout << "first set bit at index " << idx << '\n';
		}
		else {
			std::cout << "no set bits\n";
		}*/

		end = clock();
		temp.push_back(end - begin);

		/*
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
		/**/


		for (auto element : temp)
		{
			std::cout <<","<< element;
		}

		std::cout << "\n";
		if (all)
		{
			if (alle)
			{
				std::cout << "alibaba";
			}
		}
	}
};

void fun(int& a)
{
	a++;
}

int main(int argc, char* argv[])
{
	//std::unique_ptr < std::array<int, 3>> temp(new std::array<int, 3>({ 1,2,3 }));

	//std::cout << &temp.operator*()[1];

	std::vector<int> a({ 12,23,34,45,56,67 });
	for (auto element : a)
	{
		//std::cout << element << " ";
	}

	//MemoryPool<int> arr;
	MemoryPool<int> ar2;
	ar2.test();
	auto af = ar2.end();
	af -= 0;
	auto tmp = af.get_index();
	std::cout << "\n" << tmp.first*ar2.block_size() + tmp.second;

	/*
	int qwer[] = { 0,1,2,3,4,5 };
	int a1 = 10;
	int a2 = 20;
	
	std::unique_ptr<int> abc(&a1);
	std::unique_ptr<int> bcd(&a2);

	abc.release();
	abc = std::move(bcd);

	std::cout << abc.operator*();
	//std::cout << bcd.operator*();

	
	std::vector<std::pair<int, int*>> vec;
	vec.emplace_back(0, &qwer[0]);
	vec.push_back(std::pair<int, int*>(2, &qwer[3]));
	vec[0] = vec[1];
	for (auto element : vec)
	{
	//	std::cout << element.first;
	}

	std::cout << "\n";

	auto* a = new tester<10>();
	a->fun();
	delete a;
	auto* b = new tester<100>();
	b->fun();
	delete b;
	auto* q = new tester<1000>();
	q->fun();
	delete q;
	auto* e = new tester<10000>();
	e->fun();
	delete e;
	auto* r = new tester<100000>();
	r->fun();
	delete r;
	auto* t = new tester<1000000>();
	t->fun();
	delete t;
	auto* d = new tester<10000000>();
	d->fun();
	delete d;
	auto* s = new tester<100000000>();
	s->fun();
	delete s;
	

	/*
	 * Plik realizuj�cy takie same zadania na obu drzewach. 
	 * Tworzy wektor danych, kt�re nast�pnie szufluje. 
	 * Drzewa korzustaj� z identycznego zestawu danych. 
	 * 
	 * Czas wykonania jest zapisany w wektorach oldavl oraz newavl
	 * 
	 * Plik du�o lepiej wygl�da po uruchomieniu ;) 
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