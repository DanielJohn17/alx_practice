#include "shell.h"

int main(void)
{
	char *token = NULL, *cmd = NULL, *cmd_cpy = NULL;
	char *dlim = " \n";
	int i = 0;

	int argc = 0, stat;
	char **argv = NULL;

	ssize_t n = 0;
	pid_t pid;
	while (1)
	{

		printf("$ ");
		if (getline(&cmd, &n, stdin) == -1)
			return (-1);

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
				perror("execve");
		}
		else
			wait(&stat);

		i = 0;
		free(cmd), free(cmd_cpy), free(argv);
	}
	return (0);
}