#include "sort.h"

/**
 * swap_i - Swap two integers in an array.
 *
 * @a: The first integer
 * @b: The second integer
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
 * s_max_heap - Turn a binary tree into a complete binary heap.
 *
 * @array: An array of integers representing a binary tree.
 * @size: The size of the array/tree.
 * @base: The index of the base row of the tree.
 * @root: The root node of the binary tree.
 *
 * Return: void
 */
void s_max_heap(int *array, size_t size, size_t base, size_t root)
{
	size_t le, ri, large;

	le = 2 * root + 1;
	ri = 2 * root + 2;
	large = root;

	if (le < base && array[le] > array[large])
		large = le;
	if (ri < base && array[ri] > array[large])
		large = ri;

	if (large != root)
	{
		swap_i(array + root, array + large);
		print_array(array, size);
		s_max_heap(array, size, base, large);
	}
}

/**
 * heap_sort - Sort an array
 *
 * @array: An array
 * @size: The size of the array.
 *
 * Return: void
 */
void heap_sort(int *array, size_t size)
{
	int j;

	if (array == NULL || size < 2)
		return;

	for (j = (size / 2) - 1; j >= 0; j--)
		s_max_heap(array, size, size, j);

	for (j = size - 1; j > 0; j--)
	{
		swap_i(array, array + j);
		print_array(array, size);
		s_max_heap(array, size, j, 0);
	}
}
