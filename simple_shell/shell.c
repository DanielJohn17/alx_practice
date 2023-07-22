#include "shell.h"

int main(int ac __attribute__((unused)), char *av[])
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

	return (0);
}