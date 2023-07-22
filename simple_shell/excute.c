#include "shell.h"

void exec(int argc, char **nd, char **av)
{
	pid_t pid;
	char *command = nd[0];
	char **argument = nd;
	if (argc > 0)
	{
		pid = fork();
		if (pid == 0)
		{
			if (execve(command, argument, NULL) == -1)
			{
				perror(av[0]);
				exit(EXIT_FAILURE);
				free(nd);
			}
		}
		else
		{
			wait(&pid);
			free(nd);
		}
	}
}