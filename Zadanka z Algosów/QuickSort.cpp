#include <algorithm>
template<typename T>
static void QuickSort( T *arr, int left, int right)
{
	int i = left;
	int j = right;
	T x = arr[(left + right) / 2];
	do
	{
		while (arr[i] < x)
			i++;

		while (arr[j] > x)
			j--;

		if (i <= j)
		{
			std::swap(arr[i++], arr[j--]);
		}
	} while (i <= j);

	if (left < j) QuickSort(arr, left, j);

	if (right > i) QuickSort(arr, i, right);
}