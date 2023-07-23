#include "shell.h"

int main(int ac, char *av[])
{
	char *cmd = NULL, *token = NULL;

	int argc = 0;
	char **argv = NULL;

	size_t n = 0;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			prompt();
		if (getline(&cmd, &n, stdin) == -1)
		{
			if (isatty(STDIN_FILENO))
				_putchar('\n');
			free(cmd), exit(EXIT_SUCCESS);
		}
		if (builtin(cmd) == 0)
			free(cmd), exit(EXIT_SUCCESS);
		if (ac > 0 && _strncmp(cmd, "/bin/", 5) == 0)
		{
			argv = malloc(sizeof(char *) * SIZE);

			token = strtok(cmd, LINE_DELIM);

			while (token)
			{
				argv[argc] = token;
				argc++;
				token = strtok(NULL, LINE_DELIM);
			}
			argv[argc] = NULL;
			exec(argc, argv, av);
			argc = 0;
		}
		else if (ac > 0 && _strncmp(cmd, "/bin/", 5) != 0)
		{
			path_ls(cmd, ac, av);
		}
	}
	return (0);
}
