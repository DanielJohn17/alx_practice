#include "test.h"

char *_strchr(char *s, char c)
{
	int count = 0;

	while (s[count] != '\0')
	{
		if (s[count] == c)
			return (s + count);
		count++;
	}
	if (s[count] == c)
	{
		return (s + count);
	}
}