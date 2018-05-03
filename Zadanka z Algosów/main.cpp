#include <vector>
#include <chrono>
#include <iostream>
#include "graph.h"
#include "map.h"
#include <string>

int main(int argc, char* argv[])
{
	map<int, std::string> Map;
	Map.insert(10, "alibaba");
	std::cout<<Map.find(10);

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
