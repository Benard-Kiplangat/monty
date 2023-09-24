#include "monty.h"

/**
 * _pop - a function that removes the top element of the stack
 * @doubly: the head of the doubly linked list
 * @cline: the line number
 * Return: nothing
 */
void _pop(stack_t **doubly, unsigned int cline)
{
	stack_t *aux;

	if (doubly == NULL || *doubly == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", cline);
		freer();
		exit(EXIT_FAILURE);
	}
	aux = *doubly;
	*doubly = (*doubly)->next;
	free(aux);
}
/**
 * _nop - a function that does nothing
 * @doubly: the head of the doubly linked list
 * @cline: the line number
 * Return: nothing
 */
void _nop(stack_t **doubly, unsigned int cline)
{
	(void)doubly;
	(void)cline;
}
