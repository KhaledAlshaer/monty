#include "monty.h"

/**
 *add - this is the function
 *@stack: this is a vraiable
 *@line_number: this is a vraiable
 *Return: return 0
*/
void add(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		destroy_stack(stack);
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->n += (*stack)->next->n;
	pop(stack, line_number);
}
