#include "monty.h"
#include <stdio.h>

/**
 * main - main function that runs monty opcodes
 * @argc - the number of arguments supplied to the program
 * @argv - the string pointers to the arguments
 *
 * Return: 0 on success or -1 on error
 */

global_t vg;

int main(int argc, char **argv)
{
	void (*f)(stack_t **stack, unsigned int line_number);
	FILE *fd;
	size_t sz = 256;
	ssize_t nlns = 0;
	char *lns[2] = {NULL, NULL};

	vg.cnt = 1;
	vg.lifo = 1;
	vg.arg = NULL;
	vg.head = NULL;
	vg.buffer = NULL;
	if (argc == 1 || argc > 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(argv[1], "r");
	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	vg.fd = fd;
	nlns = getline(&vg.buffer, &sz, fd);
	while (nlns != -1)
	{
		lns[0] = strtok(vg.buffer, " \t\n");
		if (lns[0] && lns[0][0] != '#')
		{
			f = get_opcodes(lns[0]);
			if (!f)
			{
				fprintf(stderr, "L%i: ", vg.cnt);
				fprintf(stderr, "unknown instruction %s\n", lns[0]);
				freer();
				exit(EXIT_FAILURE);
			}
			vg.arg = strtok(NULL, " \t\n");
			f(&vg.head, vg.cnt);
		}
		nlns = getline(&vg.buffer, &sz, fd);
		vg.cnt++;
	}
	freer();
	return (0);
}
