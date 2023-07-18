#include "shell.h"

int main(int argc __attribute__((unused)), char **argv __attribute__((unused)), char **env)
{
	int i = 0;
	while (env[i])
	{
		printf("%s\n", env[i]);
		i++;
	}
	return 0;
}