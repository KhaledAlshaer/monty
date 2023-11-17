#include "monty.h"

/**
 * _div- this is the function
 * @stack: this is a vraiable
 * @line_number: this is a vraiable
 * Return: Nothing
*/

void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		destroy_stack(stack);
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = temp->next;

	if (temp->n == 0)
	{
		destroy_stack(stack);
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->n /= temp->n;
	free(temp);
}
