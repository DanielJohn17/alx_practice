#include "test.h"

int _strcmp(char *s1, char *s2)
{
	int count = 0;
	int diff = 0;
	while (count == 0)
	{
		if ((s1[count] == '\0') && (s2[count] == '\0'))
			break;

		diff = s1[1] - s2[1];
		count++;
	}
	return (diff);
}