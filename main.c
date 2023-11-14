#include "shell.h"

/**
 * main - The main function that runs the shell.
 */
int main(int argc, char *argv[], char **env)
{

	char *command_buffer = NULL;
	char *input_prompt = "$ ";
	ssize_t bytes_read;
	int child_pid;
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
		wait_for_child_process(child_pid);
	}
	/* Free up the command buffer */
	free(command_buffer);

	/* Exit this program */
	return (0);
}

void print_prompt()
{
  write(STDOUT_FILENO, input_prompt, strlen(input_prompt));
}

void read_command(char *buffer, size_t size)
{
  /* Read the commd line fr */
  bytes_read = getline(&command_buffer, &buffer_size, stdin);

  /* check for errors here */
  if (bytes_read == -1)
  {
	  perror("Error (getline)");
	  exit(EXIT_FAILURE);
  }
}

void execute_command(char *command)
{
	/* Use execve() to execute the command */
	if (execve(command, command, NULL) == -1)
	{
		perror("Error (executing command)");
		exit(EXIT_FAILURE);
	}
}

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

	return wstatus;
}
