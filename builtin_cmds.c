#include "shell.h"

int builtin_main(char *args, char *argv[], int linecount)
{
	char **command;

	if (args != NULL)
	{
		command = split_command(args);

		if (str_cmp(command[0], "exit") == 0)
		{
			exit_builtin(args, command, argv, linecount);
			return (0);
		}
		else if (str_cmp(command[0], "env") == 0)
		{
			free(args);
			free_mem(command);
			get_env();
			return (0);
		}
		if (str_cmp(command[0], "cd") == 0)
		{
			cd_builtin(argv, linecount, command);
			free(args);
			free_mem(command);
			return (0);
		}
		free_mem(command);
	}
	return (-1);
}

/**
 * exit_builtin - exit implementation
 * @args: string input
 * @command: array of strings
 * @argv: contains program name
 * @linecount: tracks loop
 * Return void
 */
void exit_builtin(char *args, char **command, char *argv[], int linecount)
{
	long int status;

	if (command[1] != NULL)
	{
		status = atoi_custom(command[1]);
		if (status < 0 || status > INT_MAX)
		{
			error_msg(argv, linecount, command[0], "unsure no", command[1]);
			free(args);
			free_mem(command);
			return;
		}
		free(args);
		free_mem(command);
		exit(status);
	}
	else
	{
		free(args);
		free_mem(command);
		exit(EXIT_SUCCESS);
	}
}


int str_to_lng(const char *str, long int *result)
{
	char *endptr;
	*result = strtol(str, &endptr, 10);

    /* Check for conversion errors */
	if (*endptr != '\0' || errno == ERANGE)
	{
		return (-1);  /* Conversion error */
	}

	return (0);  /* Successful conversion */
}
