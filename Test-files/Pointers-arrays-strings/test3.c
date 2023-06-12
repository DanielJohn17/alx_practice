#include "test.h"

int _strlen(char *s)
{
	int i = 0;
	char *ch = s;

	while (*ch != '\0')
	{
		i += 1;
		ch++;
	}
	return (i);
}
