#include "sort.h"
#include <stdbool.h>

void swap_n_head(listint_t **list, listint_t **taill, listint_t **shakr);
void swap_n_behd(listint_t **list, listint_t **taill, listint_t **shakr);
void cocktail_sort_list(listint_t **list);

/**
 * swap_n_head - Swap a node in a listint_t..
 *
 * @list: A pointer to the head of a doubly-linked list of (int).
 * @taill: A pointer to the taill of the doubly-linked list.
 * @shakr: A pointer to the current swapping node of doubly list.
 */
void swap_n_head(listint_t **list, listint_t **taill, listint_t **shakr)
{
	listint_t *temp = (*shakr)->next;

	if ((*shakr)->prev != NULL)
		(*shakr)->prev->next = temp;
	else
		*list = temp;
	temp->prev = (*shakr)->prev;
	(*shakr)->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = *shakr;
	else
		*taill = *shakr;
	(*shakr)->prev = temp;
	temp->next = *shakr;
	*shakr = temp;
}

/**
 * swap_n_behd - Swap a node in a listint_t doubly-linked (int)
 *
 * @list: A pointer to the head of a doubly-linked list of (int).
 * @taill: A pointer to the taill of the doubly-linked list.
 * @shakr: A pointer to the current swapping node...
 */
void swap_n_behd(listint_t **list, listint_t **taill, listint_t **shakr)
{
	listint_t *temp = (*shakr)->prev;

	if ((*shakr)->next != NULL)
		(*shakr)->next->prev = temp;
	else
		*taill = temp;
	temp->next = (*shakr)->next;
	(*shakr)->prev = temp->prev;
	if (temp->prev != NULL)
		temp->prev->next = *shakr;
	else
		*list = *shakr;
	(*shakr)->next = temp;
	temp->prev = *shakr;
	*shakr = temp;
}

/**
 * cocktail_sort_list - Sort a listint_t doubly-linked ...
 *
 * @list: A pointer to the head of a listint_t int.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *taill, *shakr;
	bool shken_nt_str = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (taill = *list; taill->next != NULL;)
		taill = taill->next;

	while (shken_nt_str == false)
	{
		shken_nt_str = true;
		for (shakr = *list; shakr != taill; shakr = shakr->next)
		{
			if (shakr->n > shakr->next->n)
			{
				swap_n_head(list, &taill, &shakr);
				print_list((const listint_t *)*list);
				shken_nt_str = false;
			}
		}
		for (shakr = shakr->prev; shakr != *list;
				shakr = shakr->prev)
		{
			if (shakr->n < shakr->prev->n)
			{
				swap_n_behd(list, &taill, &shakr);
				print_list((const listint_t *)*list);
				shken_nt_str = false;
			}
		}
	}
}
