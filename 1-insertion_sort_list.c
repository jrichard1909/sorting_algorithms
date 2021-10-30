#include "sort.h"

/**
 * insertion_sort_list - sorts an array of integers in ascending order
 * @list: array
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *new_list, *tmp_list;

	if (list == NULL || *list == NULL)
		return;
	new_list = (*list)->next;
	while (new_list)
	{
		tmp_list = new_list->next;
		while (new_list->prev && new_list->prev->n > new_list->n)
		{
			new_list->prev->next = new_list->next;
			if (new_list->next != NULL)
				new_list->next->prev = new_list->prev;
			new_list->next = new_list->prev;
			new_list->prev = new_list->prev->prev;
			new_list->next->prev = new_list;
			if (new_list->prev != NULL)
			{
				new_list->prev->next = new_list;
			}
			else
				*list = new_list;
			print_list(*list);
		}
		new_list = tmp_list;
	}
}
