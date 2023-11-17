#include "monty.h"

/**
 * pall- printing the stack
 * @stack: the stack header
 * @line_number: the current line index
*/

void pall(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	while (*stack)
	{
		fprintf(stdout, "%d\n", (*stack)->n);
		(*stack) = (*stack)->next;
	}
}
