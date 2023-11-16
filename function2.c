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
 * @env: double pointer
 * Return: void
 */
void my_env(char **env)
{
	char **env_pr = env;

	while (*env_pr)
	{
		my_puts(*env_pr);
		env_pr++;
	}
}

/**
 * my_putchar - write character to stdout
 * @c: character to be written
 */

void my_putchar(char c)
{
	/* Write the character to stdup */
	write(1, &c, 1);
}

/**
 * my_puts - write string to stdout
 * @str: pointer to string
 */
void my_puts(const char *str)
{
  /* Write the string to standard outpu */
	while (*str)
	{
		my_putchar(*str);
		str++;
	}
	my_putchar('\n');
}
