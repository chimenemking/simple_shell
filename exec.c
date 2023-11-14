#include "shell.h"

/**
 * execute_command - execute the shell cmds
 * @command: command pointer
 */
void execute_command(char *command)
{
  /* Use execve() to execute the command */
  if (execve(command, args, NULL) == -1)
  {
    perror("Error (executing command)");
    exit(EXIT_FAILURE);
  }
}
