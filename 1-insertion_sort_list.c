#include "sort.h"

/**
 * swap_n - Swap two nodes in a linked list.
 *
 * @h: A pointer to the head of the linked list.
 * @no1: A pointer to the first .
 * @no2: The second node to swap.
 *
 * Return: void
 */
void swap_n(listint_t **h, listint_t **no1, listint_t *no2)
{
	(*no1)->next = no2->next;
	if (no2->next != NULL)
		no2->next->prev = *no1;
	no2->prev = (*no1)->prev;
	no2->next = *no1;
	if ((*no1)->prev != NULL)
		(*no1)->prev->next = no2;
	else
		*h = no2;
	(*no1)->prev = no2;
	*no1 = no2->prev;
}
/**
 * insertion_sort_list - insertion sort for a linked list
 *
 * @list: node's head for a linked list
 *
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current_n, *swap_n, *prv_n;

	if (!list || !*list)
		return;

	current_n = *list;
	while ((current_n = current_n->next))
	{
		swap_n = current_n;
		while (swap_n->prev && swap_n->n < swap_n->prev->n)
		{
			prv_n = swap_n->prev;
			if (swap_n->next)
				swap_n->next->prev = prv_n;
			if (prv_n->prev)
				prv_n->prev->next = swap_n;
			else
				*list = swap_n;
			prv_n->next = swap_n->next;
			swap_n->prev = prv_n->prev;
			swap_n->next = prv_n;
			prv_n->prev = swap_n;

			print_list(*list);
		}
	}
}
