#include <algorithm>

template <typename T, typename F>
static void QuickSort2(T *arr, int left, int right, F f)
{
	int i = left;
	int j = right;
	T x = arr[(left + right) / 2];
	do
	{
		while (f(arr[i], x))
			i++;

		while (f(x, arr[j]))
			j--;

		if (i <= j)
		{
			std::swap(arr[i++], arr[j--]);
		}
	} while (i <= j);

	if (left < j) QuickSort2(arr, left, j, f);

	if (right > i) QuickSort2(arr, i, right, f);
}