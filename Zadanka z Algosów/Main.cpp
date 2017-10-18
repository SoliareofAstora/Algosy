
#include <iostream>
#include <chrono>
#include <array>
#include <algorithm>
using namespace std;

void QuickSort(int tab[], int left, int right) 
{
	int i = left;
	int j = right;
	int x = tab[(left + right) / 2];
	do
	{
		while (tab[i] < x)
			i++;

		while (tab[j] > x)
			j--;

		if (i <= j)
		{
			swap(tab[i], tab[j]);

			i++;
			j--;
		}
	} while (i <= j);

	if (left < j) QuickSort(tab, left, j);

	if (right > i) QuickSort(tab, i, right);
}
void Check(int s[], int tab[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (s[i] != tab[i])
		{
			cout << "Error!!!";
			break;
		}
	}
}
void ShowArray(int tab[],int n)
{
	for (int i = 0; i < n; i++)
	{
		//cout << tab[i] << " ";
	}
	cout << endl << endl;
}

int main()
{
	srand(time(nullptr));
	int  n = 50000;  //Sort Range
	int const ArrayLength = 50000;
	int source[ArrayLength];
	int tab[ArrayLength];
	int check[ArrayLength];
	int const numberSpread = 1000;// for counting sort 
	for (int i = 0; i < n; i++)
	{
		source[i] = rand() % numberSpread + 1;
	}
	ShowArray(source,n);

	//std::sort sort
	{
		for (int i = 0; i < n; i++)
		{
			tab[i] = source[i];
		}

		cout << "Data preparation finished. std::sort ongoing" << endl;
		auto start = chrono::high_resolution_clock::now();

		sort(tab, tab+n);

		auto end = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsed = end - start;
		cout << "std::sort Elapsed time[s] = " << elapsed.count() << endl << endl;

		ShowArray(tab, n);
	}

	//Save array after std::sort for future checks 
	for (int i = 0; i < n; i++)
	{
		check[i] = tab[i];
	}

	//Quick Sort
	{
		for (int i = 0; i < n; i++)
		{
			tab[i] = source[i];
		}

		cout << "Data preparation finished. Quick sort ongoing" << endl;
		auto start = chrono::high_resolution_clock::now();

		QuickSort(tab, 0, n-1);

		auto end = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsed = end - start;
		cout << "Quick sort Elapsed time[s] = " << elapsed.count() << endl << endl;

		Check(check, tab, n);
		ShowArray(tab, n);
	}

	//Counting sort
	{
		for (int i = 0; i < n; i++)
		{
			tab[i] = source[i];
		}

		cout << "Data preparation finished. Counting sort ongoing" << endl;
		auto start = chrono::high_resolution_clock::now();

		int const NumbersRange = numberSpread+1;
		int NumbersCount[NumbersRange] = { 0 };

		for (int i = 0; i<n; i++)
		{
			NumbersCount[tab[i]]++;
		}

		int outputindex = 0;
		for (int j = 0; j<NumbersRange; j++)
		{
			while (NumbersCount[j]--)
				tab[outputindex++] = j;
		}							  

		auto end = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsed = end - start;
		cout << "Counting sort Elapsed time[s] = " << elapsed.count() << endl << endl;

		Check(check, tab, n);
		ShowArray(tab, n);
	}

	//Selection Sort
	{
		for (int i = 0; i < n; i++)
		{
			tab[i] = source[i];
		}

		cout << "Data preparation finished. Selection sort ongoing" << endl;
		auto start = chrono::high_resolution_clock::now();

		for (int i = 0; i<n; i++) {
			int k = i;
			for (int j = i + 1; j<n; j++) if (tab[j]<tab[k]) k = j;
			swap(tab[k], tab[i]);
		}

		auto end = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsed = end - start;
		cout << "Selection sort Elapsed time[s] = " << elapsed.count() << endl << endl;

		Check(check, tab, n);
		ShowArray(tab, n);
	}

	//Insertion sort
	{
		for (int i = 0; i < n; i++)
		{
			tab[i] = source[i];
		}

		cout << "Data preparation finished. Insertion sort ongoing" << endl;
		auto start = chrono::high_resolution_clock::now();

		int j;
		for (int i = 1; i < n; i++)
		{
			int temp = tab[i];

			for (j = i - 1; j >= 0 && tab[j] > temp; j--)
				tab[j + 1] = tab[j];

			tab[j + 1] = temp;
		}

		auto end = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsed = end - start;
		cout << "Insertion sort Elapsed time[s] = " << elapsed.count() << endl << endl;

		Check(check, tab, n);
		ShowArray(tab, n);
	}

	//BUBBLE SORT
	{
		for (int i = 0; i < n; i++)
		{
			//tab[i] = source[i];
		}

		cout << "Data preparation finished. Bubble sort ongoing" << endl;
		auto start = chrono::high_resolution_clock::now();

		for (int i = 0; i < n - 1; i++)
		{
			bool sorted = true;
			for (int j = n - 1; j > i; j--)
			{
				if (tab[j - 1] > tab[j])
				{
					swap(tab[j - 1], tab[j]);
					sorted = false;
				}
			}
			if (sorted)
			{
				break;
			}
		}

		auto end = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsed = end - start;
		cout << "Bubble Sort Elapsed time[s] = " << elapsed.count() << endl << endl;

		Check(check, tab, n);
		ShowArray(tab, n);
	}
	
	//pause the program
	system("PAUSE");
}

