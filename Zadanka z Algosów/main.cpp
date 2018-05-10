#include <vector>
#include <chrono>
#include <iostream>
#include "graph.h"
#include "map.h"
#include <string>
#include <memory>

int main(int argc, char* argv[])
{
	map<int, std::string> Map;
	std::string tekst[] = { 
		".","kota","ma","a", "kot","Ala", "ma", "Ale"};
	int klucz[]={ 88, 23,65,21,34,11,66,70};
	for (int i = 0; i < 8; i++)
	{
		Map.insert(klucz[i], tekst[i]);
	}

	for(auto &a: Map)
	{
		std::cout << a<< " ";
	}

	/*
	avl<int> tree;
	tree.insert(1);
	tree.insert(2);
	tree.insert(3);
	tree.insert(4);
	tree.insert(5);
	tree.insert(6);
	tree.insert(7);

	for (auto &a: tree)
	{
		std::cout << a.value<<" ";
	}
	*/
	char a;
	std::cin >> a;
	/*Zabawa z grafem
	std::vector<std::vector<int>> tabl;
	std::vector<int> val;
	val.push_back(10);
	tabl.push_back(val);
	graph<int,int> struktura;
	int temp = 10;
	do
	{
		temp++;
		struktura.insert_vertex(temp);
	}
	while (temp<100);
	struktura.insert_vertex(temp);
	struktura.insert_vertex(temp);
	struktura.insert_vertex(temp);
	struktura.insert_vertex(temp);
	struktura.printSize();
	char a;
	std::cin>>a;
	return 0;*/
}
