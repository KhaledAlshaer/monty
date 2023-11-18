#include "monty.h"

/**
 * line_proccessing- proccessing the line
 * @line: the line
 * @line_number: index of the line
 * @stack: the stack header
 * Return: Nothing.
*/

int line_proccessing(stack_t **stack, char *line, unsigned int line_number)
{
	char *token = strtok(line, " \t\n");
	int i = 0;
	instruction_t ops[] = {
		{"push", push}, {"pall", pall}, {"pint", pint},
		{"pop", pop}, {"nop", nop}, {"add", add}, {"swap", swap},
		{"sub", sub}, {"div", _div}, {"mul", mul}, {"mod", mod},
		{"pchar", pchar}, {"pstr", pstr}, {NULL, NULL}
	};

	if (token == NULL || *token == '\n')
	{
		fprintf(stderr, "L%u>: Line is empty\n", line_number);
		return (0);
	}
	else if (*token == '#' || token[0] == '#')
		return (1);

	while (ops[i].opcode && token)
	{
		if (strcmp(token, ops[i].opcode) == 0)
		{
			ops[i].f(stack, line_number);
			return (1);
		}
		i++;
	}

	if (ops[i].opcode == NULL && *token)
	{
		fprintf(stderr, "L%u>: unknown instruction %s\n", line_number, token);
		return (0);
	}

	return (1);
}
