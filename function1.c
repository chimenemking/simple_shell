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
