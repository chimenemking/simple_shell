#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>

int main(int argc, char *argv[], char **env);
void execute_command(char *command);
void read_command(char *buffer, size_t size);
void print_prompt(void);


extern char buffer[1024];
#endif /* my simple shell */
