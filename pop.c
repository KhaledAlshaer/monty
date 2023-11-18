#include "monty.h"

/**
 * pop- this is the function
 * @stack: this is a vraiable
 * @line_number: this is a vraiable
 * Return: Nothing.
*/

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		destroy_stack(stack);
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;
	free(temp);
}
