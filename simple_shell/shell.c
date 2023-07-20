#include "shell.h"

int main(int ac __attribute__((unused)), char *av[])
{
	char *token = NULL, *cmd = NULL, *cmd_cpy = NULL;
	char *dlim = " \n";
	int i = 0;

	int argc = 0;
	char **argv = NULL;

	size_t n = 0;
	pid_t pid;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			prompt();
		if (getline(&cmd, &n, stdin) == -1)
		{
			if (isatty(STDIN_FILENO))
				_putchar('\n');
			free(argv), exit(EXIT_SUCCESS);
		}

		cmd_cpy = strdup(cmd);

		token = strtok(cmd, dlim);

		while (token)
		{
			token = strtok(NULL, dlim);
			argc++;
		}

		argv = malloc(sizeof(char *) * argc);
		token = strtok(cmd_cpy, dlim);

		while (token)
		{
			argv[i] = token;
			token = strtok(NULL, dlim);
			i++;
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