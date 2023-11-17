#include "monty.h"

/**
 * is_valid_num - check weather the token is valid
 * @token: the token
 * Return: 1 Valid, 0 Not Valid
*/

int is_valid_num(char *token)
{
	size_t i;

	if (token == NULL || *token == '\0')
		return (0);

	for (i = 0; i < strlen(token); i++)
	{
		if (!isdigit(token[i]))
			return (0);
	}

	return (1);
}
