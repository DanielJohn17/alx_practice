#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>

#define LINE_DELIM " \n"
#define SIZE 1024

int _putchar(char c);
void prompt();
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _strncmp(char *str1, char *str2, int n);

int builtin(char *cmd);
void exec(int argc, char **argument, char **av);
void path_ls(char *cmd2, int ac, char **av);

#endif