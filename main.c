#include "shell.h"
int main(int argc, char *argv[], char **env);

/**
 * main - The main function that runs the shell.
 * @argc: no of cmd arguments
 * @argv: array of cmd line arguments
 * @env: environment
 * Return: 0.
 */
int main(int argc, char *argv[], char **env)
{
	char *command_buffer = NULL;
	char **args;
	int chd_pid;
	bool input_from_pipe = false;
	struct stat command_info;

	while (1 && !input_from_pipe)
	{
		if (!isatty(STDIN_FILENO))
		{
			input_from_pipe = true;
		}

		/* print my prompt here */
		print_prompt();

		/* Read the command line */
		read_command(command_buffer, BUFFER_SIZE);

		/* split the cmd line into tokens */
		args = split_cmd(command_buffer);

		if (stng_cmp(args[0], "exit") == 0)
		{
			free(command_buffer);
			free_space(args);
			exit(EXIT_SUCCESS);
		}

		if (stng_cmp(args[0], "env") == 0)
		{
			my_env(env);
			free(command_buffer);
			free_space(args);
			continue;
		}

		if (stat(args[0], &command_info) == -1)
		{
			perror("Error (stat)");
			fprintf(stderr, "Command not found: %s\n", args[0]);
			free(command_buffer);
			free_space(args);
			continue;
		}

		/* fork the process first after reading */
		chd_pid = fork();

		if (chd_pid == -1)
		{
			perror("Error (fork)");
			exit(EXIT_FAILURE);
		}

		/* you now execute the command in the child process */
		if (chd_pid == 0)
		{
			execute_command(command_buffer);
			exit(EXIT_SUCCESS);
		}

		/* wait for child to exit */
		wait_for_child_process(chd_pid);
	}
	/* Free up the command buffer */
	free(command_buffer);

	/* exit this programm */
	return (0);
}

/**
 * wait_for_child_process - wait for child
 * @pid: pid.
 * Return: wstatus.
 */

int wait_for_child_process(int pid)
{
	/* Wait for child process to exit,then get its status */
	int wstatus;
	int wait_result = waitpid(pid, &wstatus, 0);

	/* check process */
	if (wait_result == -1)
	{
		perror("Error (wait)");
		exit(EXIT_FAILURE);
	}

	return (wstatus);
}
