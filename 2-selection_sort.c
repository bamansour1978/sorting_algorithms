#include "sort.h"

/**
 * swap_i - Swap tow elemnet int in array
 *
 * @a: 1st int
 * @b: 2nd int
 *
 * Return: void
 */
void swap_i(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * selection_sort - A function that sorts array in ascending order
 *
 * @array: Array of int
 * @size: Array's size
 *
 * Return: void
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, min_index;

	if (!array || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min_index = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[min_index] > array[j])
				min_index = j;
		}

		if (i != min_index)
		{

			swap_i(&array[i], &array[min_index]);
			print_array(array, size);
		}
	}
}
