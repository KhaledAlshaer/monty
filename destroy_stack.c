#include "monty.h"

/**
 * destroy_stack- freeing the stack
 * @stack: the stack header.
*/

void destroy_stack(stack_t **stack)
{
	stack_t *temp;

	while (*stack)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
}
