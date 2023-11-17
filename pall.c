#include "monty.h"

/**
 * pall- printing the stack
 * @stack: the stack header
 * @line_number: the current line index
*/

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr;
	(void)line_number;
	ptr = *stack;

	while (ptr)
	{
		fprintf(stdout, "%d\n", ptr->n);
		ptr = ptr->next;
	}
}
