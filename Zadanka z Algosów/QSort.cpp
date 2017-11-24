#include <xutility>
static int compare(const void * a, const void * b)
{
	return (*(int*)a - *(int*)b);
}
static void QSort(int *arr,int size)
{
	qsort(arr, size, sizeof (int), compare);
}
