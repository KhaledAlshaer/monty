#include "monty.h"

/**
 * main- the entry point.
 * @argc: the arguments count.
 * @argv: the arguments vector.
 * Return: 0 successful.
*/

int  main(int argc, char *argv[])
{
	FILE *file, *err_file;
	char line[256];
	unsigned int line_number = 1, size = 0;
	stack_t *head = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		file = fopen(argv[1], "r");
		if (file == NULL)
		{
			fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
			exit(EXIT_FAILURE);
		}
		else
		{
			while (fgets(line, sizeof(line), file) != NULL)
			{
				trim(line);
				if (line_proccessing(&head, line, line_number) == 0)
				{
					destroy_stack(&head);
					fclose(file);
					exit(EXIT_FAILURE);
				}
				line_number++;
			}
		}
		destroy_stack(&head);
		fclose(file);
	}
	return (0);
}
