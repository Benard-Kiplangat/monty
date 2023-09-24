#include "monty.h"

/**
 * free_dlistint - a function that frees a doubly linked list
 * @h: a dlistint list to be freed
 * Return: nothing
 */

void free_dlistint(stack_t *h)
{
	stack_t *hcopy;

	while (h)
	{
		hcopy = h->next;
		free(h);
		h = hcopy;
	}
}
