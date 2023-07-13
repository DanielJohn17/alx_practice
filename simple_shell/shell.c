#include "shell.h"

int main(void)
{
	char *token = NULL, *cmd = NULL, *cmd_cpy = NULL;
	char *dlim = " \n";
	int i = 0;

	int argc = 0;
	char **argv = NULL;

	ssize_t n = 0;

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

	i = 0;
	while (argv[i])
		printf("%s\n", argv[i++]);

	free(cmd), free(cmd_cpy), free(argv);

	return (0);
}