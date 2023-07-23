#include "shell.h"

void exec(int argc, char **argument, char **av)
{
	pid_t pid;

	if (argc > 0)
	{
		pid = fork();
		if (pid == 0)
		{
			if (execve(argument[0], argument, NULL) == -1)
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