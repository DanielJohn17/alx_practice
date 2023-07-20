#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>

void display_prompt()
{
	write(STDOUT_FILENO, "$ ", 2);
}

int main(int ac __attribute__((unused)), char *av[])
{
	char *token = NULL, *cmd = NULL, *cmd_cpy = NULL;
	char *dlim = "\n";
	int i = 0, j;

	int argc = 0;
	char **argv = NULL;

	size_t n = 0;
	pid_t pid;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			display_prompt();

		if (getline(&cmd, &n, stdin) == -1)
		{
			if (isatty(STDIN_FILENO))
				putchar('\n');
			free(argv), exit(EXIT_SUCCESS);
		}
		cmd_cpy = strdup(cmd);

		token = strtok(cmd, dlim);

		while (token)
		{
			argc++;
			token = strtok(NULL, dlim);
		}

		argv = malloc(sizeof(char *) * (argc + 1));
		token = strtok(cmd_cpy, dlim);

		while (token)
		{
			argv[i] = token;
			i++;
			token = strtok(NULL, dlim);
		}
		argv[i] = NULL;

		pid = fork();

		if (pid == 0)
		{
			if (execve(argv[0], argv, NULL) == -1)
			{
				perror(av[0]);
				exit(EXIT_FAILURE);
			}
		}
		else
			wait(&pid);

		i = 0;
	}
	free(cmd);
	return (0);
}
