static int* genReverse(int size)
{
	int *arr = new int[size];
	for (int i = 0; i < size; i++)
	{
		arr[i] = size-i;
	}
	return arr;
}
