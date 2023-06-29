#include "test.h"

void puts2(char *str)
{
	int count = 0;

	while (count >= 0)
	{
		if (str[count] == '\0')
		{
			_putchar('\n');
			break;
		}
		else if (count % 2 == 0)
		{
			_putchar(str[count]);
		}
		count++;
	}
}