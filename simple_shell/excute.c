#include "shell.h"

void exec(int argc, char **argument, char **av)
{
	pid_t pid;
	char *command = argument[0];
	if (argc > 0)
	{
		pid = fork();
		if (pid == 0)
		{
			if (execve(command, argument, NULL) == -1)
			{
				perror(av[0]);
				exit(EXIT_FAILURE);
				free(argument);
			}
		}
		else
		{
			wait(&pid);
			free(argument);
		}
	}
}