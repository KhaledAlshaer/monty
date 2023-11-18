#include "monty.h"

/**
 * push- pushing nodes
 * @stack: the stack header
 * @line_number: the current line index
 * Return: Nothing
*/

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	char *token = strtok(NULL, " \t\n");
	int val;

	if (!is_valid_num(token))
	{
		destroy_stack(stack);
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	val = atoi(token);

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		destroy_stack(stack);
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new->n = val;
	new->prev = NULL;
	new->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new;

	*stack = new;
}
