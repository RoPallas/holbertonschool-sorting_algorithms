#include "sort.h"
/**
 * shell_sort - sorts an array of integers in ascending order
 * optimized for Knut's Sequence
 * @array: array to be sorted
 * @size: size of array
*/
void shell_sort(int *array, size_t size)
{
	/*
	 * i, j: iterators
	 * temp: auxiliary value
	 * gap: point of reference for comparisons
	*/
	unsigned long int i, j, gap;
	int temp;

	if (array == NULL || size < 2)
		return;

	for (gap = 1; gap < size / 3; gap = gap * 3 + 1)
		;

	for (; gap > 0; gap = (gap - 1) / 3)
	{
		for (i = gap; i < size; i += 1)
		{
			temp = array[i];
			for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
				array[j] = array[j - gap];
			array[j] = temp;
		}
		print_array(array, size);
	}
}
