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
 * lomut_parti - Order a subset of an array of integers according to
 *                    the lomuto partition scheme (last element as pivot).
 *
 * @array: The array of integers.
 * @size: The size of the array.
 * @le: The start index of the subset to order.
 * @ri: The end index of the subset to order.
 *
 * Return: int partition index.
 */
int lomut_parti(int *array, size_t size, int le, int ri)
{
	int *pvot, abve, bel;

	pvot = array + ri;
	for (abve = bel = le; bel < ri; bel++)
	{
		if (array[bel] < *pvot)
		{
			if (abve < bel)
			{
				swap_i(array + bel, array + abve);
				print_array(array, size);
			}
			abve++;
		}
	}

	if (array[abve] > *pvot)
	{
		swap_i(array + abve, pvot);
		print_array(array, size);
	}

	return (abve);
}

/**
 * lomut_sort - A function quicksort algorithm through recursion.
 *
 * @array: An array of integers.
 * @size: The  array's size.
 * @le: The start index of the array parti to order.
 * @ri: The end index of the array parti to order.
 *
 */
void lomut_sort(int *array, size_t size, int le, int ri)
{
	int parti;

	if (ri - le > 0)
	{
		parti = lomut_parti(array, size, le, ri);
		lomut_sort(array, size, le, parti - 1);
		lomut_sort(array, size, parti + 1, ri);
	}
}

/**
 * quick_sort - A function Sorts an array of integers in ascending
 *              order using the quicksort.
 *
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomut_sort(array, size, 0, size - 1);
}
