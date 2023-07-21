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
 * bubble_sort - A function that sorts array in ascending order
 *
 * @array: Array of int
 * @size: Array's size
 *
 * Return: void
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;

	if (!array || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap_i(&array[j], &array[j + 1]);
				print_array(array, size);
			}
		}
	}
}
