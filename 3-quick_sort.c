#include "sort.h"
/**
 * swap - function for swap
 * @array: array to be sorted
 * @size: size of array
 * @low: first pointer to be swap
 * @high: second pointer to be swap
 */
void swap(int *array, size_t size, int low, int high)
{
	int aux = 0;

	if (array[low] != array[high])
	{
		aux = array[low];
		array[low] = array[high];
		array[high] = aux;
		print_array(array, size);
	}
}

/**
 * partition_lomuto - function for partition an array
 * @array: array to be sorted
 * @size: size of array
 * @low: the first value
 * @high: the last value
 * Return: the partition point
 */
int partition_lomuto(int array[], size_t size, int low, int high)
{
	int pivot = array[high];
	int i = low - 1, j = 0;

	for (j = low; j <= high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap(array, size, i, j);
		}
	}
	swap(array, size, i + 1, high);
	return (i + 1);
}

/**
 * recursive_sorting - sorts an array using quicksorting
 * @array: array to be sorted
 * @size: size of array
 * @low: the first value
 * @high: the last value
 */
void recursive_sorting(int *array, size_t size, int low, int high)
{
	int pivot;

	if (low < high)
	{
		pivot = partition_lomuto(array, size, low, high);
		recursive_sorting(array, size, low, pivot - 1);
		recursive_sorting(array, size, pivot + 1, high);
	}

}

/**
 * quick_sort - sorts an array of integers in ascending order
 * @array: array to be sorted
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{

	if (array == NULL || size < 2)
		return;

	recursive_sorting(array, size, 0, size - 1);
}
