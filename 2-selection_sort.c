#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order
 * using the Selection sort algorithm
 * @array: of intergers
 * @size: of the array
 *
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, aux_p;
	int aux_v;

	if (!array)
		return;
	for (i = 0; i < size - 1; i++)
	{
		aux_p = i, aux_v = array[i];
			for (j = i + 1; j < size; j++)
			{
				if (array[i] > array[j] && array[j] < aux_v)
					aux_p = j, aux_v = array[j];
			}
		if (aux_p != i)
		{
			swap_int(&array[i], &array[aux_p]);
			print_array(array, size);
		}
	}
}
