
#include <iostream>
using namespace std;



int main()
{

	int input[] = { 3,2,4,1,5,6,7,1 };
	int const size = sizeof input /4;
	int tab[size];

	for (size_t i = 0; i < size; i++)
	{
		tab[i] = input[i];
		cout << tab[i] << " ";
	}
	cout << "\n";


	for (size_t i = 0; i < size - 1; i++)
	{
		bool sorted = true;
		for (size_t j = size-1; j > i; j--)
		{
			if (tab[j-1]>tab[j])
			{
				swap(tab[j-1], tab[j]);
				sorted = false;
			}
		}
		if (sorted)
		{
			break;
		}
	}









	for (size_t i = 0; i < size; i++)
	{
		cout << tab[i]<<" ";
	}
	

	
	char a;
	cin>>a;
}

