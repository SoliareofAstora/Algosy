#include "queue.h"
#include <queue>
#include "LinkedList.h"

static int remainder(int number, int divider)
{
	return number / divider % 10;
}

static void RadxSort(int *a, int length) {

	const int MAX_DIGIT = static_cast<int>(log10(INT_MAX))+1;
	const int radxStep = 10;
	//std::queue<int> numbers[radxStep];
	//queue<int> numbers[radxStep];
	LinkedList numbers[radxStep];

	for (int numberLength = 1, divider = 1; 
		numberLength <= MAX_DIGIT; 
		divider *= radxStep, ++numberLength) 
	{
		for (int i = 0; i < length; ++i) {
			numbers[remainder(a[i], divider)].push(a[i]);
		}

		int a_pos = 0;
		for (int i = 0; i < radxStep; ++i) {
			while (!numbers[i].empty()) {
				a[a_pos++] = numbers[i].front();
				numbers[i].pop();
			}
		}
	}
}