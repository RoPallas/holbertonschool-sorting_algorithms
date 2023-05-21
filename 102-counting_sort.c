#include "sort.h"
/**
 * counting_sort - sorts an array of integers in ascending order
 * @array: array to be sorted
 * @size: size of array
*/
void counting_sort(int *array, size_t size)
{
	int max;
	int *output, *count;
	size_t i;

	if (array == NULL || size < 2)
		return;

	output = (int *)malloc(size * sizeof(int));
	if (output == NULL)
		return;

	for (i = 0; i < size; i++)
		if (array[i] > max)
			max = array[i];

	count = (int *)malloc((max + 1) * sizeof(int));
	if (count == NULL)
	{
		free(output);
		return;
	}

	for (i = 0; (int)i <= (max + 1); i++)
		count[i] = 0;
	for (i = 0; i < size; i++)
		count[array[i]]++;
	for (i = 1; (int)i < (max + 1); i++)
		count[i] += count[i - 1];
	print_array(count, max + 1);

	for (i = 0; i < size ; i++)
	{
		output[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}
	for (i = 0; i < size; i++)
		array[i] = output[i];

	free(count);
	free(output);
}
