#include <iostream>
#include "map.h"
#include <string>

int main(int argc, char* argv[])
{
	map<int, std::string> Map;
	std::string tekst[] = {
		".","kota","ma","a", "kot","Ala", "ma", "Ale","kopia klucza" };
	int klucz[] = { 88, 23,21,34,65,11,66,70,34 };
	
	for (int i = 0; i < 9; i++)
	{
		Map.insert(klucz[i], tekst[i]);
	}

	for (auto &a : Map)
	{
		std::cout << a.value.second << " ";
	}
	char a;
	std::cin >> a;
}
	