#include "shell.h"

/**
 * builtin_main - to execute builtin commands
 * @args: for pointer to a string
 * @argv: contains program name
 * @linecount: shell line count
 * Return: 0.
 */

int builtin_main(char *args, char *argv[], int linecount)
{
	char **command;

	if (args != NULL)
	{
		command = split_cmd(args);

		if (stng_cmp(command[0], "exit") == 0)
		{
			builtin_exit(args, command, argv, linecount);
			return (0);
		}
		else if (stng_cmp(command[0], "envi") == 0)
		{
			free(args);
			free_space(command);
			my_env();
			return (0);
		}
		if (stng_cmp(command[0], "cd") == 0)
		{
			cd_builtin(argv, linecount, command);
			free(args);
			free_space(command);
			return (0);
		}
		free_space(command);
	}
	return (-1);
}

/**
 * builtin_exit - exits the action
 * @args: string input
 * @command: for array of strings
 * @argv: contains the program name
 * @linecount: tracks loop
 * Return void
 */
void builtin_exit(char *args, char **command, char *argv[], int linecount)
{
	long int status;

	if (command[1] != NULL)
	{
		status = atoi_custom(command[1]);
		if ((status < 0) | (status > INT_MAX))
		{
			error_msg(argv, linecount, command[0], "unsure no", command[1]);
			free(args);
			free_space(command);
			return;
		}
		free(args);
		free_space(command);
		exit(status);
	}
	else
	{
		free(args);
		free_space(command);
		exit(EXIT_SUCCESS);
	}
}

/**
 * str_to_lng - coverts string to lng i.
 * @str: string to be converted
 * @result: the result.
 * Return: 0.
 */
int str_to_lng(const char *str, long int *result)
{
	char *endptr;
	*result = strtol(str, &endptr, 10);

    /* Check for conversion errors */
	if (*endptr != '\0' || errno == ERANGE)
	{
		return (-1);
		/* Conversion error */
	}

	return (0);
	/* Successful conversion */
}
