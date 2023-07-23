#include "shell.h"

void path_ls(char *cmd, int ac, char **av)
{
	pid_t pid;
	int argc = 0;
	char **argv2 = NULL, *token = NULL, *cmd2 = NULL;

	cmd2 = malloc(sizeof(char *) * (ac + 1));

	cmd2 = _strcpy(cmd2, "/bin/");
	cmd2 = _strcat(cmd2, cmd);

	argv2 = malloc(sizeof(char *) * SIZE);

	token = strtok(cmd2, LINE_DELIM);

	while (token)
	{
		argv2[argc] = token;
		argc++;
		token = strtok(NULL, LINE_DELIM);
	}
	argv2[argc] = NULL;

	exec(argc, argv2, av);

	free(cmd2);
}