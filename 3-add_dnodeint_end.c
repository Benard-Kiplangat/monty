#include "main.h"

/**
 * add_dnodeint_end - a function that adds a node at the end of a dbly list
 * @head: a pointer to pointer to head of list
 * @n: data to be added
 * Return: the address of the new element or NULL if it failed
 */

stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *new_node, *last;

	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
		return (NULL);
	new_node->n = n;
	new_node->next = NULL;
	last = *head;
	if (*head == NULL)
	{
		new_node->next = *head;
		*head = new_node;
	}
	else
	{
		while (last->next)
			last = last->next;
		last->next = new_node;
	}
	new_node->prev = last;
	return (new_node);
}
