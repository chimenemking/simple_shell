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


/**
 * my_env - function to print the curent environment
 * Return: void
 */
void my_env(void)
{
	char **env_pr = environment;

	while (*env_pr)
	{
		print_stdout(*env_pr);
		putchar_stdout('\n');
		env_pr++;
	}
}
