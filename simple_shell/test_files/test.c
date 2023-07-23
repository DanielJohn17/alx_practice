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

int main(int ac, char *av[])
{
	char *token = NULL, *cmd = NULL, *cmd2 = NULL;
	char *dlim = " \n";
	int i = 0, j;

	int argc = 0;
	char **argv = NULL, **argv2 = NULL;

	size_t n = 0, len;
	pid_t pid;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			display_prompt();

		if (getline(&cmd, &n, stdin) == -1)
		{
			if (isatty(STDIN_FILENO))
				putchar('\n');
			free(argv), free(cmd), exit(EXIT_SUCCESS);
		}

		if (strncmp(cmd, "/bin/", 5) == 0)
		{
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
			}
		}
		else if (strncmp(cmd, "/bin/", 5) != 0)
		{
			cmd2 = malloc(sizeof(char *) * (ac + 1));

			cmd2 = strcpy(cmd2, "/bin/");
			cmd2 = strcat(cmd2, cmd);

			argv2 = malloc(sizeof(char *) * 1024);

			token = strtok(cmd2, dlim);

			while (token)
			{
				argv2[argc] = token;
				argc++;
				token = strtok(NULL, dlim);
			}
			argv2[argc] = NULL;
			pid = fork();
			if (pid == 0)
			{
				if (execve(argv2[0], argv2, NULL) == -1)
				{
					perror(av[0]);
					exit(EXIT_FAILURE);
				}
			}
			else
				wait(&pid);
			free(argv2);
			free(cmd2);
		}
		argc = 0;
	}
	return (0);
}
