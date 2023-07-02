#include "test.h"

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int count = 0;

	while (count <= n)
	{
		s[count] = b;
		count++;
	}
	return (s);
}
