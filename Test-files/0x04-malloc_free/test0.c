#include "test.h"

char *create_array(unsigned int size, char c)
{
	unsigned int i;
	char *cr;

	if (size == 0)
		return (NULL);

	cr = (char *)malloc(sizeof(c) * size);

	if (cr == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		cr[i] = c;
	return (cr);
}