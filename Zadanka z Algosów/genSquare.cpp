#include <cstdlib>

template<typename T>
static T* genSquare(int size) {
	T *arr = new T[size];

	for (int i = 0; i < size; i++)
	{
		arr[i].x = (float)rand() / (float)(RAND_MAX);
		arr[i].y = (float)rand() / (float)(RAND_MAX);;
	}
	return arr;
}
