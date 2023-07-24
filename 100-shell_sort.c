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
 * gap_sheel_sort - Array's sort with gap
 *
 * @array: array will be sorted
 * @size: array's size
 * @gap: size of gap
 *
 * Return: void
 */
void gap_sheel_sort(int *array, size_t size, unsigned int gap)
{
	size_t i, j;

	for (i = gap; i < size; i++)
	{
		j = i;
		while (j >= gap && array[j] < array[j - gap])
		{
			swap_i(array + j, array - gap + j);
			j -= gap;
		}
	}
}

/**
 * shell_sort - Sheel sort's function
 *
 * @array: array
 * @size: array's size
 *
 * Return: void
 */
void shell_sort(int *array, size_t size)
{
	unsigned int gap = 1;

	if (!array || size < 2)
		return;

	while (gap < size / 3)
	{
		gap_sheel_sort(array, size, gap);
		gap = (gap - 1) / 3;
		print_array(array, size);
	}
}
