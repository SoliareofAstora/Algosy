static int merge(int *arr, int leftIndex, int splitIndex, int rightIndex)
{
	int out = 0;
	int i, j;
	int leftSize = splitIndex - leftIndex + 1;
	int rightSize = rightIndex - splitIndex;

	int *left = new int[leftSize];
	int *right= new int[rightSize];

	for (i = 0; i < leftSize; i++)
		left[i] = arr[leftIndex + i];
	for (j = 0; j < rightSize; j++)
		right[j] = arr[splitIndex + 1 + j];

	i = 0; //left index
	j = 0; //right index
	int k = leftIndex; //output array index 
	while (i < leftSize && j < rightSize)
	{
		if (left[i] <= right[j])
		{
			//out++;
			arr[k] = left[i++];
		}
		else
		{
			//out++;
			arr[k] = right[j++];
		}
		k++;
	}

	while (i < leftSize)
	{
	//	out++;
		arr[k++] = left[i++];
	}

	while (j < rightSize)
	{
	//	out++;
		arr[k++] = right[j++];
	}
	delete[] right;
	delete[] left;
	return out;
}

static int MergeSort(int* arr, int begin, int end)
{
	int out = 0;
	if (begin < end)
	{
		int splitPoint = begin + (end - begin) / 2;

		MergeSort(arr, begin, splitPoint);
		MergeSort(arr, splitPoint + 1, end);
		out++;
		merge(arr, begin, splitPoint, end);
	}
	return out;
}