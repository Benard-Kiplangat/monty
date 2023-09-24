#include "main.h"
/**
 * _add - a function that adds an element to stack
 * @doubly: the pointer to the head ofa doubly linked list
 * @cline: dthe line number
 * Return: nothing
 */
void _add(stack_t **doubly, unsigned int cline)
{
	int k = 0;
	stack_t *aux = NULL;

	aux = *doubly;
	for (; aux != NULL; aux = aux->next, k++)
		;
	if (k < 2)
	{
		fprintf(stderr, "L%u: Can't add, stack too short\n", cline);
		freer();
		exit(EXIT_FAILURE);
	}
	aux = (*doubly)->next;
	aux->n += (*doubly)->n;
	_pop(doubly, cline);
}
/**
 * _push - a function that pushes an element to stack
 * @doubly: the pointer to the head ofa doubly linked list
 * @cline: dthe line number
 * Return: nothing
 */

void _push(__attribute__((unused)) stack_t **doubly, unsigned int cline)
{
	int n, j;

	if (!vg.arg)
	{
		fprintf(stderr, "L%u: ", cline);
		fprintf(stderr, "usage: push integer\n");
		freer();
		exit(EXIT_FAILURE);
	}

	for (j = 0; vg.arg[j] != '\0'; j++)
	{
		if (!isdigit(vg.arg[j]) && vg.arg[j] != '-')
		{
			fprintf(stderr, "L%u: ", cline);
			fprintf(stderr, "usage: push integer\n");
			freer();
			exit(EXIT_FAILURE);
		}
	}
	n = atoi(vg.arg);
	if (vg.lifo == 1)
		add_dnodeint(doubly, n);
	else
		add_dnodeint_end(doubly, n);
}
/**
 * _swap - a function that swaps the top two elements of the stack
 * @doubly: the head of the linked list
 * @cline: the line number
 * Return: nothing
 */
void _swap(stack_t **doubly, unsigned int cline)
{
	int m = 0;
	stack_t *aux = NULL;

	aux = *doubly;
	for (; aux != NULL; aux = aux->next, m++)
		;
	if (m < 2)
	{
		fprintf(stderr, "L%u: Can't swap, stack too short\n", cline);
		freer();
		exit(EXIT_FAILURE);
	}
	aux = *doubly;
	*doubly = (*doubly)->next;
	aux->next = (*doubly)->next;
	aux->prev = *doubly;
	(*doubly)->next = aux;
	(*doubly)->prev = NULL;
}
/**
 * _pall - a function that prints all values on the stack
 * @doubly: the head of the linked list
 * @cline: line numbers
 * Return: no return
 */
void _pall(stack_t **doubly, unsigned int cline)
{
	stack_t *aux;
	(void)cline;

	aux = *doubly;
	while (aux)
	{
		printf("%d\n", aux->n);
		aux = aux->next;
	}
}

/**
 * _pint - a function that prints the value at the top of the stack
 * @doubly: the head of a doubly linked list
 * @cline: the line number
 * Return: nothing
 */
void _pint(stack_t **doubly, unsigned int cline)
{
	(void)cline;

	if (*doubly == NULL)
	{
		fprintf(stderr, "L%u: ", cline);
		fprintf(stderr, "can't pint, stack empty\n");
		freer();
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*doubly)->n);
}
