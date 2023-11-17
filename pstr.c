#include "monty.h"

/**
 * pstr- printing the head value as char
 * @stack: this is a vraiable
 * @line_number: this is a vraiable
 * Return: Nothing
*/

void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	(void)line_number;

	if (*stack == NULL)
	{
		putchar('\n');
		return;
	}

	temp = *stack;

	while (temp)
	{
		if (temp->n > 127 || temp->n < 0)
		{
			destroy_stack(stack);
			exit(1);
		}
		else
			putchar(temp->n);

		temp = temp->next;
	}

	putchar('\n');
}
