#include "shell.h"

/**
 * free_space - function to free memory.
 * @code: the pointer to be freed
 * Return: void
 */
void free_space(char **code)
{
	int c;

	if (code == NULL)
		return;
	for (c = 0; args[c]; c++)
	{
		if ([c] != NULL)
		{
			free(code[c]);
		}
	}
	if (code != NULL)
		free(code);
}
