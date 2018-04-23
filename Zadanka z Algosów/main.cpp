#include <vector>
#include <chrono>
#include <iostream>
#include "map.h"

int main(int argc, char* argv[])
{

	std::vector<std::vector<int>> tabl;
	std::vector<int> val;
	val.push_back(10);
	tabl.push_back(val);
	map<int,int> struktura;
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
	return 0;
}
