static int* genReverse(int size)
{
	int *arr = new int[size];
	for (int i = size-1; i >= 0; i--)
	{
		arr[i] = i;
	}
	return arr;
}
