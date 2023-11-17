#include "monty.h"

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
