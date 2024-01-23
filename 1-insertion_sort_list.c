#include "sort.h"
/**
 * insertion_sort_list - a function that sorts a doubly linked list using
 *				using the Insertion sort algorithm
 * list : list to be sorted
 *
 * Return : Nothing (void)
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *sorted = *list;

	if (*list == NULL || (*list)->next == NULL)
	{
		return;
	}

	while (sorted->next != NULL)
	{
		if (sorted->n > sorted->next->n)
		{
			current = sorted->next;
			sorted->next = current->next;

			if (current->next != NULL)
				current->next->prev = sorted;

			/** Find insertion point in the sorted part*/
			while (sorted->prev != NULL && sorted->prev->n > current->n)
				sorted = sorted->prev;

			/**Insert current node*/
			current->next = sorted;
			current->prev = sorted->prev;

			if (sorted->prev != NULL)
				sorted->prev->next = current;
			else
				*list = current;
			sorted->prev = current;
			print_list(*list);
		}
		else
			sorted = sorted->next;
	}
}
