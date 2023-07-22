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

int _putchar(char c);
void prompt();

void exec(int argc, char **nd, char **av);

#endif