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
void swap_n(listint_t **h, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	if (n2->next != NULL)
		n2->next->prev = *n1;
	n2->prev = (*n1)->prev;
	n2->next = *n1;
	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;
	else
		*h = n2;
	(*n1)->prev = n2;
	*n1 = n2->prev;
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
