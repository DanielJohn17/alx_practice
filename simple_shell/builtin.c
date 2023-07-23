#include "shell.h"

int builtin(char *cmd)
{
	if (_strncmp(cmd, "exit", 4) == 0)
		return (errno);
}