#include "monty.h"

/**
 * pint- print the heading node value
 * @stack: the stack header
 * @line_number: the current line index
*/

void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		destroy_stack(stack);
		fprintf(stderr, "L%u>: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	fprintf(stdout, "%d\n", (*stack)->n);
}
