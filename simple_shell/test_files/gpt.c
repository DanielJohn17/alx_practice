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
	char *dlim = " \n";
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
			free(cmd), free(argv), exit(EXIT_SUCCESS);
		}
		argv = malloc(sizeof(char *) * 1024);
		token = strtok(cmd, dlim);

		while (token)
		{
			argv[argc] = token;
			argc++;
			token = strtok(NULL, dlim);
		}
		argv[argc] = NULL;
		if (argc > 0)
		{
			char *command = argv[0];
			char **argument = argv;
			pid = fork();

			if (pid == 0)
			{
				if (execve(command, argument, NULL) == -1)
				{
					perror(av[0]);
					exit(EXIT_FAILURE);
				}
			}
			else
				wait(&pid);
		}
		argc = 0;
		i = 0;
	}
	return (0);
}
