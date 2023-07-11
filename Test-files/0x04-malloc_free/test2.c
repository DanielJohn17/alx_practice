#include "test.h"

char *str_concat(char *s1, char *s2)
{
	unsigned int i, j, k, limit;
	char *connect;

	if (s1 == NULL)
		return (NULL);
	if (s2 == NULL)
		return (NULL);

	for (i = 0; s1[i] != '\0'; i++)
		;

	for (j = 0; s2[j] != '\0'; j++)
		;

	connect = (char *)malloc(sizeof(char) * (i + j + 1));

	if (connect == NULL)
	{
		free(connect);
		return (NULL);
	}

	for (k = 0; k < i; k++)
		connect[k] = s1[k];

	limit = j;
	for (j = 0; j <= limit; k++, j++)
		connect[k] = s2[j];

	return (connect);
}