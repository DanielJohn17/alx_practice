#include "test.h"

char *string_toupper(char *s)
{
	int i = 0;

	while (i >= 0)
	{
		if (s[i] == '\0')
			break;
		else if ((s[i] >= 97) && (s[i] <= 122))
		{
			s[i] -= 32;
		}
		i++;
	}
	return (s);
}