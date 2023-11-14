#include "shell.h"

/**
 * print_prompt - prints sh prompt to stdout
 */ 

void print_prompt()
{
  write(STDOUT_FILENO, input_prompt, strlen(input_prompt));
}
