#include "shell.h"

/**
 * exec - executing function
 * @argc: intiger input
 * @argument: command argument
 * @av: argument vector
 *
 * Return: 0 on success 1 if pid is 1 if pid is different from 0
 */
int exec(int argc, char **argument, char **av)
{
	pid_t pid;

	if (argc > 0)
	{
		pid = fork();
		if (pid == 0)
		{
			if (execve(argument[0], argument, environ) == -1)
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
			return (1);
		}
	}
	return (0);
}
