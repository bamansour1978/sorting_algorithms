#ifndef SORT_H
#define SORT_H


#include <stdio.h>
#include <stdlib.h>
#include "sort.h"


/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
const int n;
struct listint_s *prev;
struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void swap_n_head(listint_t **list, listint_t **taill, listint_t **shakr);
void swap_n_behd(listint_t **list, listint_t **taill, listint_t **shakr);
void cocktail_sort_list(listint_t **list);
int s_get_maximum(int *array, int size);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);





#endif /* SORT_H */
