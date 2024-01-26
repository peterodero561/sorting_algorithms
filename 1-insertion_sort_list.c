#include "sort.h"

/**
 * insertion_sort_list - algorithm that sorts a doubly
 * linked list in ascending order in Insertion Sort algorithm
 * @list: pointer to the head of the linked list
 * Return: nothing
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *current;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	current = (*list)->next;
	while(current != NULL)
	{
		temp = current->prev;
		while (temp != NULL && temp->n > current->n)
		{
			temp->next = current->next;
			if (current->next != NULL)
				current->next->prev = temp;
			current->next = temp;
			current->prev = temp->prev;
			temp->prev = current;
			if (current->prev == NULL)
				*list = current;
			else
				current->prev->next = current;
			print_list(*list);
			temp = current->prev;
		}
		current = current->next;
	}
}
