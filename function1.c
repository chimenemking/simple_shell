#include "shell.h"

/**
 * split_cmd - splits a command line into tokens
 * @command: command to split
 * Return: array of strings with tokens
 * of the command line.
 */

char **split_cmd(const char *command)
{
	char *args[10];
	int i = 0;
	char *token = strtok((char *)command, " ");

	while (token != NULL)
	{
		args[i] = token;
		i++;
		token = strtok(NULL, " ");
	}
	return (args);
}


/**
 * stng_cmp - function to compares two strings.
 *
 * @sg1: string 1.
 * @sg2: string 2.
 *
 * Return: int
 */
int stng_cmp(char *sg1, char *sg2)
{
	if (sg1 == NULL && sg2 == NULL)
		return (0);
	else if (sg1 == NULL || sg2 == NULL)
		return (1);

	while (*sg1 && *sg2)
	{
		if (*sg1 != *sg2)
		{
			return (1);
		}
		sg1++;
		sg2++;
	}
	return (*sg1 != *sg2);
}
