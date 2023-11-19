#include "monty.h"

/**
 * push- pushing nodes.
 * @stack: the stack header.
 * @line_number: the current line index
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

/**
 * pint- print the heading node value
 * @stack: the stack header
 * @line_number: the current line index
*/

void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		destroy_stack(stack);
		fprintf(stderr, "L%u>: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	fprintf(stdout, "%d\n", (*stack)->n);
}

/**
 * destroy_stack- freeing the stack
 * @stack: the stack header
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
