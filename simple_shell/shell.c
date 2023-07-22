#include "shell.h"

int main(int ac __attribute__((unused)), char *av[])
{
	char *token = NULL, *cmd = NULL, *cmd_cpy = NULL;
	char *dlim = " \n";
	int i = 0;

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

		cmd_cpy = strdup(cmd);

		token = strtok(cmd, LINE_DELIM);

		while (token)
		{
			token = strtok(NULL, LINE_DELIM);
			argc++;
		}

		argv = malloc(sizeof(char *) * (argc + 1));
		token = strtok(cmd_cpy, LINE_DELIM);

		while (token)
		{
			argv[i] = token;
			token = strtok(NULL, LINE_DELIM);
			i++;
		}
		argv[i] = NULL;
		exec(argc, argv, av);

		argc = 0;
		i = 0;
	}

	return (0);
}