#include "monty.h"

/**
 * swap- swaping values of two nodes
 * @stack: the stack header
 * @line_number: the line index
 * Return: Nothing
*/

void swap(stack_t **stack, unsigned int line_number)
{
	int n;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		destroy_stack(stack);
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	n = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = n;
}
