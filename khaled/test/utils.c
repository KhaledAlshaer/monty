#include "monty.h"

/**
 * line_proccessing- proccessing the line
 * @line: the line
 * @line_number: index of the line
 * @stack: the stack header
 * Return: Nothing
*/

int line_proccessing(stack_t **stack, char *line, unsigned int line_number)
{
	char *token = strtok(line, " \t\n");

	if (token == NULL || *token == '\n')
	{
		fprintf(stderr, "L%u>: Line is empty\n", line_number);
		return (0);
	}

	if (strcmp(token, "push") == 0)
		push(stack, line_number);
	else if (strcmp(token, "pall") == 0)
		pall(stack, line_number);
	else if (strcmp(token, "pint") == 0)
		pint(stack, line_number);
	else
	{
		fprintf(stderr, "L%u>: unknown instruction %s\n", line_number, token);
		return (0);
	}

	return (1);
}

/**
 * is_valid_token: check weather the token is valid
 * @token: the token
 * Return: 1 Valid, 0 Not Valid
*/

int is_valid_num(char *token)
{
	size_t i;

	if (token == NULL || *token == '\0')
		return 0;

	for (i = 0; i < strlen(token); i++) {
		if (!isdigit(token[i]))
			return (0);
	}

	return (1);
}

/**
 * trim- removing the leading and ending spaces
 * @str: the string
 * Return: Nothing
*/

void trim(char *str)
{
	char *start = str;
	char *back = str + strlen(str) - 1;

	while (isspace(*str))
	{
		str++;
	}

	if (*start == '\0')
	{
		*str = '\0';
		return;
	}

	while (back > start && isspace(*back))
	{
		back--;
	}

	*(back + 1) = '\0';

	if (start != str)
		memmove(str, start, strlen(start) + 1);
}
