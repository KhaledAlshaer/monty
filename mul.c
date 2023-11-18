#include "monty.h"

/**
 * mul- this is the function
 * @stack: this is a vraiable
 * @line_number: this is a vraiable
 * Return: Nothing.
*/

void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		destroy_stack(stack);
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = temp->next;
	(*stack)->n *= temp->n;
	free(temp);
}
