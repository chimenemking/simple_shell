#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <limits.h>
#include <errno.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>

int main(int argc, char *argv[], char **env);
int wait_for_child_process(int pid);
void execute_command(char *command);
void read_command(char *buffer, size_t size);
void print_prompt(void);
char **split_cmd(const char *command);
int stng_cmp(char *sg1, char *sg2);
void builtin_exit(char *args, char **command, char *argv[],
	int linecount);
int str_to_lng(const char *str, long int *result);
int builtin_main(char *args, char *argv[], int linecount);
void my_env(char **env);
void free_space(char **code);

extern char **environment;

#define BUFFER_SIZE 1024
#endif /* my simple shell */
