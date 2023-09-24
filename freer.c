#include "main.h"

/**
 * free - a function that frees
 * Return: nothing
 */

void freer(void)
{
	free(vg.buffer);
	free_dlistint(vg.head);
	fclose(vg.fd);
}
