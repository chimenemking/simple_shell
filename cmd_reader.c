#include "shell.h"

/**
 * read_command - command that reads command
 * @buffer: pointer to buffer
 * @size: size of the buffer
 */

void read_command(char *buffer, size_t size)
{
	/* Read the command line fr */
	ssize_t bytes_read;
	bytes_read = getline(&command_buffer, &buffer_size, stdin);

	/* check for errors */
	if (bytes_read == -1)
	{
		perror("Error (getline)");
		exit(EXIT_FAILURE);
	}
}
