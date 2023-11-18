#include "monty.h"

/**
 * pchar- printing the head value as char
 * @stack: this is a vraiable
 * @line_number: this is a vraiable
 * Return: Nothing.
*/

void pchar(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		destroy_stack(stack);
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n <= 127 && (*stack)->n >= 0)
	{
		putchar((*stack)->n);
		putchar('\n');
	}
	else
	{
		destroy_stack(stack);
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
}
