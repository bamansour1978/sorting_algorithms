#include "sort.h"

/**
 * s_merge_subb - Sort a subaryay of integers.
 *
 * @subary: A subary of integer's array to sort.
 * @bufer: A bufer to store the sorted subaryay.
 * @front: The front index of the array.
 * @middle: The middle index of the array.
 * @back: The back index of the array.
 *
 * Return: void
 */
void s_merge_subb(int *subary, int *bufer, size_t front, size_t middle,
		size_t back)
{
	size_t i, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(subary + front, middle - front);

	printf("[right]: ");
	print_array(subary + middle, back - middle);

	for (i = front, j = middle; i < middle && j < back; k++)
		bufer[k] = (subary[i] < subary[j]) ? subary[i++] : subary[j++];
	for (; i < middle; i++)
		bufer[k++] = subary[i];
	for (; j < back; j++)
		bufer[k++] = subary[j];
	for (i = front, k = 0; i < back; i++)
		subary[i] = bufer[k++];

	printf("[Done]: ");
	print_array(subary + front, back - front);
}

/**
 * merge_sort_recursive - recursive
 *
 * @subary: A subaryay of an array of integers to sort.
 * @bufer: A buferer to store the sorted result.
 * @front: The front index of the subaryay.
 * @back: The back index of the subaryay.
 *
 * Return: void
 */
void merge_sort_recursive(int *subary, int *bufer, size_t front, size_t back)
{
	size_t middle;

	if (back - front > 1)
	{
		middle = front + (back - front) / 2;
		merge_sort_recursive(subary, bufer, front, middle);
		merge_sort_recursive(subary, bufer, middle, back);
		s_merge_subb(subary, bufer, front, middle, back);
	}
}

/**
 * merge_sort - Sort an array
 *
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: void
 */
void merge_sort(int *array, size_t size)
{
	int *bufer;

	if (array == NULL || size < 2)
		return;

	bufer = malloc(sizeof(int) * size);
	if (bufer == NULL)
		return;

	merge_sort_recursive(array, bufer, 0, size);

	free(bufer);
}
