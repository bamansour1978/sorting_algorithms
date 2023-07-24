#include "sort.h"

/**
 * s_get_maximum - Get the maximum value in an array (int).
 *
 * @array: An array of (int).
 * @size: The array's.size
 *
 * Return: The  array's maximum.
 */
int s_get_maximum(int *array, int size)
{
	int max, j;

	for (max = array[0], j = 1; j < size; j++)
	{
		if (array[j] > max)
			max = array[j];
	}

	return (max);
}

/**
 * counting_sort - Sort an array of (int) in ascending order
 *
 * @array: An array of (int).
 * @size: The array's size.
 *
 * Return: void
 */
void counting_sort(int *array, size_t size)
{
	int *cont, *srted, max, j;

	if (array == NULL || size < 2)
		return;

	srted = malloc(sizeof(int) * size);
	if (srted == NULL)
		return;
	max = s_get_maximum(array, size);
	cont = malloc(sizeof(int) * (max + 1));
	if (cont == NULL)
	{
		free(srted);
		return;
	}

	for (j = 0; j < (max + 1); j++)
		cont[j] = 0;
	for (j = 0; j < (int)size; j++)
		cont[array[j]] += 1;
	for (j = 0; j < (max + 1); j++)
		cont[j] += cont[j - 1];
	print_array(cont, max + 1);

	for (j = 0; j < (int)size; j++)
	{
		srted[cont[array[j]] - 1] = array[j];
		cont[array[j]] -= 1;
	}

	for (j = 0; j < (int)size; j++)
		array[j] = srted[j];

	free(srted);
	free(cont);
}
